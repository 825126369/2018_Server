#ifndef SRC_MARIADBMANAGER_DBTABLE_H
#define SRC_MARIADBMANAGER_DBTABLE_H
#include <string>
#include "MariaDBSystem.h"
namespace basic{
class game_login:private DbTableBase
{
public:
	game_login(string keyvalue);
	int set_account_value(string value);
	string get_account_value();
	int set_password_value(string value);
	string get_password_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	string account;
	string password;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
class game_role:private DbTableBase
{
public:
	game_role(string keyvalue);
	int set_userId_value(int value);
	int get_userId_value();
	int set_level_value(int value);
	int get_level_value();
protected:
	virtual string get_database_value();
	virtual string get_tablename_value();
	virtual string get_primarykeyname_value();
private:
	int userId;
	int level;
	static string database;
	static string tablename;
	static string primarykeyname;
public:
	static int classId;
};
}
#endif
