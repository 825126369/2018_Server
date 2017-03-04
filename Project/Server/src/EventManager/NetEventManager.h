/*
 * NetEventManager1.h
 *
 *  Created on: Apr 7, 2016
 *      Author: xuke
 */

#ifndef SRC_EVENTMANAGER_NETEVENTMANAGER_H_
#define SRC_EVENTMANAGER_NETEVENTMANAGER_H_
#include "CommonBase.h"
#include "NetProtoEvent.h"
using namespace xk_protobuf_data;
namespace basic
{
class NetEventPackage;
typedef int(*RecFun)(const NetEventPackage);
class NetEventManager:public Singleton<NetEventManager>
{
public:
	int Init();
	int RegisterNetEvent(const ProtoCommand command,const RecFun Evfun) const;
	int handleNetPackage(const NetEventPackage mProtobuf) const;
	~NetEventManager();
private:
	friend class Singleton<NetEventManager>;
	NetEventManager();
private:
	map<ProtoCommand,RecFun>* NetEventReceiveDic;
};

} /* namespace basic */

#endif /* SRC_EVENTMANAGER_NETEVENTMANAGER_H_ */
