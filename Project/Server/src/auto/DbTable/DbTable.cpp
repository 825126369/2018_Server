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

string game_money::database="game";
string game_money::tablename="game_money";
string game_money::primarykeyname="account";
int game_money::classId=102;
int game_money::create_key_account_value()
{
	CreatePrimaryKey("account",primarykeyvalue);
	return 0;
}
bool game_money::has_key_account_value()
{
	get_key_account_value();
	return OrGetDb_account;
}
string game_money::get_key_account_value()
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
int game_money::set_key_account_value(string account_value,bool orAutoCreateDb)
{
	account=account_value;
	primarykeyvalue=account_value;
	if(orAutoCreateDb==true && has_key_account_value()==false)
	{
		create_key_account_value();
	}
}
int game_money::set_money_value(unsigned int value)
{
	money=value;
	OrGetDb_money=true;
	string str=DbTableBase::convert<unsigned int,string>(money);
	DbTableBase::set_field_value("money",str);
 	return 0;
}
unsigned int game_money::get_money_value()
{
	if(OrGetDb_money==false)
	{
		string str=get_field_value("money");
		unsigned int value=DbTableBase::convert<string,unsigned int>(str);
		money=value;
		OrGetDb_money=true;
	}
	return money;
}
game_money::game_money()
{
	OrGetDb_account=false;
	OrGetDb_money=false;
}
game_money::game_money(string account_value)
{
	set_key_account_value(account_value,false);
	game_money();
}
game_money::game_money(string account_value,bool OrAutoCreate)
{
	set_key_account_value(account_value,OrAutoCreate);
	game_money();
}
int game_money::get_all_value()
{
	string fieldlist[]={"money"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_money=true;
	money=DbTableBase::convert<string,unsigned int>(valuelist[0]);
	return 0;
}
int game_money::set_all_value(unsigned int money_value)
{
	money=money_value;
	OrGetDb_money=true;
	string moneyStr=DbTableBase::convert<unsigned int,string>(money);
	string fieldlist[]={"money",moneyStr};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	DbTableBase::set_all_value(result);
	return 0;
}
string game_money::get_database_value()
{
	return database;
}
string game_money::get_tablename_value()
{
	return tablename;
}
string game_money::get_primarykeyname_value()
{
	return primarykeyname;
}

string game_role::database="game";
string game_role::tablename="game_role";
string game_role::primarykeyname="roleId";
int game_role::classId=103;
int game_role::create_key_roleId_value()
{
	CreatePrimaryKey("roleId",primarykeyvalue);
	return 0;
}
bool game_role::has_key_roleId_value()
{
	get_key_roleId_value();
	return OrGetDb_roleId;
}
unsigned int game_role::get_key_roleId_value()
{
	if(OrGetDb_roleId==false)
	{
		string str=get_field_value("roleId");
		unsigned int value=DbTableBase::convert<string,unsigned int>(str);
		roleId=value;
		if(str==primarykeyvalue && str!="")
		{
			OrGetDb_roleId=true;
		}
	}
	return roleId;
}
int game_role::set_key_roleId_value(unsigned int roleId_value,bool orAutoCreateDb)
{
	roleId=roleId_value;
	string str=DbTableBase::convert<unsigned int,string>(roleId_value);
	primarykeyvalue=str;
	if(orAutoCreateDb==true && has_key_roleId_value()==false)
	{
		create_key_roleId_value();
	}
}
int game_role::set_name_value(string value)
{
	name=value;
	OrGetDb_name=true;
	set_field_value("name",value);
	return 0;
}
string game_role::get_name_value()
{
	if(OrGetDb_name==false)
	{
		string str=get_field_value("name");
		name=str;
		OrGetDb_name=true;
	}
	return name;
}
int game_role::set_gender_value(unsigned int value)
{
	gender=value;
	OrGetDb_gender=true;
	string str=DbTableBase::convert<unsigned int,string>(gender);
	DbTableBase::set_field_value("gender",str);
 	return 0;
}
unsigned int game_role::get_gender_value()
{
	if(OrGetDb_gender==false)
	{
		string str=get_field_value("gender");
		unsigned int value=DbTableBase::convert<string,unsigned int>(str);
		gender=value;
		OrGetDb_gender=true;
	}
	return gender;
}
int game_role::set_profession_value(unsigned int value)
{
	profession=value;
	OrGetDb_profession=true;
	string str=DbTableBase::convert<unsigned int,string>(profession);
	DbTableBase::set_field_value("profession",str);
 	return 0;
}
unsigned int game_role::get_profession_value()
{
	if(OrGetDb_profession==false)
	{
		string str=get_field_value("profession");
		unsigned int value=DbTableBase::convert<string,unsigned int>(str);
		profession=value;
		OrGetDb_profession=true;
	}
	return profession;
}
int game_role::set_level_value(unsigned int value)
{
	level=value;
	OrGetDb_level=true;
	string str=DbTableBase::convert<unsigned int,string>(level);
	DbTableBase::set_field_value("level",str);
 	return 0;
}
unsigned int game_role::get_level_value()
{
	if(OrGetDb_level==false)
	{
		string str=get_field_value("level");
		unsigned int value=DbTableBase::convert<string,unsigned int>(str);
		level=value;
		OrGetDb_level=true;
	}
	return level;
}
game_role::game_role()
{
	OrGetDb_roleId=false;
	OrGetDb_name=false;
	OrGetDb_gender=false;
	OrGetDb_profession=false;
	OrGetDb_level=false;
}
game_role::game_role(unsigned int roleId_value)
{
	set_key_roleId_value(roleId_value,false);
	game_role();
}
game_role::game_role(unsigned int roleId_value,bool OrAutoCreate)
{
	set_key_roleId_value(roleId_value,OrAutoCreate);
	game_role();
}
int game_role::get_all_value()
{
	string fieldlist[]={"name","gender","profession","level"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_name=true;
	name=valuelist[0];
	OrGetDb_gender=true;
	gender=DbTableBase::convert<string,unsigned int>(valuelist[1]);
	OrGetDb_profession=true;
	profession=DbTableBase::convert<string,unsigned int>(valuelist[2]);
	OrGetDb_level=true;
	level=DbTableBase::convert<string,unsigned int>(valuelist[3]);
	return 0;
}
int game_role::set_all_value(string name_value,unsigned int gender_value,unsigned int profession_value,unsigned int level_value)
{
	name=name_value;
	OrGetDb_name=true;
	string nameStr=name_value;
	gender=gender_value;
	OrGetDb_gender=true;
	string genderStr=DbTableBase::convert<unsigned int,string>(gender);
	profession=profession_value;
	OrGetDb_profession=true;
	string professionStr=DbTableBase::convert<unsigned int,string>(profession);
	level=level_value;
	OrGetDb_level=true;
	string levelStr=DbTableBase::convert<unsigned int,string>(level);
	string fieldlist[]={"name",nameStr,"gender",genderStr,"profession",professionStr,"level",levelStr};
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

string game_server::database="game";
string game_server::tablename="game_server";
string game_server::primarykeyname="account";
int game_server::classId=104;
int game_server::create_key_account_value()
{
	CreatePrimaryKey("account",primarykeyvalue);
	return 0;
}
bool game_server::has_key_account_value()
{
	get_key_account_value();
	return OrGetDb_account;
}
string game_server::get_key_account_value()
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
int game_server::set_key_account_value(string account_value,bool orAutoCreateDb)
{
	account=account_value;
	primarykeyvalue=account_value;
	if(orAutoCreateDb==true && has_key_account_value()==false)
	{
		create_key_account_value();
	}
}
int game_server::set_custom_db_loginallserverinfo_value(db_loginallserverinfo* value)
{
	custom_db_loginallserverinfo=value;
	OrGetDb_custom_db_loginallserverinfo=true;
	string str=DbTableBase::Serialize<db_loginallserverinfo>(custom_db_loginallserverinfo);
	DbTableBase::set_field_value("custom_db_loginallserverinfo",str);
 	return 0;
}
db_loginallserverinfo* game_server::get_custom_db_loginallserverinfo_value()
{
	if(OrGetDb_custom_db_loginallserverinfo==false)
	{
		string str=get_field_value("custom_db_loginallserverinfo");
		db_loginallserverinfo* value=DbTableBase::DeSerialize<db_loginallserverinfo>(str);
		custom_db_loginallserverinfo=value;
		OrGetDb_custom_db_loginallserverinfo=true;
	}
	return custom_db_loginallserverinfo;
}
int game_server::set_lastloginserverid_value(unsigned int value)
{
	lastloginserverid=value;
	OrGetDb_lastloginserverid=true;
	string str=DbTableBase::convert<unsigned int,string>(lastloginserverid);
	DbTableBase::set_field_value("lastloginserverid",str);
 	return 0;
}
unsigned int game_server::get_lastloginserverid_value()
{
	if(OrGetDb_lastloginserverid==false)
	{
		string str=get_field_value("lastloginserverid");
		unsigned int value=DbTableBase::convert<string,unsigned int>(str);
		lastloginserverid=value;
		OrGetDb_lastloginserverid=true;
	}
	return lastloginserverid;
}
game_server::game_server()
{
	OrGetDb_account=false;
	OrGetDb_custom_db_loginallserverinfo=false;
	OrGetDb_lastloginserverid=false;
}
game_server::game_server(string account_value)
{
	set_key_account_value(account_value,false);
	game_server();
}
game_server::game_server(string account_value,bool OrAutoCreate)
{
	set_key_account_value(account_value,OrAutoCreate);
	game_server();
}
int game_server::get_all_value()
{
	string fieldlist[]={"custom_db_loginallserverinfo","lastloginserverid"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_custom_db_loginallserverinfo=true;
	custom_db_loginallserverinfo=DbTableBase::DeSerialize<db_loginallserverinfo>(valuelist[0]);
	OrGetDb_lastloginserverid=true;
	lastloginserverid=DbTableBase::convert<string,unsigned int>(valuelist[1]);
	return 0;
}
int game_server::set_all_value(db_loginallserverinfo* custom_db_loginallserverinfo_value,unsigned int lastloginserverid_value)
{
	custom_db_loginallserverinfo=custom_db_loginallserverinfo_value;
	OrGetDb_custom_db_loginallserverinfo=true;
	string custom_db_loginallserverinfoStr=DbTableBase::Serialize<db_loginallserverinfo>(custom_db_loginallserverinfo);
	lastloginserverid=lastloginserverid_value;
	OrGetDb_lastloginserverid=true;
	string lastloginserveridStr=DbTableBase::convert<unsigned int,string>(lastloginserverid);
	string fieldlist[]={"custom_db_loginallserverinfo",custom_db_loginallserverinfoStr,"lastloginserverid",lastloginserveridStr};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	DbTableBase::set_all_value(result);
	return 0;
}
string game_server::get_database_value()
{
	return database;
}
string game_server::get_tablename_value()
{
	return tablename;
}
string game_server::get_primarykeyname_value()
{
	return primarykeyname;
}

}
