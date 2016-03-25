/*
 * ClientInfoPool.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: xuke
 */

#include "../../basicModule/NetManager/ClientInfoPool.h"

namespace basic {

ClientInfoPool::ClientInfoPool(socket_class* socket_r)
{
	mClientInfo=new ClientInfo();
	mClientInfo->mSocketInfo=socket_r;
}

ClientInfoPool::~ClientInfoPool() {
	delete mClientInfo->mSocketInfo;
}
int ClientInfoPool::run()
{
	NetReceiveMsg();
	return 0;
}

int ClientInfoPool::NetReceiveMsg()
{
	const socket_class& client=*(mClientInfo->mSocketInfo);
	xk_Debug::Log("Client Connect Success：");
	NetUtility::printClientinfo(client);
	//client_list.push_back(client);
	//NetUtility::printClientPoolinfo(client_list);
	while(3)
	{
		unsigned char msg[1024]={};
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
			//NetUtility::removeClientinfo(client_list,client);
			//NetUtility::printClientPoolinfo(client_list);
			break;
		}else if(receiveMsgLength>0)
		{
			xk_Debug::Log("Get Data Length：");
			//cout<<receiveMsgLength<<endl;
			//xk_Debug::Log(msg);
			ParseData(msg);
		}

	}
	return 0;
}

int ClientInfoPool::ParseData(const unsigned char* msg)
{
	int command={};
	command=(msg[3]<<24 | msg[2]<<16 | msg[1]<<8 | msg[0]);
	cout<<"命令："<<command<<endl;

	int Length={};
	Length=msg[7]<<24 | msg[6]<<16 | msg[5]<<8 | msg[4];
	cout<<"protobuf Length："<<Length<<endl;


	unsigned char content[Length]={};
	for(int i=8;i<8+Length;i++)
	{
		content[i-8]=msg[i];
	}

	ParseCommand(command,Length,content);
	return 0;
}

int ClientInfoPool::ParseCommand(int command,int Length,unsigned char* content)
{
	map<ProtoCommand,RecFun>* mDic=NetEventManager::getSingle()->ProtoEventReceiveDic;
	map<ProtoCommand,RecFun>::iterator iter=mDic->find((ProtoCommand)command);
	if(iter!=mDic->end())
	{
		socket_class& client=*mClientInfo->mSocketInfo;
		(*iter).second(client._fd,Length,content);
	}else
	{
		xk_Debug::Log("没有找到接收命令");
	}

}

int ClientInfoPool::SendData(int command,void* msgClass)
{
		int Length=0;
		unsigned char* msg={};
		map<ProtoCommand,SendFun>* mDic=NetEventManager::getSingle()->ProtoEventSendDic;
		map<ProtoCommand,SendFun>::iterator iter=mDic->find((ProtoCommand)command);
		if(iter!=mDic->end())
		{
			(*iter).second(msgClass,msg,Length);
		}else
		{
			xk_Debug::Log("没有找到发送命令");
			return -1;
		}
	unsigned char head[4]={};
	head[0]=command;
	head[1]=command>>8;
	head[2]=command>>16;
	head[3]=command>>24;


	unsigned char lengStr[4]={};
	lengStr[0]=Length;
	lengStr[1]=Length>>8;
	lengStr[2]=Length>>16;
	lengStr[3]=Length>>24;

	const int sumLength=8+Length;
	unsigned char mStr[sumLength]={};
	for(int i=0;i<sumLength;i++)
	{
		if(i<4)
		{
			mStr[i]=head[i];
		}else if(i>=4 && i<8)
		{
			mStr[i]=lengStr[i]=lengStr[i-4];
		}else
		{
			mStr[i]=msg[i-8];
		}

	}
	NetSendMsg(mStr);
	return 0;
}

int ClientInfoPool::NetSendMsg(const unsigned char* msg)
{
	const socket_class& client=*mClientInfo->mSocketInfo;
	xk_Debug::Log("Send :");
	if(send(client._fd,msg,1024,0)==-1)
	{
		xk_Debug::LogSystemError("Send Error:");
		return -1;
	}
	//xk_Debug::Log(2,"Send Data：",msg);
	return 0;
}




} /* namespace basic */
