/*
 * xkDebug.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: xuke
 */

#include "../DebugManager/xkDebug.h"
namespace basic {

xk_Debug::xk_Debug() {
	// TODO Auto-generated constructor stub

}

xk_Debug::~xk_Debug() {
	// TODO Auto-generated destructor stub
}

ostream& xk_Debug::Log()
{
	 return cout;
}



ostream& xk_Debug::LogSystemError(const char* str)
{
	perror(str);
}


} /* namespace basic */
