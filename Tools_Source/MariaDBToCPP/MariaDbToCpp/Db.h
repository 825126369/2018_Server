#ifndef SRC_MARIADBMANAGER_DBTABLE_H;
#define SRC_MARIADBMANAGER_DBTABLE_H;
#include <string>
#include "MariaDBSystem.h"
namespace basic{
class config_Sheet2DB:DbTableBase
{
public:
	int set_id_value(int value);
	int get_id_value();
	int set_fff1_value(string value);
	string get_fff1_value();
	int set_fff2_value(string value);
	string get_fff2_value();
	int set_fff3_value(string value);
	string get_fff3_value();
	int set_fff4_value(string value);
	string get_fff4_value();
private:
	int id;
	string fff1;
	string fff2;
	string fff3;
	string fff4;
};
}
