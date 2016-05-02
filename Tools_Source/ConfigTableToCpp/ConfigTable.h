#ifndef SRC_MARIADBMANAGER_DBTABLE_H
#define SRC_MARIADBMANAGER_DBTABLE_H
#include <string>
#include <vector>
#include "ConfigTableManager.h"
using namespace std;
namespace basic{
class config_Sheet1DB:public ConfigTableBase
{
public:
	int get_id_value();
	string get_fff1_value();
	string get_fff2_value();
	string get_fff3_value();
	string get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet1DB();
	virtual ~config_Sheet1DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	string fff1;
	string fff2;
	string fff3;
	string fff4;
public:
	static int classId;
};
class config_Sheet2DB:public ConfigTableBase
{
public:
	int get_id_value();
	string get_fff1_value();
	string get_fff2_value();
	string get_fff3_value();
	string get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet2DB();
	virtual ~config_Sheet2DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	string fff1;
	string fff2;
	string fff3;
	string fff4;
public:
	static int classId;
};
ConfigTableBase* LoadTableCpp(string classname);
}
#endif
