/*
 * NetProtoEvent.h
 *
 *  Created on: Mar 25, 2016
 *      Author: xuke
 */

#ifndef SRC_BASICMODULE_NETMANAGER_NETPROTOEVENT_H_
#define SRC_BASICMODULE_NETMANAGER_NETPROTOEVENT_H_

#include "../../Protobuf/Proto.cpp/test.pb.h"
#include "../xk_basic/xkDebug.h"
#include "NetCommand.h"
#include "ClientManagerPool.h"

using namespace basic;
//1001协议
int Proto_Rec_Chat(const int fd,const int Length,const unsigned char* msg);
int Proto_Send_Chat(const void* info,unsigned char* msg,int& Length);



#endif /* SRC_BASICMODULE_NETMANAGER_NETPROTOEVENT_H_ */
