//============================================================================
// Name        : XmlToMariaDb_config.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <libxml/tree.h>
#include <mysql.h>
#include <vector>
using namespace std;

void writeXML();
void ReadXML();
string GetTrimStr(xmlChar* str);
int ConnectMariadb();
int ExcuteSqlSelectCommand(MYSQL* connection, string command);
int ExcuteSqlCommand(MYSQL* connection, string command);
void Help();
void PrintConnectionInfo();
MYSQL* connection;
string db = "game";
string ip = "127.0.0.1";
string user = "root";
string password = "123";
int main(int length, char** msg)
{
	if (length < 5)
	{
		Help();
		exit(1);
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
	ReadXML();
	mysql_close(connection);
	cout << "Finish XML To MariaDb" << endl;
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

void writeXML()
{

	//定义文档和节点指针
	xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
	xmlNodePtr root_node = xmlNewNode(NULL, BAD_CAST "root");
	//设置根节点
	xmlDocSetRootElement(doc, root_node);
	//xmlNodeSetContent(root_node,(xmlChar*)"rrrrrrooooootttttttts");

	//创建一个节点，设置其内容和属性，然后加入根结点
	xmlNodePtr node = xmlNewNode(NULL, BAD_CAST "node2");
	xmlNodeSetContent(node, (xmlChar*) "aaaaaaaaaaaaa");
	xmlAddChild(root_node, node);

	xmlNodePtr node1 = xmlNewNode(NULL, BAD_CAST "node3");
	xmlNodeSetContent(node1, (xmlChar*) "bbbbbbbbbbbbbbbbbb");
	xmlAddChild(root_node, node1);
	//设置节点属性
	xmlAttrPtr nodeAtt = xmlNewProp(node, BAD_CAST "aaa", BAD_CAST "100");
	xmlNewProp(node, BAD_CAST "bbb", BAD_CAST "100");

	//存储xml文档
	int nRel = 0;
	nRel = xmlSaveFormatFile("CreatedXml.xml", doc, 1);

	if (nRel != -1)
	{
		cout << "一个xml文档被创建,写入" << nRel << "个字节" << endl;
	}
	//释放文档内节点动态申请的内存
	xmlFreeDoc(doc);
}

void ReadXML()
{
	xmlDocPtr doc;
	doc = xmlParseFile("DB_Server.xml");
	xmlNodePtr root = xmlDocGetRootElement(doc);
	cout << "Root: " << root->name << endl;
	xmlNodePtr rootchild = root->children;
	while (rootchild != NULL)
	{
		if (rootchild->type == XML_ELEMENT_NODE)
		{
			//cout << "rootchild: " << rootchild->name << endl;
			xmlNodePtr mNode1 = rootchild->children;
			vector<string> mComment;
			vector<string> mDataType;
			vector<string> mDataName;
			int i = 0;
			while (mNode1 != NULL)
			{
				if (mNode1->type == XML_ELEMENT_NODE)
				{
					//cout << "mNode1: " << mNode1->name << endl;
					xmlNodePtr mNode2 = mNode1->children;
					int j = 0;
					vector<string> mData;
					while (mNode2 != NULL)
					{
						if (mNode2->type == XML_ELEMENT_NODE)
						{
							//cout << "mNode2:" << mNode2->name << endl;
							xmlNodePtr mNode3 = mNode2->children;
							while (mNode3 != NULL)
							{
								if (mNode3->type == XML_TEXT_NODE)
								{
									cout << mNode3->name << ": "
											<< mNode3->content << endl;
									if (i == 0)
									{
										mComment.push_back(
												(char*) mNode3->content);
									}
									else if (i == 1)
									{
										string datatype =
												(char*) mNode3->content;
										if (datatype == "string")
										{
											datatype = "varchar";
										}
										mDataType.push_back(datatype);
									}
									else if (i == 2)
									{
										mDataName.push_back(
												(char*) mNode3->content);
									}
									else if (i >= 3)
									{
										mData.push_back(
												(char*) mNode3->content);
									}
									j++;

								}
								mNode3 = mNode3->next;
							}

						}
						mNode2 = mNode2->next;
					}

					if (i == 3)
					{
						int Length = mComment.size();
						string tablename = (char*) rootchild->name;
						tablename.erase(tablename.end() - 1);
						tablename = "config_" + tablename;

						string sqlCommand = "drop table if exists " + tablename
								+ ";";
						ExcuteSqlCommand(connection, sqlCommand);
						sqlCommand = "create table " + tablename + "(";
						for (int i = 0; i < Length; i++)
						{
							sqlCommand += mDataName[i] + " " + mDataType[i]
									+ "(255) comment'" + mComment[i] + "',";
						}
						sqlCommand.erase(sqlCommand.end() - 1);
						sqlCommand += ")";

						ExcuteSqlCommand(connection, sqlCommand);

					}
					if (i >= 3)
					{
						int Length = mData.size();
						string tablename = (char*) rootchild->name;
						tablename.erase(tablename.end() - 1);
						tablename = "config_" + tablename;
						string sqlCommand = "insert into " + tablename
								+ " values(";
						for (int i = 0; i < Length; i++)
						{
							sqlCommand += "'" + mData[i] + "',";
						}
						sqlCommand.erase(sqlCommand.end() - 1);
						sqlCommand += ")";

						ExcuteSqlCommand(connection, sqlCommand);
					}
					i++;
				}
				mNode1 = mNode1->next;
			}
			string tablename = (char*) rootchild->name;
			tablename.erase(tablename.end() - 1);
			tablename = "config_" + tablename;
			string cmd = "select * from " + tablename;
			ExcuteSqlSelectCommand(connection, cmd);
		}
		rootchild = rootchild->next;
	}
	xmlFreeDoc(doc);

}

string GetTrimStr(xmlChar* str)
{
	string content = (char*) str;
	content = content.substr(content.find_first_not_of(" "),
			content.find_last_not_of(" "));
	return content;
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

	string sqlcommand = "drop database if exists " + db;
	ExcuteSqlCommand(connection, sqlcommand);
	sqlcommand = "create database " + db;
	ExcuteSqlCommand(connection, sqlcommand);
	sqlcommand = "use " + db;
	ExcuteSqlCommand(connection, sqlcommand);
	cout << "连接数据库:" << db << endl;
	return 0;
}
int ExcuteSqlCommand(MYSQL* connection, string command)
{
	cout << "sql command:" << command << endl;
	int EffectRows = mysql_query(connection, command.c_str());
	//cout << "影响的行数:" << EffectRows << endl;
	if (EffectRows == 1)
	{
		cerr << "sql Error:" << mysql_error(connection) << endl;
		exit(1);
	}
}

int ExcuteSqlSelectCommand(MYSQL* connection, string command)
{
	cout << "sql command:" << command << endl;
	int EffectRows = mysql_query(connection, command.c_str());
	//cout << "影响的行数:" << EffectRows << endl;
	if (EffectRows == 1)
	{
		cerr << "sql Error:" << mysql_error(connection) << endl;
		exit(1);
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
				if (row <= 0)
				{

				}
				//mysql_num_fields(res)  函数返回结果集中字段的数
				for (int r = 0; r < mysql_num_fields(res); r++)
				{
					printf("%s\t", row[r]);
				}
				printf("\n");
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
