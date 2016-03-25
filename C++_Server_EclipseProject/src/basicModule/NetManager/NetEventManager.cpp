/*
 * NetEventManager.cpp
 *
 *  Created on: Mar 24, 2016
 *      Author: xuke
 */

#include "NetEventManager.h"

namespace basic {

NetEventManager* NetEventManager::single=new NetEventManager;

NetEventManager::NetEventManager() {


}

NetEventManager::~NetEventManager() {
	delete ProtoEventReceiveDic;
	delete ProtoEventSendDic;
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

int NetEventManager::Init()
{
	ProtoEventReceiveDic=new map<ProtoCommand,RecFun>;
	ProtoEventSendDic=new map<ProtoCommand,SendFun>;

	//1100
	ProtoEventReceiveDic->insert(pair<ProtoCommand,RecFun>(ProtoCommand_1100_,Proto_Rec_Chat));
	ProtoEventSendDic->insert(pair<ProtoCommand,SendFun>(ProtoCommand_1100_,Proto_Send_Chat));
	return 0;
}


} /* namespace basic */
