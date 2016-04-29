//============================================================================
// Name        : MariaDbToCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <mysql.h>
#include <vector>
#include <cstdlib>
using namespace std;

int ConnectMariadb();
int ReSolveTableInfo();
string ChangeFieldType(enum_field_types value);
class TableInfo
{
public:
	static string db;
	string table;
	vector<string> datanameList;
	vector<string> datatypeList;
};
int GenerateCpp(vector<TableInfo> mClassInfoList);
void Help();
void PrintConnectionInfo();
MYSQL* connection;
string db = "game";
string ip = "127.0.0.1";
string user = "root";
string password = "123";
string TableInfo::db = db;
string hname = "DbTable.h";
string cppname = "DbTable.cpp";
string hbasename="DbTableBase";

int main(int length, char** msg)
{
	if (length < 5)
	{
		Help();
		//exit(1);
	}
	else
	{
		ip = msg[1];
		user = msg[2];
		password = msg[3];
		db = msg[4];
	}
	PrintConnectionInfo();
	ConnectMariadb();
	mysql_close(connection);
	cout << "Finish MariaDB To CPP000000" << endl;
	cout << "Finish MariaDB To CPP1111111111111" << endl;
	return 0;
}
void Help()
{
	cout << "Help:" << endl;
	cout << "参数1 ：数据库服务器的IP地址" << endl;
	cout << "参数2 ：用户名" << endl;
	cout << "参数3 ：用户密码" << endl;
	cout << "参数4 ：数据库名" << endl;
}
void PrintConnectionInfo()
{
	cout << "数据库服务器的IP地址: " << ip << endl;
	cout << "用户名: " << user << endl;
	cout << "用户密码: " << password << endl;
	cout << "数据库名: " << db << endl;
}

int ConnectMariadb()
{
	connection = mysql_init(NULL);
	connection = mysql_real_connect(connection, ip.c_str(), user.c_str(),
			password.c_str(), NULL, 0, NULL, 0);
	if (connection == NULL)
	{
		cerr << "mysql connection Error: MYSQL* is NULL" << endl;
		exit(1);
	}
	string sqlcommand = "use " + db;

	int aaa=mysql_query(connection,sqlcommand.c_str());
	cout << "连接数据库:" << db << endl;
	//sqlcommand = "select * from config_Sheet2DB";
	//ExcuteSqlSelectCommand(sqlcommand);
	ReSolveTableInfo();
	return 0;
}
//检索所有表结构信息
int ReSolveTableInfo()
{
	string command = "show tables";
	cout << "sql command:" << command << endl;
	int EffectRows = mysql_query(connection, command.c_str());
	cout << "影响的行数:" << EffectRows << endl;
	if (EffectRows == 1)
	{
		cerr << "sql Error:" << mysql_error(connection) << endl;
		exit(1);
	}
	MYSQL_RES* res = mysql_store_result(connection);
	if (res)
	{
		vector<TableInfo> mClassInfoList;
		while (true)
		{
			MYSQL_ROW row = mysql_fetch_row(res);
			if (row != NULL)
			{
				//mysql_num_fields(res)  函数返回结果集中字段的数
				for (int r = 0; r < mysql_num_fields(res); r++)
				{
					TableInfo mTableInfo;
					string str = row[r];
					cout << "表名： " << str << endl;
					mTableInfo.table = str;
					string sqlcommand = "select * from " + str;
					cout << "sql command:" << sqlcommand << endl;
					int EffectRows = mysql_query(connection,
							sqlcommand.c_str());
					cout << "影响的行数:" << EffectRows << endl;
					if (EffectRows == 1)
					{
						cerr << "sql Error:" << mysql_error(connection) << endl;
						exit(1);
					}
					MYSQL_RES* res1 = mysql_store_result(connection);
					if (res1)
					{
						while (true)
						{
							MYSQL_FIELD * mArray0 = mysql_fetch_field(res1);
							if (mArray0 != NULL)
							{
								cout << mArray0->name << endl;
								cout << mArray0->type << endl;
								mTableInfo.datanameList.push_back(
										mArray0->name);
								mTableInfo.datatypeList.push_back(
										ChangeFieldType(mArray0->type));
							}
							else
							{
								break;
							}
						}
					}
					mClassInfoList.push_back(mTableInfo);
					cout<<"增加："<<mClassInfoList.size()<<endl;
					cout<<"增加："<<mClassInfoList.capacity()<<endl;
				}
				GenerateCpp(mClassInfoList);
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

string ChangeFieldNameType(string value)
{

}

string ChangeFieldType(enum_field_types value)
{
	string str = "";
	switch (value)
	{
	case MYSQL_TYPE_LONG:
		str = "int";
		break;
	case MYSQL_TYPE_VAR_STRING:
		str = "string";
		break;
	default:
		cerr << "转换字段【类型】:" << value << "出错" << endl;
		break;
	}
	return str;
}

int GenerateCpp(vector<TableInfo> mClassInfoList)
{
	if (mClassInfoList.size() > 0)
	{
		cout<<"数量："<<mClassInfoList.size()<<endl;
		string dbname = TableInfo::db;
		ofstream mfile;

		//生成.h文件
		mfile.open(hname.c_str(), ios_base::out | ios_base::trunc);
		string mClassStr = "";
		mClassStr +=
				"#ifndef SRC_MARIADBMANAGER_DBTABLE_H\n#define SRC_MARIADBMANAGER_DBTABLE_H\n";
		mClassStr += "#include <string>\n#include \"MariaDBSystem.h\"\n";
		mClassStr += "namespace basic{\n";

		for (vector<TableInfo>::iterator iter = mClassInfoList.begin();iter < mClassInfoList.end(); iter++)
		{
			string classname = (*iter).table;
			vector<string> nameList = (*iter).datanameList;
			vector<string> typeList = (*iter).datatypeList;
			int Length = nameList.size();
			mClassStr += "class " + classname + ":"+hbasename+"\n{\npublic:\n";
			for (int i = 0; i < Length; i++)
			{
				string name = nameList[i];
				string type = typeList[i];
				mClassStr += "\tint set_" + name + "_value(" + type
						+ " value);\n";
				mClassStr += "\t" + type + " get_" + name + "_value();\n";
			}
			mClassStr += "private:\n";
			for (int i = 0; i < Length; i++)
			{
				string name = nameList[i];
				string type = typeList[i];
				mClassStr += "\t" + type + " " + name + ";\n";
			}
			mClassStr += "};\n";
		}
		mClassStr += "}\n";
		mClassStr += "#endif";
		mfile << mClassStr << endl;
		mfile.close();

		//生成CPP
		mfile.open(cppname.c_str(), ios_base::out | ios_base::trunc);
		mClassStr = "";
		mClassStr += "#include \"" + hname + "\"\n";
		mClassStr += "namespace basic{\n";
		for (vector<TableInfo>::iterator iter = mClassInfoList.begin();
				iter < mClassInfoList.end(); iter++)
		{
			string classname = (*iter).table;
			vector<string> nameList = (*iter).datanameList;
			vector<string> typeList = (*iter).datatypeList;
			int Length = nameList.size();
			for (int i = 0; i < Length; i++)
			{
				string name = nameList[i];
				string type = typeList[i];
				if (type == "string")
				{
					mClassStr += "int " + classname + "::set_" + name
							+ "_value(" + type + " value)\n{\n";
					mClassStr += "\tset_field_value(\"" + name + "\",value);\n";
					mClassStr += "\treturn 0;\n";
					mClassStr += "}\n";

					mClassStr += type + " " + classname + "::get_" + name
							+ "_value()\n{\n";
					mClassStr += "\tstring str=get_field_value(\"" + name
							+ "\");\n";
					mClassStr += "\treturn str;\n";
					mClassStr += "}\n";
				}
				else
				{
					mClassStr += "int " + classname + "::set_" + name
							+ "_value(" + type + " value)\n{\n";
					mClassStr += "\tstring str="+hbasename+"::convert<" + type
							+ ",string>(value);\n";
					mClassStr += "\t"+hbasename+"::set_field_value(\"" + name + "\",str);\n ";
					mClassStr += "\treturn 0;\n";
					mClassStr += "}\n";

					mClassStr += type + " " + classname + "::get_" + name
							+ "_value()\n{\n";
					mClassStr += "\tstring str="+hbasename+"::get_field_value(\"" + name
							+ "\");\n";
					mClassStr += "\t" + type + " value="+hbasename+"::convert<string," + type
							+ ">(str);\n";
					mClassStr += "\treturn value;\n";
					mClassStr += "}\n";
				}
			}
		}
		mClassStr += "}";

		mfile << mClassStr << endl;

	}
	return 0;

}
