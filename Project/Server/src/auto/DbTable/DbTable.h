#ifndef SRC_MARIADBMANAGER_DBTABLE_H
#define SRC_MARIADBMANAGER_DBTABLE_H
#include <string>
#include "MariaDBSystem.h"
namespace basic{
class game_login:public DbTableBase
{
public:
	game_login();
	game_login(string account_value);
	game_login(string account_value,bool OrAutoCreateDb);

	int set_key_account_value(string value,bool orAutoCreateDb=false);
	int create_key_account_value();
	bool has_key_account_value();
	string get_key_account_value();

	int set_password_value(string value);
	string get_password_value();

	int set_all_value(string password_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	string account;
	bool OrGetDb_account;
	string password;
	bool OrGetDb_password;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
class game_money:public DbTableBase
{
public:
	game_money();
	game_money(string account_value);
	game_money(string account_value,bool OrAutoCreateDb);

	int set_key_account_value(string value,bool orAutoCreateDb=false);
	int create_key_account_value();
	bool has_key_account_value();
	string get_key_account_value();

	int set_money_value(int value);
	int get_money_value();

	int set_all_value(int money_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	string account;
	bool OrGetDb_account;
	int money;
	bool OrGetDb_money;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
class game_role:public DbTableBase
{
public:
	game_role();
	game_role(int roleId_value);
	game_role(int roleId_value,bool OrAutoCreateDb);

	int set_key_roleId_value(int value,bool orAutoCreateDb=false);
	int create_key_roleId_value();
	bool has_key_roleId_value();
	int get_key_roleId_value();

	int set_name_value(string value);
	string get_name_value();
	int set_gender_value(int value);
	int get_gender_value();
	int set_profession_value(int value);
	int get_profession_value();
	int set_level_value(int value);
	int get_level_value();
	int set_equipBin_value(string value);
	string get_equipBin_value();

	int set_all_value(string name_value,int gender_value,int profession_value,int level_value,string equipBin_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	int roleId;
	bool OrGetDb_roleId;
	string name;
	bool OrGetDb_name;
	int gender;
	bool OrGetDb_gender;
	int profession;
	bool OrGetDb_profession;
	int level;
	bool OrGetDb_level;
	string equipBin;
	bool OrGetDb_equipBin;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
class game_server:public DbTableBase
{
public:
	game_server();
	game_server(string account_value);
	game_server(string account_value,bool OrAutoCreateDb);

	int set_key_account_value(string value,bool orAutoCreateDb=false);
	int create_key_account_value();
	bool has_key_account_value();
	string get_key_account_value();

	int set_loginallserverinfo_value(string value);
	string get_loginallserverinfo_value();
	int set_lastloginserverid_value(int value);
	int get_lastloginserverid_value();

	int set_all_value(string loginallserverinfo_value,int lastloginserverid_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	string account;
	bool OrGetDb_account;
	string loginallserverinfo;
	bool OrGetDb_loginallserverinfo;
	int lastloginserverid;
	bool OrGetDb_lastloginserverid;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
class game_template:public DbTableBase
{
public:
	game_template();
	game_template(int intId_value);
	game_template(int intId_value,bool OrAutoCreateDb);

	int set_key_intId_value(int value,bool orAutoCreateDb=false);
	int create_key_intId_value();
	bool has_key_intId_value();
	int get_key_intId_value();

	int set_stringId_value(string value);
	string get_stringId_value();
	int set_binaryId_value(string value);
	string get_binaryId_value();

	int set_all_value(string stringId_value,string binaryId_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	int intId;
	bool OrGetDb_intId;
	string stringId;
	bool OrGetDb_stringId;
	string binaryId;
	bool OrGetDb_binaryId;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
}
#endif
