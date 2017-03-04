/*
 * xkDebug.h
 *
 *  Created on: Mar 21, 2016
 *      Author: xuke
 */

#ifndef SRC_XK_BASIC_XKDEBUG_H_
#define SRC_XK_BASIC_XKDEBUG_H_

#include <iostream>
#include <string>
#include "CommonBase.h"
using namespace std;

#define TEST
namespace basic {

class xk_Debug 
{
public:
	static ostream& Log()
	{
		return cout;
	}
	static ostream& LogSystemError(const char* str)
	{
		return cerr;
	}
};

class LogManager
{
public:
	void Init()
	{

		
	}		
public:
	static ostream& Log()
	{
		return cout;
	}
	static ostream& LogError(const char* str)
	{
		return cerr;
	}
	template<typename T>	
	static void Debug(T s)
	{
#ifdef TEST
		cout<<"Log: "<<to_string(s);
#endif	
	}
	template<typename T>
	static void DebugError(T s)
	{
#ifdef TEST
		cerr<<"LogError: "<<to_string(s);
#endif	
	}
};

} /* namespace basic */

#endif /* SRC_XK_BASIC_XKDEBUG_H_ */
