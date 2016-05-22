#ifndef SRC_MARIADBMANAGER_DBTABLE_H
#define SRC_MARIADBMANAGER_DBTABLE_H
#include <string>
#include <vector>
#include <array>
#include "ConfigTableManager.h"
using namespace std;
namespace basic{
class config_Sheet1DB:public ConfigTableBase
{
public:
	int get_id_value();
	array<string,3> get_fff1_value();
	array<string,4> get_fff2_value();
	array<string,5> get_fff3_value();
	array<string,6> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet1DB();
	virtual ~config_Sheet1DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	array<string,3> fff1;
	array<string,4> fff2;
	array<string,5> fff3;
	array<string,6> fff4;
public:
	static int classId;
};
class config_Sheet2DB:public ConfigTableBase
{
public:
	int get_id_value();
	array<string,3> get_fff1_value();
	array<string,4> get_fff2_value();
	array<string,5> get_fff3_value();
	array<string,6> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet2DB();
	virtual ~config_Sheet2DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	array<string,3> fff1;
	array<string,4> fff2;
	array<string,5> fff3;
	array<string,6> fff4;
public:
	static int classId;
};
class config_Sheet3DB:public ConfigTableBase
{
public:
	int get_id_value();
	array<string,3> get_fff1_value();
	array<string,4> get_fff2_value();
	array<string,5> get_fff3_value();
	array<string,6> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet3DB();
	virtual ~config_Sheet3DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	array<string,3> fff1;
	array<string,4> fff2;
	array<string,5> fff3;
	array<string,6> fff4;
public:
	static int classId;
};
class config_Sheet4DB:public ConfigTableBase
{
public:
	int get_id_value();
	string get_fff0_value();
	array<int,10> get_fff6_value();
	array<string,3> get_fff1_value();
	array<string,4> get_fff2_value();
	array<string,5> get_fff3_value();
	array<string,6> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet4DB();
	virtual ~config_Sheet4DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	string fff0;
	array<int,10> fff6;
	array<string,3> fff1;
	array<string,4> fff2;
	array<string,5> fff3;
	array<string,6> fff4;
public:
	static int classId;
};
ConfigTableBase* LoadTableCpp(string classname);
}
#endif
