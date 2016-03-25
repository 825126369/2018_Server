/*
 * NetThreadManager.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: xuke
 */

#include "../../basicModule/NetManager/NetThreadManager.h"

namespace basic {

NetManager mNetManager=NetManager();

int NetThreadManger_Init(const char* ip,const int port,const int maxConnect)
{
	if(mNetManager.InitNet(ip,port,maxConnect)==-1)
	{
		mNetManager.CloseNet();
		return -1;
	}
	while(true)
	{
		socket_class* client=new socket_class;
		*client={};
		if(mNetManager.NetAcceptClient(*client)==-1)
		{
			continue;
		}
		if(NetThreadManager_CreateClientThread(client)==-1)
		{
			continue;
		}
	}
	mNetManager.CloseNet();

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
	ClientInfoPool* mClient=new ClientInfoPool((socket_class*)ccc);
	ClientManagerPool::getSingle()->AddClient(mClient);

	mClient->run();
	delete mClient;
	return 0;
}

}


