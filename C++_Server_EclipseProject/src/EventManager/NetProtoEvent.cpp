/*
 * NetProtoEvent.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: xuke
 */

#include "NetProtoEvent.h"

namespace basic
{

//1100
int Proto_Rec_Chat(const NetEventPackage mProtobuf)
{
	ClientSendData mChatinfo;
	mChatinfo.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	xk_Debug::Log()<<"解析数据："<<mChatinfo.sendername()<<" | "<<mChatinfo.talkmsg()<<endl;


	if(mProtobuf.mClient!=0)
	{
		ServerSendData mdata=ServerSendData();
		mdata.set_nickname("server");
		mdata.set_talkmsg("shou dao");
		mProtobuf.mClient->SendData((int)Chat,&mdata);
	}else
	{
		xk_Debug::Log()<<"事件发送者不存在"<<endl;
	}
	return 0;
}
int Proto_Send_Chat(const google::protobuf::Message* info,unsigned char* msg,int& Length)
{
	info->ByteSize();
	info->SerializeToArray(msg,Length);
		ServerSendData* mChat=(ServerSendData*)info;
		Length=mChat->ByteSize();
		msg=new unsigned char[Length];
		mChat->SerializeToArray(msg,Length);
		return 0;
}


}
