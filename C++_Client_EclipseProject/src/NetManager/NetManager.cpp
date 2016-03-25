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
			ParseData(ReceiveMsg);
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

int NetManager::ParseData(const char* msg)
{
	ChatInfo mChatInfo;
	mChatInfo.ParseFromArray(msg,1024);
	cout<<"解析数据："<<endl;
	cout<<mChatInfo.name()<<endl;;
	cout<<mChatInfo.content()<<endl;

	return 0;
}

int NetManager::SerializeData()
{
	char* msg;
	ChatInfo mChat;
	mChat.set_name("xuke:");
	mChat.set_content("Hello,Protobuf Serialize Data");

	mChat.SerializeToArray((void*)msg,1024);
	//NetSendMsg(msg);

	return 0;
}
int NetManager::NetSendMsg(const  char* content)
{
	int command=1100;

	ChatInfo mChat;

	mChat.set_name("xuke:");
	mChat.set_content(content);

	int Length=mChat.ByteSize();

	unsigned char msg[Length]={};
	mChat.SerializeToArray(msg,Length);

	unsigned char head[4]={};
	head[0]=command;
	head[1]=command>>8;
	head[2]=command>>16;
	head[3]=command>>24;

	cout<<"head:"<<command<<endl;
	cout<<"head:"<<head<<endl;

	unsigned char lengStr[4]={};
	lengStr[0]=Length;
	lengStr[1]=Length>>8;
	lengStr[2]=Length>>16;
	lengStr[3]=Length>>24;

	cout<<"Length:"<<Length<<endl;
	cout<<"Length:"<<lengStr<<endl;

	unsigned char mStr[Length+8]={};
	for(int i=0;i<Length+8;i++)
	{
		if(i<4)
		{
			mStr[i]=head[i];
		}else if(i>=4 && i<8)
		{
			mStr[i]=lengStr[i-4];
		}else
		{
			mStr[i]=msg[i-8];
		}

	}
	int SendLen=0;
	if((SendLen=send(client_fd,mStr,Length+8,0))==-1)
	{
		return -1;
	}
	cout<<"发送字符串长度："<<SendLen<<endl;
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

