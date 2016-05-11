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
class game_role:public DbTableBase
{
public:
	game_role();
	game_role(int userId_value);
	game_role(int userId_value,bool OrAutoCreateDb);

	int set_key_userId_value(int value,bool orAutoCreateDb=false);
	int create_key_userId_value();
	bool has_key_userId_value();
	int get_key_userId_value();

	int set_level_value(int value);
	int get_level_value();

	int set_all_value(int level_value);
	int get_all_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	int userId;
	bool OrGetDb_userId;
	int level;
	bool OrGetDb_level;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
}
#endif
