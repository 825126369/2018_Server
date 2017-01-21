#ifndef SRC_MARIADBMANAGER_DBTABLE_H
#define SRC_MARIADBMANAGER_DBTABLE_H
#include <string>
#include "MariaDBSystem.h"
#include "db_protobuf.pb.h"
#include "db_protobuf_struct.pb.h"
using namespace db_protobuf;
using namespace std;
namespace basic
{
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

	int set_money_value(unsigned int value);
	unsigned int get_money_value();

	int set_all_value(unsigned int money_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	string account;
	bool OrGetDb_account;
	unsigned int money;
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
	game_role(unsigned int roleId_value);
	game_role(unsigned int roleId_value,bool OrAutoCreateDb);

	int set_key_roleId_value(unsigned int value,bool orAutoCreateDb=false);
	int create_key_roleId_value();
	bool has_key_roleId_value();
	unsigned int get_key_roleId_value();

	int set_name_value(string value);
	string get_name_value();
	int set_gender_value(unsigned int value);
	unsigned int get_gender_value();
	int set_profession_value(unsigned int value);
	unsigned int get_profession_value();
	int set_level_value(unsigned int value);
	unsigned int get_level_value();

	int set_all_value(string name_value,unsigned int gender_value,unsigned int profession_value,unsigned int level_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	unsigned int roleId;
	bool OrGetDb_roleId;
	string name;
	bool OrGetDb_name;
	unsigned int gender;
	bool OrGetDb_gender;
	unsigned int profession;
	bool OrGetDb_profession;
	unsigned int level;
	bool OrGetDb_level;
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

	int set_custom_db_loginallserverinfo_value(db_loginallserverinfo* value);
	db_loginallserverinfo* get_custom_db_loginallserverinfo_value();
	int set_lastloginserverid_value(unsigned int value);
	unsigned int get_lastloginserverid_value();

	int set_all_value(db_loginallserverinfo* custom_db_loginallserverinfo_value,unsigned int lastloginserverid_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	string account;
	bool OrGetDb_account;
	db_loginallserverinfo* custom_db_loginallserverinfo;
	bool OrGetDb_custom_db_loginallserverinfo;
	unsigned int lastloginserverid;
	bool OrGetDb_lastloginserverid;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
}
#endif
