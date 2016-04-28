/*
 * DbTable.cpp
 *
 *  Created on: Apr 27, 2016
 *      Author: xuke
 */

#include "DbTable.h"

namespace basic
{
int test::set_aaa_value(string value)
{
	set_field_value("aaa",value);

	return 0;
}
int test::get_aaa_value()
{
	get_field_value("aaa");
	return 0;
}
int test::set_bbb_value(string value)
{
	set_field_value("bbb",value);
	return 0;
}
int test::get_bbb_value()
{
	get_field_value("bbb");
	return 0;
}


} /* namespace basic */
