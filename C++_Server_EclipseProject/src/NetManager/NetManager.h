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
namespace basic {

class NetManager {
public:
	NetManager();
	virtual ~NetManager();
	int InitNet(const char* ipStr,int port,int maxConnectCout);
	void closeNet();
	void NetAcceptClient();
	void NetReceiveMsg();
	void NetSendMsg();
	void NetSendMsg(int client_fd,char* msg);



private:
	struct sockaddr_in  server_addr;
	int server_fd;

};

} /* namespace basic */

#endif /* SRC_NETMANAGER_NETMANAGER_H_ */
