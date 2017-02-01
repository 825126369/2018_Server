#include "Environment.h"

void CheckEnvironment()
{
	assert(CHAR_BIT==8);	
	assert(sizeof(short)==2);
	assert(sizeof(int)==4);
	assert(sizeof(long)==8);
}
