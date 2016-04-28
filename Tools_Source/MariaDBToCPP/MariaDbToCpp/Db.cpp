#include "Db.h"
namespace basic{
int config_Sheet2DB::set_id_value(int value)
{
	string str=convert<int,string>(value);
	set_field_value("id",str);
 	return 0;
}
int config_Sheet2DB::get_id_value()
{
	string str=get_field_value("id");
	int value=convert<string,int>(str);
	return value;
}
int config_Sheet2DB::set_fff1_value(string value)
{
	set_field_value("fff1",value);
	return 0;
}
string config_Sheet2DB::get_fff1_value()
{
	string str=get_field_value("fff1");
	return str;
}
int config_Sheet2DB::set_fff2_value(string value)
{
	set_field_value("fff2",value);
	return 0;
}
string config_Sheet2DB::get_fff2_value()
{
	string str=get_field_value("fff2");
	return str;
}
int config_Sheet2DB::set_fff3_value(string value)
{
	set_field_value("fff3",value);
	return 0;
}
string config_Sheet2DB::get_fff3_value()
{
	string str=get_field_value("fff3");
	return str;
}
int config_Sheet2DB::set_fff4_value(string value)
{
	set_field_value("fff4",value);
	return 0;
}
string config_Sheet2DB::get_fff4_value()
{
	string str=get_field_value("fff4");
	return str;
}
}
