/*
 * NetManager.h
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */

#ifndef SRC_NETMANAGER_NETMANAGER_H_
#define SRC_NETMANAGER_NETMANAGER_H_
#include <sys/socket.h>
#include <netinet/in.h>
#include "../Proto.cpp/test.pb.h"
namespace basic {

class NetManager {
public:
	NetManager();
	virtual ~NetManager();
	int InitNet(const char* ipStr,const int port);
	int closeNet();
	int NetConnectServer();
	int NetReceiveMsg();
	int NetSendMsg(const  char* msg);
	int NetProcessManager();
	int SerializeData();
	int ParseData(const char* msg);


private:
	struct sockaddr_in  client_addr;
	int client_fd;

};

} /* namespace basic */

#endif /* SRC_NETMANAGER_NETMANAGER_H_ */
