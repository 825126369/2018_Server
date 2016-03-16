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

int NetManager::InitNet(const char* ipStr,int port,int maxConnectCout)
{
	//生成SOCKet描数字
	server_fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//Socket结构封装
	//memset((void *)&server_addr,0,sizeof(server_addr));
	server_addr.sin_addr.s_addr=inet_addr(ipStr);
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	cout<<"Socket初始化:  IP:"<<(server_addr.sin_addr.s_addr)<<"    端口："<<(server_addr.sin_port)<<endl;
	cout<<"Socket初始化:  IP:"<<inet_ntoa(server_addr.sin_addr)<<"    端口："<<(ntohs(server_addr.sin_port))<<endl;
	//把socket描数字，socket地址结构绑定
	if(bind(server_fd,(const struct sockaddr *)&server_addr,sizeof(server_addr))==-1)
	{
		cout<<"Bind error:"<<strerror(errno)<<endl;
		return -1;
	}
	if(listen(server_fd,maxConnectCout)==-1)
	{
		cout<<"Listen：Error"<<endl;
		return -1;
	}
	cout<<"服务器初始化完成"<<endl;
	return 0;
}
void NetManager::NetAcceptClient()
{
		while(2)
		{
			struct sockaddr_in mConnectHost;
			socklen_t len;
			int connect_fd;
			char* ReceiveMsg=NULL;
			cout<<"等待客户连接："<<endl;
			connect_fd=accept(server_fd,(struct sockaddr*)&mConnectHost,&len);
			cout<<"连接客户："<<endl;
			cout<<"连接客户："<<(inet_ntoa(mConnectHost.sin_addr))<<endl;

			NetSendMsg(connect_fd,"hello");

			/*ssize_t receiveMsgLength=recv(connect_fd,(void*)ReceiveMsg,1024,0);
			if(receiveMsgLength>0)
			{
				cout<<"获取的字符串是："<<ReceiveMsg<<endl;
			}*/
		}

}
void NetManager::NetReceiveMsg()
{

}

void NetManager::NetSendMsg(int client_fd,char* msg)
{
	send(client_fd,msg,1024,0);
	cout<<"发送数据："<<msg<<endl;
}
void NetManager::closeNet()
{
	shutdown(server_fd,SHUT_WR);
	//close(server_fd);
	cout<<"Socket关闭"<<endl;
}

} /* namespace basic */

