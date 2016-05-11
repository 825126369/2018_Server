/*
 * MariaDBSystem.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: xuke
 */

#include "MariaDBSystem.h"

namespace basic
{
MariaDBSystem* MariaDBSystem::single=new MariaDBSystem;
MariaDBSystem::MariaDBSystem()
{
	db = "game";
	ip = "127.0.0.1";
	user = "root";
	password = "123";
}

MariaDBSystem::~MariaDBSystem()
{
	// TODO Auto-generated destructor stub
}
MariaDBSystem* MariaDBSystem::getSingle()
{
	if (single == NULL)
	{
		single = new MariaDBSystem();
	}
	return single;



}

int MariaDBSystem::ConnectMariadb()
{
	connection = mysql_init(NULL);
	connection = mysql_real_connect(connection, ip.c_str(), user.c_str(),
			password.c_str(), NULL, 0, NULL, 0);
	if (connection == NULL)
	{
		cerr << "mysql connection Error: MYSQL* is NULL" << endl;
		return -1;
	}
	string sqlcommand = "use " + db;
	ExcuteSqlCommand(sqlcommand);
	cout << "连接数据库:" << db << endl;
	return 0;
}

int MariaDBSystem::CloseMariaDb()
{
	mysql_close(connection);
	return 0;
}

int MariaDBSystem::ExcuteSqlCommand(string command)
{
	cout << "sql command:" << command << endl;
	int result = mysql_query(connection, command.c_str());
	cout<<"Effect Rows: "<<mysql_affected_rows(connection)<<endl;
	if (result == 0)
	{
		//cout<<"Effect Rows: "<<mysql_affected_rows(connection)<<endl;
	}else
	{
		cerr << "sql Error:" << mysql_error(connection) << endl;
		return -1;
	}
	return 0;
}

int MariaDBSystem::GetResultCollection(string command)
{
	ExcuteSqlCommand(command);
	MYSQL_RES* res = mysql_use_result(connection);
	MYSQL_ROW row;
	//cout << "字段数： " << mysql_num_fields(res) << endl;
	cout << "字段数： " << res->field_count << endl;
	//cout << "字段数： " << res->row_count << endl;
	//cout << "字段数： " << *res->lengths << endl;
	//MYSQL_ROW mRow= res->
	if (res)
	{
		while (true)
		{
			//检索一个结果集合的下一行
			row = mysql_fetch_row(res);
			if (row != NULL)
			{
				//mysql_num_fields(res)  函数返回结果集中字段的数
				for (int r = 0; r < mysql_num_fields(res); r++)
				{
					cout << "\t" << row[r] << endl;
				}
				cout << "\n" << endl;
			}
			else
			{
				break;
			}
		}

	}
	//释放结果集使用的内存
	mysql_free_result(res);
}

string MariaDBSystem::getSinglefield(string command)
{
		string value="";
		ExcuteSqlCommand(command);
		MYSQL_RES* res = mysql_use_result(connection);
		MYSQL_ROW row;
		if (res)
		{
			int i=0;
			while (true)
			{
				//检索一个结果集合的下一行
				row = mysql_fetch_row(res);
				if (row != NULL)
				{
					value=row[0];
					cout<<"Singlefield:数据库数据："<<value<<endl;
					break;
				}
				else
				{
					cout<<"扫描第["<<i<<"]行 is NULL"<<endl;
					break;
				}
				i++;
			}
		}
		//释放结果集使用的内存
		mysql_free_result(res);
		return value;
}

vector<string> MariaDBSystem::getMultiplefield(string command)
{
		vector<string> result;
		ExcuteSqlCommand(command);
		MYSQL_RES* res = mysql_use_result(connection);
		MYSQL_ROW row;
		if (res)
		{
			int i=0;
			while (true)
			{
				//检索一个结果集合的下一行
				row = mysql_fetch_row(res);
				if (row != NULL)
				{
					for(int j=0;j<res->field_count;j++)
					{
						char* value=row[j];
						cout<<"Multiplefield:数据库数据："<<value<<endl;
						result.push_back(value);
					}
					break;
				}
				else
				{
					cout<<"扫描第["<<i<<"]行 is NULL"<<endl;
					break;
				}
				i++;
			}
		}
		//释放结果集使用的内存
		mysql_free_result(res);
		return result;
}
DbTableBase::DbTableBase()
{

}

DbTableBase:: ~DbTableBase()
{

}
int  DbTableBase::set_all_value(vector<string> fieldlist)
{
	string tablename=get_tablename_value();
	string keyname=get_primarykeyname_value();
	string keyvalue=primarykeyvalue;
	string sqlcommand="update "+tablename+" ";
	for(int i=0;i<fieldlist.size();i+=2)
	{
		sqlcommand+="set "+fieldlist[i]+"='"+fieldlist[i+1]+"' ";
	}
	sqlcommand+="where "+keyname+"='"+keyvalue+"';";
	MariaDBSystem::getSingle()->ExcuteSqlCommand(sqlcommand);
}

vector<string>  DbTableBase::get_all_value(vector<string> fieldlist)
{
		vector<string> result;
		string tablename=get_tablename_value();
		string keyname=get_primarykeyname_value();
		string keyvalue=primarykeyvalue;
		string sqlcommand="select ";
		for(int i=0;i<fieldlist.size();i++)
		{
			sqlcommand+=fieldlist[i]+",";
		}
		sqlcommand.erase(sqlcommand.end()-1);
		sqlcommand+=" from "+tablename+" where "+keyname+"='"+keyvalue+"';";
		result= MariaDBSystem::getSingle()->getMultiplefield(sqlcommand);

		return result;
}

int DbTableBase::CreatePrimaryKey(string fieldname,string value)
{
	string tablename=get_tablename_value();
	string keyname=get_primarykeyname_value();
	string keyvalue=value;
	string sqlcommand="insert into "+tablename+" set "+keyname+"='"+keyvalue+"';";
	MariaDBSystem::getSingle()->ExcuteSqlCommand(sqlcommand);
	return 0;
}


int DbTableBase::set_field_value(string fieldname,string value)
{
	string tablename=get_tablename_value();
	string keyname=get_primarykeyname_value();
	string keyvalue=primarykeyvalue;
	string sqlcommand="update "+tablename+" set "+fieldname+"='"+value+"' where "+keyname+"='"+keyvalue+"';";
	MariaDBSystem::getSingle()->ExcuteSqlCommand(sqlcommand);
	return 0;
}

string DbTableBase::get_field_value(string fieldname)
{
	string result="";
	string tablename=get_tablename_value();
	string keyname=get_primarykeyname_value();
	string keyvalue=primarykeyvalue;
	string sqlcommand="select "+fieldname+" from "+tablename+" where "+keyname+"='"+keyvalue+"';";
	result= MariaDBSystem::getSingle()->getSinglefield(sqlcommand);
	return result;
}


} /* namespace basic */
