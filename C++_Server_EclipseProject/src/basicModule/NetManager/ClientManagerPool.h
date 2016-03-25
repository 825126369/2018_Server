/*
 * ClientManagerPool.h
 *
 *  Created on: Mar 23, 2016
 *      Author: xuke
 */

#ifndef SRC_NETMANAGER_CLIENTMANAGERPOOL_H_
#define SRC_NETMANAGER_CLIENTMANAGERPOOL_H_
#include <vector>
#include "ClientInfoPool.h"

namespace basic {
class ClientInfoPool;
class ClientManagerPool {

public:
	static ClientManagerPool* getSingle();

	int AddClient(const ClientInfoPool* client);

	int RemoveClient(const ClientInfoPool& client);

	ClientInfoPool* GetClient(int _fd);
private:
	ClientManagerPool();
	~ClientManagerPool();

private:
	static ClientManagerPool* single;
public:
	vector<ClientInfoPool> ClientList;
	map<int,ClientInfoPool> ClientDic;
};

} /* namespace basic */

#endif /* SRC_NETMANAGER_CLIENTMANAGERPOOL_H_ */
