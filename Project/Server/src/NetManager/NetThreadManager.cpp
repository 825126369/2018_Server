/*

 * NetThreadManager.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: xuke
 */

#include "NetThreadManager.h"

namespace basic {

NetManager* mNetManager;

int NetThreadManger_Init(NetManager* mNetManagerPtr)
{
	mNetManager=mNetManagerPtr;
	while(true)
	{
		socket_class* client=new socket_class;
		*client={};
		if(mNetManager->NetAcceptClient(*client)==-1)
		{
			continue;
		}
		if(NetThreadManager_CreateClientThread(client)==-1)
		{
			continue;
		}
	}
	mNetManager->CloseNet();
	return 0;
}
int NetThreadManager_CreateClientThread(socket_class* client)
{
	pthread_t pr={};
	if(pthread_create(&pr,NULL,NetThreadManager_ReceiveMsg,client)==-1)
	{
		xk_Debug::LogSystemError("Create Client Thread Error:");
		delete client;
		return -1;
	};
	return 0;
}
void* NetThreadManager_ReceiveMsg(void* ccc)
{
	ClientManagerPool::getSingle()->InitClient((socket_class*)ccc);
	return 0;
}

}


