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
	//1100
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(Chat,Proto_Rec_Chat));
	//1101:注册账号
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(RegisterAccount,Proto_Recevie_RegisterAccount));
	//1102:登陆账户
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(Login,Proto_Receive_LoginGame));
	//1103：得到服务器列表
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(SelectServer,Proto_Receive_ServerList));
	//1104：进入游戏服务器
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(EnterGame,Proto_Receive_EnterGame));
	return 0;
}

} /* namespace basic */
