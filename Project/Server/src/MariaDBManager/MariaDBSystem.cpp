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

int MariaDBSystem::Init()
{
		db = "game";
		ip = "127.0.0.1";
		user = "root";
		password = "123456";
		InitMariaDBThread();
		ConnectMariadb();
}

int MariaDBSystem::ConnectMariadb()
{
	connection = mysql_init(NULL);
	my_bool mb=1;
	mysql_options(connection,MYSQL_OPT_RECONNECT,&mb);
	connection = mysql_real_connect(connection, ip.c_str(), user.c_str(),password.c_str(), NULL, 0, NULL, 0);
	//mysql_options(connection,MYSQL_OPT_RECONNECT,0);
	if (connection == NULL)
	{
		cerr << "mysql connection Error: MYSQL* is NULL" << endl;
		return -1;
	}
	string sqlcommand = "use " + db;
	ExcuteSqlCommand(sqlcommand);
	cout << "Connect DataBase: " << db << endl;

	SetThreadState(false);
	InitTrhead(this);
	cout<<"mysql Thread Init Finish"<<endl;
	return 0;
}

int MariaDBSystem::InitMariaDBThread()
{
	if(pthread_rwlock_init(&m_mutex_ping_t,NULL)==-1)
	{
		cout<<"MYSQL ping Lock  Init Error"<<endl;
	}
	if(pthread_rwlock_init(&m_mutex_TrheadState_t,NULL)==-1)
	{
		cout<<"ThreadState Lock Init Error"<<endl;
	}
}

void MariaDBSystem::Check_Ping()
{
	pthread_rwlock_wrlock(&m_mutex_ping_t); 
	int result=mysql_ping(connection);
	pthread_rwlock_unlock(&m_mutex_ping_t); 
	if(result!=0)
	{
		cout<<"Check mysql Connection State : false: "<<result<<endl;
	}else
	{
		cout<<"Check mysql Connection State : true"<<endl;
	}
}

bool MariaDBSystem::GetThreadState()
{
	bool state=orCancelThread;
	return state;
}
void MariaDBSystem::SetThreadState(bool state)
{
	pthread_rwlock_wrlock(&m_mutex_TrheadState_t); 
	orCancelThread=state;
	pthread_rwlock_unlock(&m_mutex_TrheadState_t); 
}

int MariaDBSystem::CloseMariaDb()
{
	SetThreadState(true);
	mysql_close(connection);
	return 0;
}

MYSQL_RES* MariaDBSystem::GetQueryResultCollection()
{
	pthread_rwlock_wrlock(&m_mutex_ping_t); 
	MYSQL_RES* res = mysql_use_result(connection);
	pthread_rwlock_unlock(&m_mutex_ping_t); 
	return res;
}
int MariaDBSystem::ExcuteSqlCommand(string command)
{
	cout << "sql command:" << command << endl;
	pthread_rwlock_wrlock(&m_mutex_ping_t); 
	int result = mysql_query(connection, command.c_str());
	pthread_rwlock_unlock(&m_mutex_ping_t); 
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
	MYSQL_RES* res=GetQueryResultCollection();
	MYSQL_ROW row;
	//cout << "mysql num fields: " << mysql_num_fields(res) << endl;
	cout << "field count: " << res->field_count << endl;
	//cout << "row count: " << res->row_count << endl;
	//cout << "res Length " << *res->lengths << endl;
	if (res)
	{
		while (true)
		{
			row = mysql_fetch_row(res);
			if (row != NULL)
			{
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
	mysql_free_result(res);
}

string MariaDBSystem::getSinglefield(string command)
{
		string value="";
		ExcuteSqlCommand(command);
		MYSQL_RES* res=GetQueryResultCollection();
		MYSQL_ROW row;
		if (res)
		{
			int i=0;
			while (true)
			{
				row = mysql_fetch_row(res);
				if (row != NULL)
				{
					value=row[0];
					cout<<"field value"<<value<<endl;
					break;
				}
				else
				{
					cout<<"["<<i<<"]is NULL"<<endl;
					break;
				}
				i++;
			}
		}
		mysql_free_result(res);
		return value;
}

vector<string> MariaDBSystem::getMultiplefield(string command)
{
		vector<string> result;
		ExcuteSqlCommand(command);
		MYSQL_RES* res=GetQueryResultCollection();
		MYSQL_ROW row;
		if (res)
		{
			int i=0;
			while (true)
			{
				row = mysql_fetch_row(res);
				if (row != NULL)
				{
					for(int j=0;j<res->field_count;j++)
					{
						char* value=row[j];
						cout<<"Multiplefield value"<<value<<endl;
						result.push_back(value);
					}
					break;
				}
				else
				{
					cout<<i<<"is NULL"<<endl;
					break;
				}
				i++;
			}
		}
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
