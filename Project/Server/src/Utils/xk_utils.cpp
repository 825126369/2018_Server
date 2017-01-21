#include "xk_utils.h" 
 
namespace basic
{
	unsigned long generateUUID()   
	{  
   		uuid_t uu;   
   		uuid_generate_time_safe(uu);  
		unsigned long aa=(uu[7]<<56 | uu[6]<<48 | uu[5]<<40 |uu[4]<<32 |uu[3]<<24 | uu[2]<<16 | uu[1]<<8 | uu[0]);
		return aa;   
	}
}
