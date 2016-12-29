/*
 * NetEventManager1.h
 *
 *  Created on: Apr 7, 2016
 *      Author: xuke
 */

#ifndef SRC_EVENTMANAGER_NETEVENTMANAGER_H_
#define SRC_EVENTMANAGER_NETEVENTMANAGER_H_
#include "NetProtoEvent.h"
namespace basic {
class NetEventPackage;
//typedef int(*RecFun)(const int fd,const int Length,const unsigned char* msg);
typedef int(*RecFun)(const NetEventPackage);
//typedef int (*SendFun)(const google::protobuf::Message* info,unsigned char* msg,int& Length);
class NetEventManager {
public:
	int Init();
	int handleEvent(NetEventPackage mProtobuf);
	static NetEventManager* getSingle();
private:
	NetEventManager();
	virtual ~NetEventManager();
private:
	static NetEventManager* single;
	//map<ProtoCommand,SendFun> *ProtoEventSendDic;
	map<ProtoCommand,RecFun> *ProtoEventReceiveDic;
};

} /* namespace basic */

#endif /* SRC_EVENTMANAGER_NETEVENTMANAGER_H_ */
