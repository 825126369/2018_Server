/*
 * NetEventManager.h
 *
 *  Created on: Mar 24, 2016
 *      Author: xuke
 */

#ifndef SRC_BASICMODULE_NETMANAGER_NETEVENTMANAGER_H_
#define SRC_BASICMODULE_NETMANAGER_NETEVENTMANAGER_H_

#include "NetProtoEvent.h"
#include <map>

using namespace std;
namespace basic {
typedef int(*RecFun)(const int fd,const int Length,const unsigned char* msg);
typedef int (*SendFun)(const void* info,unsigned char* msg,int& Length);
class NetEventManager {
public:
	int Init();
	static NetEventManager* getSingle();
private:
	NetEventManager();
	virtual ~NetEventManager();
private:
	static NetEventManager* single;
public:
	map<ProtoCommand,RecFun>* ProtoEventReceiveDic;
	map<ProtoCommand,SendFun>* ProtoEventSendDic;
};

} /* namespace basic */

#endif /* SRC_BASICMODULE_NETMANAGER_NETEVENTMANAGER_H_ */
