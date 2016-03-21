/*
 * NetManager.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */

#include "NetManager.h"

namespace basic {

NetManager::NetManager() {
	// TODO Auto-generated constructor stub
}

NetManager::~NetManager() {
	// TODO Auto-generated destructor stub
}

int NetManager::InitNet(const char* ipStr,const int port,const int maxConnectCout)
{
	Server={};
	//memset(&Server,0,sizeof(Server));
	//生成SOCKet描数字
	if((Server._fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
	{
		xk_Debug::LogSystemError("Init Server_fd Error:");
		return -1;
	}
	/*int reuse=1;
    if (setsockopt(Server._fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse))==-1)
    {
            perror("setsockopet error:");
            return -1;
    }*/
	//Socket结构封装
	Server._addr.sin_addr.s_addr=inet_addr(ipStr);
   // Server._addr.sin_addr.s_addr=INADDR_ANY;
	Server._addr.sin_family=AF_INET;
	Server._addr.sin_port=htons(port);
	NetUtility::printServerinfo(Server);
	//把socket描数字，socket地址结构绑定
	if(bind(Server._fd,(const struct sockaddr *)&Server._addr,sizeof(Server._addr))==-1)
	{
		xk_Debug::LogSystemError("Bind error:");
		return -1;
	}
	if(listen(Server._fd,maxConnectCout)==-1)
	{
		xk_Debug::LogSystemError("Listen Error:");
		return -1;
	}
	xk_Debug::Log("服务器初始化完成");
	return 0;
}

int NetManager::NetAcceptClient(socket_class& client)
{
		socklen_t len;
		if((client._fd=accept(Server._fd,(struct sockaddr*)&(client._addr),&len))==-1)
		{
			xk_Debug::LogSystemError("Accept Error:");
			return -1;
		}
		return 0;
}

int NetManager::NetReceiveMsg(const socket_class& client)
{
	xk_Debug::Log("连接客户成功：");
	NetUtility::printClientinfo(client);
	client_list.push_back(client);
	NetUtility::printClientPoolinfo(client_list);
	while(3)
	{
		char msg[1024]={};
		ssize_t receiveMsgLength=recv(client._fd,&msg,1024,0);
		if(receiveMsgLength==-1)
		{
			xk_Debug::LogSystemError("NetReceiveMsg Error:");
			return -1;
		}else if(receiveMsgLength==0)
		{
			if(close(client._fd)==-1)
			{
				xk_Debug::LogSystemError("Client Close Error:");
			}
			xk_Debug::Log("client DisConnected： ");
			NetUtility::printClientinfo(client);
			NetUtility::removeClientinfo(client_list,client);
			NetUtility::printClientPoolinfo(client_list);
			break;
		}else if(receiveMsgLength>0)
		{
			xk_Debug::Log(2,"Get Data：",msg);
			NetSendMsg(client,"ThansYou");
		}

	}
	return 0;
}

int NetManager::NetSendMsg(const socket_class& client,const char* msg)
{
	if(send(client._fd,msg,1024,0)==-1)
	{
		xk_Debug::LogSystemError("Send Error:");
		return -1;
	}
	xk_Debug::Log(2,"Send Data：",msg);
	return 0;
}
//成功则返回0，错误返回-1
int NetManager::CloseNet()
{
	//shutdown(server_fd,SHUT_WR);
	if(close(Server._fd)==-1)
	{
		xk_Debug::LogSystemError("Close Server Error:");
		return -1;
	}
	xk_Debug::Log("Server Closed");
	return 0;
}

} /* namespace basic */

