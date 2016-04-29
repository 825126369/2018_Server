/*
 * MariaDBSystem.h
 *
 *  Created on: Apr 26, 2016
 *      Author: xuke
 */

#ifndef SRC_MARIADBMANAGER_MARIADBSYSTEM_H_
#define SRC_MARIADBMANAGER_MARIADBSYSTEM_H_
#include <string>
#include <mysql.h>
#include <iostream>
#include <sstream>
using namespace std;
namespace basic
{
class MariaDBSystem
{
public:
	virtual ~MariaDBSystem();
	int ConnectMariadb();
	int CloseMariaDb();
	int ExcuteSqlCommand(string command);
	int ExcuteSqlSelectCommand(string command);
	static MariaDBSystem* getSingle();
private:
	MariaDBSystem();
private:
	MYSQL* connection;
	string db;
	string ip;
	string user;
	string password;
	static MariaDBSystem* single;

};
class DbTableBase
{
protected:
	DbTableBase();
	~DbTableBase();
	int set_field_value(string fieldname,string value);
	string get_field_value(string fieldname);
	template<typename in_type, typename out_type>
	//out_type convert(const in_type t);
	out_type convert(const in_type t)
	{
		static stringstream stream;
		stream << t; //向流中传值
		out_type result; //这里存储转换结果
		stream >> result; //向result中写入值
		stream.clear();
		return result;
	}


protected:
	string database;
	string tablename;
	string primarykey;
};



}/* namespace basic */

#endif /* SRC_MARIADBMANAGER_MARIADBSYSTEM_H_ */
