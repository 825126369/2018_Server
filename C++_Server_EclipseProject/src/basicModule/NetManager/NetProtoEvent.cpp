/*
 * NetProtoEvent.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: xuke
 */

#include "NetProtoEvent.h"
//1100
int Proto_Rec_Chat(const int fd,const int Length,const unsigned char* msg)
{
	ChatInfo mChatinfo;
	mChatinfo.ParseFromArray(msg,Length);
	xk_Debug::Log("解析数据：");
	xk_Debug::Log(mChatinfo.name());
	xk_Debug::Log(mChatinfo.content());

	ClientInfoPool* client= ClientManagerPool::getSingle()->GetClient(fd);

	if(client!=0)
	{
		ChatInfo* mCha=new ChatInfo;
		mCha->set_name("dfdf");
		client->SendData(1100,mCha);
	}else
	{

	}
	return 0;
}
int Proto_Send_Chat(const void* info,unsigned char* msg,int& Length)
{
		ChatInfo* mChat=(ChatInfo*)info;
		Length=mChat->ByteSize();
		msg=new unsigned char[Length];
		mChat->SerializeToArray(msg,Length);
		return 0;
}



