/*
 * CommonBase.h
 *
 *  Created on: Jun 9, 2016
 *      Author: xuke
 */

#ifndef SRC_COMMONBASE_COMMONBASE_H_
#define SRC_COMMONBASE_COMMONBASE_H_
#include "pthread.h"
#include <iostream>
using namespace std;
namespace basic {
class LockManager
{
private:
	pthread_rwlock_t  m_cs;
public:
    LockManager()
    {
    	if(pthread_rwlock_init(&m_cs,NULL)==-1)
    	{
    		cout<<"客户池 互斥锁初始化失败"<<endl;
    	}
    }

    void Lock();
    void unLock();
};
template<typename T>
class Singleton
{
private:
	Singleton();
public:
	static T* getSingle()
	{
		static T single;
		return &single;
	}
};

} /* namespace basic */

#endif /* SRC_COMMONBASE_COMMONBASE_H_ */
