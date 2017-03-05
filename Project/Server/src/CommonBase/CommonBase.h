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
#include <mutex>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;
namespace basic {

class Thread_Lock
{
private:
	pthread_rwlock_t  m_Lock;
public:
    Thread_Lock()
    {
    	if(pthread_rwlock_init(&m_Lock,NULL)==-1)
    	{
    		cout<<"mutex init error"<<endl;
    	}
    }

    void Lock()
	{
		pthread_rwlock_wrlock(&m_Lock); 		
	}
    void unLock()
	{
		pthread_rwlock_unlock(&m_Lock); 
	}
};

template<typename T>
class Singleton
{
protected:
	Singleton()=default;
	~Singleton()=default;
	Singleton(Singleton&& s)=default;
	Singleton(const Singleton& s)=default;
	Singleton& operator=(Singleton&& s)=default;
	Singleton& operator=(const Singleton& s)=default;		
private:
	friend class CleanUp;
	class CleanUp
	{
		public:
			~CleanUp()
			{
				cout<<"CleanUp delete singleton"<<endl;	
				lock_guard<mutex> guard(Singleton::sMutex);
				delete pInstance;
				pInstance=nullptr;
			}
	};
public:
	static T* getSingle()
	{
		lock_guard<mutex> guard(sMutex);	
		static CleanUp cleanup;	
		static T single;
		return &single;
	}

	static T* Instance()
	{
		lock_guard<mutex> guard(sMutex);	
		static CleanUp cleanup;
		if(pInstance==NULL)
		{
			pInstance=new T();
		}
		return pInstance;
	}
private:
	static std::mutex sMutex;
	static T* pInstance;
};

template<typename T>
T* Singleton<T>::pInstance=nullptr;
template<typename T>
std::mutex Singleton<T>::sMutex;

#define TimeZone "China"
class TimeManager:public Singleton<TimeManager>
{
private:
	TimeManager()=default;
	friend class Singleton<TimeManager>;
public:
	time_t getTime()
	{
		return time(NULL);
	}

	string getTodayTime()
	{
		time_t ts=time(NULL);	
		if(strcmp(TimeZone,"China"))
		{
			struct tm* timeinfo=localtime(&ts);	
			return to_string(timeinfo->tm_hour)+":"+to_string(timeinfo->tm_min)+":"+to_string(timeinfo->tm_sec);
		}else
		{
			struct tm* timeinfo=gmtime(&ts);
			return asctime(timeinfo);
		}
	}

	string getFullTime()
	{
		time_t ts=time(NULL);	
		if(strcmp(TimeZone,"China"))
		{	
			struct tm* timeinfo=localtime(&ts);	
			return asctime(timeinfo);
		}else
		{
			struct tm* timeinfo=gmtime(&ts);
			return asctime(timeinfo);
		}
	}
};

class RandomManager:public Singleton<RandomManager>
{
private:
	RandomManager()=default;
	friend class Singleton<RandomManager>;
public:
	template<typename T>
	T getRandom(T min, T max)
	{
		srand(static_cast<unsigned int>(time(nullptr)));	
		return (rand() % static_cast<T>(max + 1 - min)) + min;
	}
};
} /* namespace basic */



#endif /* SRC_COMMONBASE_COMMONBASE_H_ */
