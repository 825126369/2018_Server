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
#include <vector>
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
	vector<string> getMultiplefield(string command);
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
	template<typename T>
	T* GetDbTable()
	{
		int id=T::classId;
		map<int,DbTableBase*>::iterator aaa=mDBTableMap.find(id);
		if(aaa!=mDBTableMap.end())
		{
			DbTableBase* bbb=(*aaa).second;
			T* t=static_cast<T*>(bbb);
			return t;
		}else
		{
			T* t=new T();
			mDBTableMap.insert(pair<int,DbTableBase*>(id,t));
			return t;
		}
	}
	template<typename T>
	void RemoveDbTable()
	{
		int id=T::classId;
		map<int,DbTableBase*>::iterator aaa=mDBTableMap.find(id);
		if(aaa!=mDBTableMap.end())
		{
			map<int,DbTableBase*>::iterator aaa=mDBTableMap.erase(aaa);
		}
	}

private:
	map<int,DbTableBase*> mDBTableMap;
};

class DbTableBase
{
protected:
	DbTableBase();
	~DbTableBase();
	int CreatePrimaryKey(string fieldname,string value);

	virtual int  set_all_value(vector<string> fieldlist);
	virtual vector<string>  get_all_value(vector<string> fieldlist);

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
