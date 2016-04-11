/*
 * NetProtoEvent.h
 *
 *  Created on: Mar 25, 2016
 *      Author: xuke
 */

#ifndef SRC_BASICMODULE_NETMANAGER_NETPROTOEVENT_H_
#define SRC_BASICMODULE_NETMANAGER_NETPROTOEVENT_H_

#include "../Protobuf/Proto.cpp/proto_command.pb.h"
#include "../Protobuf/Proto.cpp/proto_message_one.pb.h"
#include "../Protobuf/Proto.cpp/proto_message_two.pb.h"
#include "../Protobuf/Proto.cpp/proto_struct.pb.h"
#include "../DebugManager/xkDebug.h"
#include "../NetManager/NetManager.h"
namespace basic
{

class NetEventPackage;
//1001协议
int Proto_Rec_Chat(const NetEventPackage mProtobuf);

}

#endif /* SRC_BASICMODULE_NETMANAGER_NETPROTOEVENT_H_ */
