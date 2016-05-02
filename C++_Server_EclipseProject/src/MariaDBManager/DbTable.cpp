#include "DbTable.h"
namespace basic{
string game_login::database="game";
string game_login::tablename="game_login";
string game_login::primarykeyname="account";
int game_login::classId=101;
game_login::game_login(string keyvalue)
{
	primarykeyvalue=keyvalue;
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
string game_login::get_database_value()
{
	return database;
}
string game_login::get_tablename_value()
{
	return tablename;
}
string game_login::get_primarykeyname_value()
{
	return primarykeyname;
}

string game_role::database="game";
string game_role::tablename="game_role";
string game_role::primarykeyname="userId";
int game_role::classId=102;
game_role::game_role(string keyvalue)
{
	primarykeyvalue=keyvalue;
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
string game_role::get_database_value()
{
	return database;
}
string game_role::get_tablename_value()
{
	return tablename;
}
string game_role::get_primarykeyname_value()
{
	return primarykeyname;
}

}
