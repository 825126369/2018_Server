#include "DbTable.h"
namespace basic{
string game_login::database="game";
string game_login::tablename="game_login";
string game_login::primarykeyname="account";
int game_login::classId=101;
int game_login::create_key_account_value()
{
	CreatePrimaryKey("account",primarykeyvalue);
	return 0;
}
bool game_login::has_key_account_value()
{
	get_key_account_value();
	return OrGetDb_account;
}
string game_login::get_key_account_value()
{
	if(OrGetDb_account==false)
	{
		string str=get_field_value("account");
		account=str;
		if(str==primarykeyvalue && str!="")
		{
			OrGetDb_account=true;
		}
	}
	return account;
}
int game_login::set_key_account_value(string account_value,bool orAutoCreateDb)
{
	account=account_value;
	primarykeyvalue=account_value;
	if(orAutoCreateDb==true && has_key_account_value()==false)
	{
		create_key_account_value();
	}
}
int game_login::set_password_value(string value)
{
	password=value;
	OrGetDb_password=true;
	set_field_value("password",value);
	return 0;
}
string game_login::get_password_value()
{
	if(OrGetDb_password==false)
	{
		string str=get_field_value("password");
		password=str;
		OrGetDb_password=true;
	}
	return password;
}
game_login::game_login()
{
	OrGetDb_account=false;
	OrGetDb_password=false;
}
game_login::game_login(string account_value)
{
	set_key_account_value(account_value,false);
	game_login();
}
game_login::game_login(string account_value,bool OrAutoCreate)
{
	set_key_account_value(account_value,OrAutoCreate);
	game_login();
}
int game_login::get_all_value()
{
	string fieldlist[]={"password"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_password=true;
	password=valuelist[0];
	return 0;
}
int game_login::set_all_value(string password_value)
{
	password=password_value;
	OrGetDb_password=true;
	string passwordStr=password_value;
	string fieldlist[]={"password",passwordStr};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	DbTableBase::set_all_value(result);
	return 0;
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
int game_role::create_key_userId_value()
{
	CreatePrimaryKey("userId",primarykeyvalue);
	return 0;
}
bool game_role::has_key_userId_value()
{
	get_key_userId_value();
	return OrGetDb_userId;
}
int game_role::get_key_userId_value()
{
	if(OrGetDb_userId==false)
	{
		string str=get_field_value("userId");
		int value=DbTableBase::convert<string,int>(str);
		userId=value;
		if(str==primarykeyvalue && str!="")
		{
			OrGetDb_userId=true;
		}
	}
	return userId;
}
int game_role::set_key_userId_value(int userId_value,bool orAutoCreateDb)
{
	userId=userId_value;
	string str=DbTableBase::convert<int,string>(userId_value);
	primarykeyvalue=str;
	if(orAutoCreateDb==true && has_key_userId_value()==false)
	{
		create_key_userId_value();
	}
}
int game_role::set_level_value(int value)
{
	level=value;
	OrGetDb_level=true;
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("level",str);
 	return 0;
}
int game_role::get_level_value()
{
	if(OrGetDb_level==false)
	{
		string str=get_field_value("level");
		int value=DbTableBase::convert<string,int>(str);
		level=value;
		OrGetDb_level=true;
	}
	return level;
}
game_role::game_role()
{
	OrGetDb_userId=false;
	OrGetDb_level=false;
}
game_role::game_role(int userId_value)
{
	set_key_userId_value(userId_value,false);
	game_role();
}
game_role::game_role(int userId_value,bool OrAutoCreate)
{
	set_key_userId_value(userId_value,OrAutoCreate);
	game_role();
}
int game_role::get_all_value()
{
	string fieldlist[]={"level"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_level=true;
	level=DbTableBase::convert<string,int>(valuelist[0]);
	return 0;
}
int game_role::set_all_value(int level_value)
{
	level=level_value;
	OrGetDb_level=true;
	string levelStr=DbTableBase::convert<int,string>(level_value);
	string fieldlist[]={"level",levelStr};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	DbTableBase::set_all_value(result);
	return 0;
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
