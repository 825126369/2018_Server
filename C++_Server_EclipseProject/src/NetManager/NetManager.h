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
#include <vector>
#include "NetDefine.h"
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cerrno>
#include <cstdlib>
#include "NetUtility.h"
#include <cstdio>
#include <queue>
using namespace std;
namespace basic {

class NetManager {
public:
	 NetManager();
	 virtual ~NetManager();

	int InitNet(const char* ipStr,const int port,const int maxConnectCout);
	int CloseNet();
	int NetAcceptClient(socket_class& client);
	int NetReceiveMsg(const socket_class& client);
	int NetSendMsg(const socket_class& client,const char* msg);


private:
	socket_class Server;
	vector<socket_class> client_list;
};

} /* namespace basic */

#endif /* SRC_NETMANAGER_NETMANAGER_H_ */
