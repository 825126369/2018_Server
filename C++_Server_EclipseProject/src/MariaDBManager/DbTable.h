/*
 * DbTable.h
 *
 *  Created on: Apr 27, 2016
 *      Author: xuke
 */

#ifndef SRC_MARIADBMANAGER_DBTABLE_H_
#define SRC_MARIADBMANAGER_DBTABLE_H_
#include <string>
#include "MariaDBSystem.h"
namespace basic
{

class test: DbTableBase
{
public:
	int set_aaa_value(string value);
	int get_aaa_value();
	int set_bbb_value(string value);
	int get_bbb_value();
private:
	int aaa;
	int bbb;

};

} /* namespace basic */

#endif /* SRC_MARIADBMANAGER_DBTABLE_H_ */
