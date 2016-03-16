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

void NetManager::InitNet(const char* ipStr,const int port)
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
void NetManager::NetConnectServer()
{
			cout<<"正在连接服务器："<<endl;
			if(connect(client_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))==-1)
			{
					cout<<"连接服务器失败:"<<strerror(errno)<<endl;
					return;
			}
			cout<<"连接服务器成功:"<<inet_ntoa(client_addr.sin_addr)<<endl;

			NetReceiveMsg();
			//NetSendMsg(connect_fd,ReceiveMsg);

}
void NetManager::NetReceiveMsg()
{
	char ReceiveMsg[1024];
	ssize_t receiveMsgLength=recv(client_fd,(void*)ReceiveMsg,1024,0);
	cout<<"获取的字符串是："<<ReceiveMsg<<endl;
}
void NetManager::NetSendMsg(char* msg)
{
	send(client_fd,msg,1024,0);
}
void NetManager::NetSendMsg(int client_fd,char* msg)
{
	send(client_fd,msg,1024,0);
}
void NetManager::closeNet()
{
	//close(client_fd);
	cout<<"客户端Socket关闭"<<endl;
}

} /* namespace basic */

