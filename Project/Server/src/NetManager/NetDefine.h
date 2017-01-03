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
#include "../MariaDBManager/MariaDBSystem.h"
namespace basic
{
class NetPackageReceivePool;
struct  socket_class
{
		struct sockaddr_in  _addr;
		int _fd;
};
class ClientInfo
{
public:
	socket_class* mSocketInfo;
	DbTableManager mDbManager;
	~ClientInfo();

};




struct DataInfo
{
		int fd;
		char* Msg;
};

}
#endif /* SRC_NETMANAGER_NETDEFINE_H_ */
