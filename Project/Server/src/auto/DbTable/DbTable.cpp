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
int game_money::set_money_value(int value)
{
	money=value;
	OrGetDb_money=true;
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("money",str);
 	return 0;
}
int game_money::get_money_value()
{
	if(OrGetDb_money==false)
	{
		string str=get_field_value("money");
		int value=DbTableBase::convert<string,int>(str);
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
	money=DbTableBase::convert<string,int>(valuelist[0]);
	return 0;
}
int game_money::set_all_value(int money_value)
{
	money=money_value;
	OrGetDb_money=true;
	string moneyStr=DbTableBase::convert<int,string>(money_value);
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
int game_role::get_key_roleId_value()
{
	if(OrGetDb_roleId==false)
	{
		string str=get_field_value("roleId");
		int value=DbTableBase::convert<string,int>(str);
		roleId=value;
		if(str==primarykeyvalue && str!="")
		{
			OrGetDb_roleId=true;
		}
	}
	return roleId;
}
int game_role::set_key_roleId_value(int roleId_value,bool orAutoCreateDb)
{
	roleId=roleId_value;
	string str=DbTableBase::convert<int,string>(roleId_value);
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
int game_role::set_gender_value(int value)
{
	gender=value;
	OrGetDb_gender=true;
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("gender",str);
 	return 0;
}
int game_role::get_gender_value()
{
	if(OrGetDb_gender==false)
	{
		string str=get_field_value("gender");
		int value=DbTableBase::convert<string,int>(str);
		gender=value;
		OrGetDb_gender=true;
	}
	return gender;
}
int game_role::set_profession_value(int value)
{
	profession=value;
	OrGetDb_profession=true;
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("profession",str);
 	return 0;
}
int game_role::get_profession_value()
{
	if(OrGetDb_profession==false)
	{
		string str=get_field_value("profession");
		int value=DbTableBase::convert<string,int>(str);
		profession=value;
		OrGetDb_profession=true;
	}
	return profession;
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
int game_role::set_equipBin_value(string value)
{
	equipBin=value;
	OrGetDb_equipBin=true;
	set_field_value("equipBin",value);
	return 0;
}
string game_role::get_equipBin_value()
{
	if(OrGetDb_equipBin==false)
	{
		string str=get_field_value("equipBin");
		equipBin=str;
		OrGetDb_equipBin=true;
	}
	return equipBin;
}
game_role::game_role()
{
	OrGetDb_roleId=false;
	OrGetDb_name=false;
	OrGetDb_gender=false;
	OrGetDb_profession=false;
	OrGetDb_level=false;
	OrGetDb_equipBin=false;
}
game_role::game_role(int roleId_value)
{
	set_key_roleId_value(roleId_value,false);
	game_role();
}
game_role::game_role(int roleId_value,bool OrAutoCreate)
{
	set_key_roleId_value(roleId_value,OrAutoCreate);
	game_role();
}
int game_role::get_all_value()
{
	string fieldlist[]={"name","gender","profession","level","equipBin"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_name=true;
	name=valuelist[0];
	OrGetDb_gender=true;
	gender=DbTableBase::convert<string,int>(valuelist[1]);
	OrGetDb_profession=true;
	profession=DbTableBase::convert<string,int>(valuelist[2]);
	OrGetDb_level=true;
	level=DbTableBase::convert<string,int>(valuelist[3]);
	OrGetDb_equipBin=true;
	equipBin=valuelist[4];
	return 0;
}
int game_role::set_all_value(string name_value,int gender_value,int profession_value,int level_value,string equipBin_value)
{
	name=name_value;
	OrGetDb_name=true;
	string nameStr=name_value;
	gender=gender_value;
	OrGetDb_gender=true;
	string genderStr=DbTableBase::convert<int,string>(gender_value);
	profession=profession_value;
	OrGetDb_profession=true;
	string professionStr=DbTableBase::convert<int,string>(profession_value);
	level=level_value;
	OrGetDb_level=true;
	string levelStr=DbTableBase::convert<int,string>(level_value);
	equipBin=equipBin_value;
	OrGetDb_equipBin=true;
	string equipBinStr=equipBin_value;
	string fieldlist[]={"name",nameStr,"gender",genderStr,"profession",professionStr,"level",levelStr,"equipBin",equipBinStr};
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
int game_server::set_loginallserverinfo_value(string value)
{
	loginallserverinfo=value;
	OrGetDb_loginallserverinfo=true;
	set_field_value("loginallserverinfo",value);
	return 0;
}
string game_server::get_loginallserverinfo_value()
{
	if(OrGetDb_loginallserverinfo==false)
	{
		string str=get_field_value("loginallserverinfo");
		loginallserverinfo=str;
		OrGetDb_loginallserverinfo=true;
	}
	return loginallserverinfo;
}
int game_server::set_lastloginserverid_value(int value)
{
	lastloginserverid=value;
	OrGetDb_lastloginserverid=true;
	string str=DbTableBase::convert<int,string>(value);
	DbTableBase::set_field_value("lastloginserverid",str);
 	return 0;
}
int game_server::get_lastloginserverid_value()
{
	if(OrGetDb_lastloginserverid==false)
	{
		string str=get_field_value("lastloginserverid");
		int value=DbTableBase::convert<string,int>(str);
		lastloginserverid=value;
		OrGetDb_lastloginserverid=true;
	}
	return lastloginserverid;
}
game_server::game_server()
{
	OrGetDb_account=false;
	OrGetDb_loginallserverinfo=false;
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
	string fieldlist[]={"loginallserverinfo","lastloginserverid"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_loginallserverinfo=true;
	loginallserverinfo=valuelist[0];
	OrGetDb_lastloginserverid=true;
	lastloginserverid=DbTableBase::convert<string,int>(valuelist[1]);
	return 0;
}
int game_server::set_all_value(string loginallserverinfo_value,int lastloginserverid_value)
{
	loginallserverinfo=loginallserverinfo_value;
	OrGetDb_loginallserverinfo=true;
	string loginallserverinfoStr=loginallserverinfo_value;
	lastloginserverid=lastloginserverid_value;
	OrGetDb_lastloginserverid=true;
	string lastloginserveridStr=DbTableBase::convert<int,string>(lastloginserverid_value);
	string fieldlist[]={"loginallserverinfo",loginallserverinfoStr,"lastloginserverid",lastloginserveridStr};
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

string game_template::database="game";
string game_template::tablename="game_template";
string game_template::primarykeyname="intId";
int game_template::classId=105;
int game_template::create_key_intId_value()
{
	CreatePrimaryKey("intId",primarykeyvalue);
	return 0;
}
bool game_template::has_key_intId_value()
{
	get_key_intId_value();
	return OrGetDb_intId;
}
int game_template::get_key_intId_value()
{
	if(OrGetDb_intId==false)
	{
		string str=get_field_value("intId");
		int value=DbTableBase::convert<string,int>(str);
		intId=value;
		if(str==primarykeyvalue && str!="")
		{
			OrGetDb_intId=true;
		}
	}
	return intId;
}
int game_template::set_key_intId_value(int intId_value,bool orAutoCreateDb)
{
	intId=intId_value;
	string str=DbTableBase::convert<int,string>(intId_value);
	primarykeyvalue=str;
	if(orAutoCreateDb==true && has_key_intId_value()==false)
	{
		create_key_intId_value();
	}
}
int game_template::set_stringId_value(string value)
{
	stringId=value;
	OrGetDb_stringId=true;
	set_field_value("stringId",value);
	return 0;
}
string game_template::get_stringId_value()
{
	if(OrGetDb_stringId==false)
	{
		string str=get_field_value("stringId");
		stringId=str;
		OrGetDb_stringId=true;
	}
	return stringId;
}
int game_template::set_binaryId_value(string value)
{
	binaryId=value;
	OrGetDb_binaryId=true;
	set_field_value("binaryId",value);
	return 0;
}
string game_template::get_binaryId_value()
{
	if(OrGetDb_binaryId==false)
	{
		string str=get_field_value("binaryId");
		binaryId=str;
		OrGetDb_binaryId=true;
	}
	return binaryId;
}
game_template::game_template()
{
	OrGetDb_intId=false;
	OrGetDb_stringId=false;
	OrGetDb_binaryId=false;
}
game_template::game_template(int intId_value)
{
	set_key_intId_value(intId_value,false);
	game_template();
}
game_template::game_template(int intId_value,bool OrAutoCreate)
{
	set_key_intId_value(intId_value,OrAutoCreate);
	game_template();
}
int game_template::get_all_value()
{
	string fieldlist[]={"stringId","binaryId"};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	vector<string> valuelist=DbTableBase::get_all_value(result);
	OrGetDb_stringId=true;
	stringId=valuelist[0];
	OrGetDb_binaryId=true;
	binaryId=valuelist[1];
	return 0;
}
int game_template::set_all_value(string stringId_value,string binaryId_value)
{
	stringId=stringId_value;
	OrGetDb_stringId=true;
	string stringIdStr=stringId_value;
	binaryId=binaryId_value;
	OrGetDb_binaryId=true;
	string binaryIdStr=binaryId_value;
	string fieldlist[]={"stringId",stringIdStr,"binaryId",binaryIdStr};
	size_t length=sizeof(fieldlist)/sizeof(string);
	vector<string> result(fieldlist,fieldlist+length);
	DbTableBase::set_all_value(result);
	return 0;
}
string game_template::get_database_value()
{
	return database;
}
string game_template::get_tablename_value()
{
	return tablename;
}
string game_template::get_primarykeyname_value()
{
	return primarykeyname;
}

}
