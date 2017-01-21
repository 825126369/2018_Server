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
#include "MariaDBManagerThread.h"
#include <google/protobuf/message.h>
#include <typeinfo>
using namespace std;
namespace basic
{
class DbTableBase;
class MariaDBSystem
{
public:
	virtual ~MariaDBSystem();
	int Init();
	int CloseMariaDb();

	int ExcuteSqlCommand(string command);
	MYSQL_RES* GetQueryResultCollection();
	int GetResultCollection(string command);
	string getSinglefield(string command);
	vector<string> getMultiplefield(string command);
	static MariaDBSystem* getSingle();
	void Check_Ping();

	bool GetThreadState();
	void SetThreadState(bool orCancelThread);
private:
	MariaDBSystem();
	int ConnectMariadb();
	int InitMariaDBThread();
private:
	MYSQL* connection;
	pthread_rwlock_t m_mutex_ping_t;
	pthread_rwlock_t m_mutex_TrheadState_t;
	bool orCancelThread;
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
	out_type convert(in_type t)
	{			
		static stringstream stream;
		stream << t; //give stream value
		out_type result={}; //init result
		stream >> result; //write result
		stream.clear();
		return result;
	}

	template<typename T>
	string Serialize(T* t)
	{
		if(t!=NULL)
		{	
			google::protobuf::Message* m=static_cast<google::protobuf::Message*>(t);
			const size_t protobuf_Length=m->ByteSize();
			unsigned char* buffer=new unsigned char[protobuf_Length];
			m->SerializeToArray(buffer,protobuf_Length);
			string stream={};
			char* buffer1=new char[protobuf_Length];
			for(int i=0;i<protobuf_Length;i++)
			{
				buffer1[i]=static_cast<char>(buffer[i]);		
			}
			stream=buffer1;
			delete[] buffer;
			delete[] buffer1;
			return stream;	
		}else
		{
			return "";
		}
	}

	template<typename T>
	T* DeSerialize(string stream)
	{
		cout<<"DeSerialize......."<<endl;
		if(stream!="" && stream.length()>0)
		{	
			const size_t protobuf_Length=stream.length();
			unsigned char* buffer=new unsigned char[protobuf_Length];
			for(int i=0;i<protobuf_Length;i++)
			{
				buffer[i]=stream[i];
			}
			google::protobuf::Message* m=new T();
			m->ParseFromArray(buffer,protobuf_Length);
			delete[] buffer;
			return static_cast<T*>(m);
		}else
		{
			return NULL;
		}	
	}

	
protected:
	string primarykeyvalue;
	bool orCreatedDb;
};



}/* namespace basic */

#endif /* SRC_MARIADBMANAGER_MARIADBSYSTEM_H_ */
