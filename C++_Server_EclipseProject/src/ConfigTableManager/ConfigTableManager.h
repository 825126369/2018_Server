/*
 * ConfigTableManager.h
 *
 *  Created on: Apr 29, 2016
 *      Author: xuke
 */

#ifndef SRC_INITMANAGER_CONFIGTABLEMANAGER_H_
#define SRC_INITMANAGER_CONFIGTABLEMANAGER_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <libxml/tree.h>
using namespace std;
namespace basic {
class ConfigTableBase;
ConfigTableBase* LoadTableCpp(string classname);
class ConfigTableManager {
public:
	int Init();
	int ReadXML(string path);
	static ConfigTableManager* getSingle();
public:
	int test();
public:
	template<typename T>
	T* getConfigTable(int id) {
		T* value = NULL;
		int classId = T::classId;

		map<int, map<int, ConfigTableBase*> >::iterator aaa = mTableMap.find(classId);
		if (aaa != mTableMap.end()) {
			map<int, ConfigTableBase*> mMap1 = (*aaa).second;
			map<int, ConfigTableBase*>::iterator ccc = mMap1.find(id);
			if (ccc != mMap1.end()) {
				ConfigTableBase* ddd = (*ccc).second;
				value = static_cast<T*>(ddd);
			}
		}
		return value;
	}
private:
	ConfigTableManager();
	virtual ~ConfigTableManager();
public:
	static ConfigTableManager single;
private:
	map<int,map<int,ConfigTableBase*> > mTableMap;
};
class ConfigTableBase
{
public:
	virtual int set_fields_value(vector<string> value)=0;
	virtual int get_fields_value()=0;
	virtual int get_classId_value()=0;
	ConfigTableBase();
	virtual ~ConfigTableBase();
protected:
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

	vector<string> StrToVector(string str,string splitStr);
};




} /* namespace basic */

#endif /* SRC_INITMANAGER_CONFIGTABLEMANAGER_H_ */
