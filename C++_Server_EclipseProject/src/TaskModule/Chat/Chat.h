/*
 * Chat.h
 *
 *  Created on: Mar 23, 2016
 *      Author: xuke
 */

#ifndef SRC_TASKMODULE_CHAT_H_
#define SRC_TASKMODULE_CHAT_H_

#include "../../basicModule/NetManager/ClientManagerPool.h"
using namespace basic;

namespace ChatServer
{

class ChatServer {
public:
	ChatServer();
	virtual ~ChatServer();

	void BroastChat();

};

} /* namespace basic */

#endif /* SRC_TASKMODULE_CHAT_H_ */
