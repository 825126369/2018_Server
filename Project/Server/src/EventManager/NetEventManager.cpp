/*
 * NetEventManager1.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: xuke
 */

#include "NetEventManager.h"

namespace basic {

NetEventManager* NetEventManager::single=new NetEventManager;

NetEventManager::NetEventManager() {


}

NetEventManager::~NetEventManager()
{
	delete ProtoEventReceiveDic;
}


NetEventManager* NetEventManager::getSingle()
{
			if(single==0)
			{
				//lock();
				if(single==0)
				{
					single=new NetEventManager();
				}
				//unlock();
			}
			return single;
}

int NetEventManager::handleEvent(NetEventPackage mProtobuf)
{
	map<ProtoCommand,RecFun>::iterator iter=ProtoEventReceiveDic->find((ProtoCommand)mProtobuf.protobuf_command);
	if(iter!=ProtoEventReceiveDic->end())
	{
		//socket_class& client=*mClientInfo->mSocketInfo;
		(*iter).second(mProtobuf);
	}else
	{
		xk_Debug::Log()<<"protobuf command not find Event"<<endl;
	}
	return 0;
}

int NetEventManager::Init()
{
	cout<<"Net Event Register Begin"<<endl;
	ProtoEventReceiveDic=new map<ProtoCommand,RecFun>;
	//1100:Chat
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(PROTO_CHAT,Proto_Rec_Chat));
	//1101:Register Account
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(PROTO_REGISTERACCOUNT,Proto_Recevie_RegisterAccount));
	//1102:Account Login
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(PROTO_LOGIN,Proto_Receive_LoginGame));
	//1103:Select Server
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(PROTO_SELECTSERVER,Proto_Receive_SelectServer));
	//1104:CreateRole
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(PROTO_CREATEROLE,Proto_Receive_CreateRole));
	return 0;
}

} /* namespace basic */
