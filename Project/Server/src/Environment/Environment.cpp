#include "Environment.h"
void CheckSystemVersion()
{
	size_t bits= sizeof(char *);
	assert(bits==8);
}
void CheckEndianPattern()
{
	short int x；
	char x0,x1;
	x=1;
	x0=((char*)&x)[0]; //低地址单元
	x1=((char*)&x)[1]; //高地址单元
	assert(x0==1);
}
void CheckEnvironment()
{
	assert(CHAR_BIT==8);	
	assert(sizeof(short)==2);
	assert(sizeof(int)==4);
	assert(sizeof(long)==8);

	CheckEndianPattern();
	CheckSystemVersion();
}

