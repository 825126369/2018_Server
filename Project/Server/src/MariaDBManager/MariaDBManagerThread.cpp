/*
 * MariaDBManagerThread.cpp
 *
 *  Created on: May 16, 2016
 *      Author: xuke
 */

#include "MariaDBManagerThread.h"

namespace basic
{
MariaDBSystem* mMariaDBSystem;
void InitTrhead(MariaDBSystem* connection)
{
	mMariaDBSystem=connection;
	pthread_t pt1=0;
	pthread_create(&pt1,NULL,Fun_ping,NULL);
}

void* Fun_ping(void * aaa)
{
	time_t mNowTime=time(NULL);
	time_t mNextTime=time(NULL);
	while(true)
	{
		if(mMariaDBSystem->GetThreadState()==true)
		{
			cout<<"Fun_ping 线程结束"<<endl;
			pthread_exit(NULL);
			break;
		}

		mNextTime=time(NULL);
		if(mNextTime-mNowTime>10)
		{
			mMariaDBSystem->Check_Ping();
			mNowTime=mNextTime;
		}
	}
	cout<<"Fun_ping 线程结束"<<endl;
}

}
