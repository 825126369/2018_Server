/*
 * xkDebug.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: xuke
 */

#include "xkDebug.h"
namespace basic {

xk_Debug::xk_Debug() {
	// TODO Auto-generated constructor stub

}

xk_Debug::~xk_Debug() {
	// TODO Auto-generated destructor stub
}

int xk_Debug::Log(const char* str)
{
	cout<<str<<endl;
	 return 0;
}

int xk_Debug::Log(const int length,...)
{
	 va_list ap;
	 va_start(ap, length);//将ap指向fmt后的第一个参数
	 int i=0;
	 while(i<length)
	 {
		 char* value = va_arg(ap,char*);
		 cout<<value<<endl;
		 i++;
	 }
	 va_end(ap);//将ap置为NULL
	 return 0;
}
int xk_Debug::LogError(const char* str)
{
	cerr<<RED<<str<<NONE<<endl;
	return 0;
}
int xk_Debug::LogError(const int length,...)
{
		va_list ap;
		 va_start(ap, length);//将ap指向fmt后的第一个参数
		 int i=0;
		 while(i<length)
		 {
			 char* value = va_arg(ap,char*);
			 cerr<<RED<<value<<NONE<<endl;
			 i++;
		 }
		 va_end(ap);//将ap置为NULL
		 return 0;
}

int xk_Debug::LogSystemError(const char* str)
{
	perror(str);
}

} /* namespace basic */
