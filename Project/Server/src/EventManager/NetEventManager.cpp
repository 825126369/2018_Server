/*
 * NetEventManager1.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: xuke
 */

#include "NetEventManager.h"

namespace basic 
{

NetEventManager::NetEventManager() 
{
	NetEventReceiveDic=new map<ProtoCommand,RecFun>;
}

NetEventManager::~NetEventManager() 
{
	delete NetEventReceiveDic;
	NetEventReceiveDic=nullptr;
}

int NetEventManager::handleNetPackage(const NetEventPackage mProtobuf) const
{
	map<ProtoCommand,RecFun>::iterator iter=NetEventReceiveDic->find((ProtoCommand)mProtobuf.protobuf_command);
	if(iter!=NetEventReceiveDic->end())
	{
		(*iter).second(mProtobuf);
	}else
	{
		xk_Debug::Log()<<"protobuf command not find Event"<<endl;
	}
	return 0;
}

int NetEventManager::RegisterNetEvent(const ProtoCommand command,const RecFun Evfun) const
{
	NetEventReceiveDic->insert(pair<ProtoCommand,RecFun>(command,Evfun));	
}

int NetEventManager::Init()
{
	//1100:Chat
	RegisterNetEvent(PROTO_CHAT,Proto_Rec_Chat);
	//1101:Register Account
	RegisterNetEvent(PROTO_REGISTERACCOUNT,Proto_Recevie_RegisterAccount);
	//1102:Account Login
	RegisterNetEvent(PROTO_LOGIN,Proto_Receive_LoginGame);
	//1103:Select Server
	RegisterNetEvent(PROTO_SELECTSERVER,Proto_Receive_SelectServer);
	//1104:CreateRole
	RegisterNetEvent(PROTO_CREATEROLE,Proto_Receive_CreateRole);
	//1105:SelectRole
	RegisterNetEvent(PROTO_SELECTROLE,Proto_Receive_SelectRole);


	cout<<"Net Event Register Finish"<<endl;
	return 0;
}

} /* namespace basic */
