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
	void InitNet(const char* ipStr,const int port);
	void closeNet();
	void NetConnectServer();
	void NetReceiveMsg();
	void NetSendMsg(char* msg);
	void NetSendMsg(int client_fd,char* msg);



private:
	struct sockaddr_in  client_addr;
	int client_fd;

};

} /* namespace basic */

#endif /* SRC_NETMANAGER_NETMANAGER_H_ */
