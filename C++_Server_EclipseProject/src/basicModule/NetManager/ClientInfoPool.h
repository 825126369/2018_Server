/*
 * ClientInfoPool.h
 *	function:
 *	1：主要为了开辟的读，写客户线程，提供共享数据
 *	2：封包，解包
 *  Created on: Mar 22, 2016
 *      Author: xuke
 */

#ifndef SRC_NETMANAGER_CLIENTINFOPOOL_H_
#define SRC_NETMANAGER_CLIENTINFOPOOL_H_
#include <unistd.h>
#include <bitset>
#include <cstdlib>
#include "NetEventManager.h"
#include "../../basicModule/NetManager/NetDefine.h"
#include "../../basicModule/NetManager/NetUtility.h"
#include "../../Protobuf/Proto.cpp/test.pb.h"
namespace basic {

class ClientInfoPool {
public:
	ClientInfoPool(socket_class* socket_r);
	virtual ~ClientInfoPool();
	int run();
	int NetReceiveMsg();
	int NetSendMsg(const unsigned char* msg);
	int ParseData(const unsigned char* msg);
	int ParseCommand(int command,int Length,unsigned char* content);
	int SendData(int command,void* msgClass);

public:
	ClientInfo* mClientInfo;




};

} /* namespace basic */

#endif /* SRC_NETMANAGER_CLIENTINFOPOOL_H_ */
