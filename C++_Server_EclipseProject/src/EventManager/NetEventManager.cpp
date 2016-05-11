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

NetEventManager::~NetEventManager() {
	delete ProtoEventReceiveDic;
	//delete ProtoEventSendDic;
	delete single;
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
		xk_Debug::Log()<<"没有找到接收命令"<<endl;
	}
	return 0;
}

int NetEventManager::Init()
{
	ProtoEventReceiveDic=new map<ProtoCommand,RecFun>;
	//ProtoEventSendDic=new map<ProtoCommand,SendFun>;

	//1100
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(Chat,Proto_Rec_Chat));
	//1101:注册账号
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(RegisterAccount,Proto_Recevie_RegisterAccount));
	//1102
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(Login,Proto_Receive_LoginGame));
	return 0;
}

} /* namespace basic */
