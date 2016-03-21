/*
 * NetUtility.h
 *
 *  Created on: Mar 18, 2016
 *      Author: xuke
 */

#ifndef SRC_NETMANAGER_NETUTILITY_H_
#define SRC_NETMANAGER_NETUTILITY_H_

#include "NetDefine.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
namespace basic {

class NetUtility {
public:
	NetUtility();
	virtual ~NetUtility();
	static void printServerinfo(const socket_class& _socket);
	static void printClientinfo(const socket_class& _socket);
	static void printClientPoolinfo(const vector<socket_class>& list);
	static void removeClientinfo(vector<socket_class>& list,socket_class client);
};

} /* namespace basic */

#endif /* SRC_NETMANAGER_NETUTILITY_H_ */
