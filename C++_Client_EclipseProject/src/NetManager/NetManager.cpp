/*
 * NetManager.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */

#include "NetManager.h"
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cerrno>
using namespace std;

namespace basic {

NetManager::NetManager() {
	// TODO Auto-generated constructor stub
}

NetManager::~NetManager() {
	// TODO Auto-generated destructor stub
}

int NetManager::InitNet(const char* ipStr,const int port)
{
	//生成SOCKet描数字
	client_fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//Socket结构封装
	//memset((void *)&client_addr,0,sizeof(client_addr));
	client_addr.sin_addr.s_addr=inet_addr(ipStr);
	client_addr.sin_family=AF_INET;
	client_addr.sin_port=htons(port);
	cout<<"连接服务器:  IP:"<<inet_ntoa(client_addr.sin_addr)<<"  端口："<<ntohs(client_addr.sin_port)<<endl;

	cout<<"客户端Socket初始化完毕"<<endl;
}
int NetManager::NetConnectServer()
{
			cout<<"正在连接服务器："<<endl;
			if(connect(client_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))==-1)
			{
					cout<<"连接服务器失败:"<<strerror(errno)<<endl;
					return -1;
			}
			cout<<"连接服务器成功:"<<inet_ntoa(client_addr.sin_addr)<<endl;

			NetProcessManager();
			return 0;
}
int NetManager::NetProcessManager()
{
	pid_t mchild_pid=fork();
			if(mchild_pid==0)
			{
				NetReceiveMsg();
			}else
			{
				while(true)
				{
					char buf[1024];
					cout<<">:";
					cin>>buf;
					buf[1024]='\0';
					NetSendMsg(buf);
				}
			}

}
int NetManager::NetReceiveMsg()
{
	while(3)
	{
		char ReceiveMsg[1024];
		ssize_t receiveMsgLength=recv(client_fd,(void*)ReceiveMsg,1024,0);
		if(receiveMsgLength>0)
		{
			cout<<"获取的字符串是："<<ReceiveMsg<<endl;
		}else if(receiveMsgLength==0)
		{
			closeNet();
			break;
		}else
		{
			cout<<"Rev Error："<<errno<<endl;
			return -1;
		}
	}
	return 0;
}
int NetManager::NetSendMsg(char* msg)
{
	if(send(client_fd,msg,1024,0)==-1)
	{
		return -1;
	}
	return 0;
}

int NetManager::closeNet()
{
	if(close(client_fd)==-1)
	{
		return -1;
	}
	cout<<"客户端Socket关闭"<<endl;
	return 0;
}

} /* namespace basic */

