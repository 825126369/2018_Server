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
#include "../MariaDBManager/DbTable.h"
namespace basic
{

class NetEventPackage;
//1100协议
int Proto_Rec_Chat(const NetEventPackage mProtobuf);
//1101注册账号
int Proto_Recevie_RegisterAccount(const NetEventPackage mProtobuf);
//1102 登陆账号
int Proto_Receive_LoginGame(const NetEventPackage mProtobuf);
//1103	获取服务器列表
int Proto_Receive_ServerList(const NetEventPackage mProtobuf);
//1104	进入游戏
int Proto_Receive_EnterGame(const NetEventPackage mProtobuf);
}

#endif /* SRC_BASICMODULE_NETMANAGER_NETPROTOEVENT_H_ */
