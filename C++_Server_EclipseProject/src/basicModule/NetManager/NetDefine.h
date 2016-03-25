/*
 * NetDefine.h
 *定义各种有关网络数据结构
 *  Created on: Mar 18, 2016
 *      Author: xuke
 */

#ifndef SRC_NETMANAGER_NETDEFINE_H_
#define SRC_NETMANAGER_NETDEFINE_H_

#include <sys/socket.h>
#include <netinet/in.h>

#include "../../basicModule/xk_basic/xkDebug.h"
namespace basic
{
struct  socket_class
{
	public:
		struct sockaddr_in  _addr;
		int _fd;
};
struct ClientInfo
{
public:
	socket_class* mSocketInfo;

};


struct DataInfo
{
	public:
		int fd;
		char* Msg;
};

}
#endif /* SRC_NETMANAGER_NETDEFINE_H_ */
