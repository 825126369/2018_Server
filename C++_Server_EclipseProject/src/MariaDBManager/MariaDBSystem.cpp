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
	db = "test";
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

	string sqlcommand = "drop database if exists " + db;
	ExcuteSqlCommand(sqlcommand);
	sqlcommand = "create database " + db;
	ExcuteSqlCommand(sqlcommand);
	sqlcommand = "use " + db;
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
	int EffectRows = mysql_query(connection, command.c_str());
	//cout << "影响的行数:" << EffectRows << endl;
	if (EffectRows == 1)
	{
		cerr << "sql Error:" << mysql_error(connection) << endl;
		return -1;
	}
	return 0;
}

int MariaDBSystem::ExcuteSqlSelectCommand(string command)
{
	cout << "sql command:" << command << endl;
	int EffectRows = mysql_query(connection, command.c_str());
	//cout << "影响的行数:" << EffectRows << endl;
	if (EffectRows == 1)
	{
		cerr << "sql Error:" << mysql_error(connection) << endl;
		return -1;
	}
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

DbTableBase::DbTableBase()
{

}

DbTableBase:: ~DbTableBase()
{

}

int DbTableBase::set_field_value(string fieldname,string value)
{
	string sqlcommand="update "+tablename+" set "+fieldname+"='"+value+"' where premakkey=10; ";
	int result=MariaDBSystem::getSingle()->ExcuteSqlCommand(sqlcommand);
	return result;
}

string DbTableBase::get_field_value(string fieldname)
{
	string sqlcommand="select fieldname from "+tablename+" where id="+primarykey;
	MariaDBSystem::getSingle()->ExcuteSqlCommand(sqlcommand);
	string result="";
	return result;
}

/*template<typename in_type, typename out_type>
out_type DbTableBase::convert(const in_type t)
{
	static stringstream stream;
	stream << t; //向流中传值
	out_type result; //这里存储转换结果
	stream >> result; //向result中写入值
	stream.clear();
	return result;
}*/

} /* namespace basic */
