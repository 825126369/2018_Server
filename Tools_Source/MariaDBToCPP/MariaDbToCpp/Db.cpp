#include "Db.h"
namespace basic{
int config_Sheet1DB::set_id_value(int value)
{
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("id",str);
 	return 0;
}
int config_Sheet1DB::get_id_value()
{
	string str=DbTableBase::get_field_value("id");
	int value=DbTableBase::convert<string,int>(str);
	return value;
}
int config_Sheet1DB::set_fff1_value(string value)
{
	set_field_value("fff1",value);
	return 0;
}
string config_Sheet1DB::get_fff1_value()
{
	string str=get_field_value("fff1");
	return str;
}
int config_Sheet1DB::set_fff2_value(string value)
{
	set_field_value("fff2",value);
	return 0;
}
string config_Sheet1DB::get_fff2_value()
{
	string str=get_field_value("fff2");
	return str;
}
int config_Sheet1DB::set_fff3_value(string value)
{
	set_field_value("fff3",value);
	return 0;
}
string config_Sheet1DB::get_fff3_value()
{
	string str=get_field_value("fff3");
	return str;
}
int config_Sheet1DB::set_fff4_value(string value)
{
	set_field_value("fff4",value);
	return 0;
}
string config_Sheet1DB::get_fff4_value()
{
	string str=get_field_value("fff4");
	return str;
}
int config_Sheet2DB::set_id_value(int value)
{
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("id",str);
 	return 0;
}
int config_Sheet2DB::get_id_value()
{
	string str=DbTableBase::get_field_value("id");
	int value=DbTableBase::convert<string,int>(str);
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
int game_login::set_id_value(int value)
{
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("id",str);
 	return 0;
}
int game_login::get_id_value()
{
	string str=DbTableBase::get_field_value("id");
	int value=DbTableBase::convert<string,int>(str);
	return value;
}
int game_login::set_account_value(string value)
{
	set_field_value("account",value);
	return 0;
}
string game_login::get_account_value()
{
	string str=get_field_value("account");
	return str;
}
int game_login::set_password_value(string value)
{
	set_field_value("password",value);
	return 0;
}
string game_login::get_password_value()
{
	string str=get_field_value("password");
	return str;
}
int game_role::set_id_value(int value)
{
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("id",str);
 	return 0;
}
int game_role::get_id_value()
{
	string str=DbTableBase::get_field_value("id");
	int value=DbTableBase::convert<string,int>(str);
	return value;
}
int game_role::set_userId_value(int value)
{
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("userId",str);
 	return 0;
}
int game_role::get_userId_value()
{
	string str=DbTableBase::get_field_value("userId");
	int value=DbTableBase::convert<string,int>(str);
	return value;
}
int game_role::set_level_value(int value)
{
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("level",str);
 	return 0;
}
int game_role::get_level_value()
{
	string str=DbTableBase::get_field_value("level");
	int value=DbTableBase::convert<string,int>(str);
	return value;
}
}
