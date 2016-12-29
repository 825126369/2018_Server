/*
 * NetThreadManager.h
 *
 *  Created on: Mar 20, 2016
 *      Author: xuke
 */

#ifndef SRC_NETMANAGER_NETTHREADMANAGER_H_
#define SRC_NETMANAGER_NETTHREADMANAGER_H_

#include <pthread.h>
#include "NetManager.h"
using namespace std;
namespace basic
{
class NetManager;
int NetThreadManger_Init(NetManager* nm);
void* NetThreadManager_ReceiveMsg(void* ccc);
int NetThreadManager_CreateClientThread(socket_class* client);
}



#endif /* SRC_NETMANAGER_NETTHREADMANAGER_H_ */
