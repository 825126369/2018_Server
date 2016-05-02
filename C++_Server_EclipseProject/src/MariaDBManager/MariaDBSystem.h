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
#include <map>
using namespace std;
namespace basic
{
class DbTableBase;
class MariaDBSystem
{
public:
	virtual ~MariaDBSystem();
	int ConnectMariadb();
	int CloseMariaDb();
	int ExcuteSqlCommand(string command);
	int GetResultCollection(string command);
	string getSinglefield(string command);
	bool IsExistsDb(string command);
	string getAllFields(string command);
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

class DbTableManager
{
public:

public:
	template<typename T>
	T* getDbTable()
	{
		int id=T::classId;
		map<int,DbTableBase*>::iterator aaa=mDBTableMap.find(id);
		if(aaa!=mDBTableMap.end())
		{
			DbTableBase* bbb=(*aaa).second;
			T* t=static_cast<T*>(bbb);
			return t;
		}
	}

private:
	map<int,DbTableBase*> mDBTableMap;
};

class DbTableBase
{
public:
	bool OrExistsPrimaryKey();
	int CreatePrimaryKey();
protected:
	DbTableBase();
	~DbTableBase();

	int set_field_value(string fieldname,string value);
	string get_field_value(string fieldname);
	virtual string get_database_value()=0;
	virtual string get_tablename_value()=0;
	virtual string get_primarykeyname_value()=0;
	template<typename in_type, typename out_type>
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
	string primarykeyvalue;
	bool orCreatedDb;
};



}/* namespace basic */

#endif /* SRC_MARIADBMANAGER_MARIADBSYSTEM_H_ */
