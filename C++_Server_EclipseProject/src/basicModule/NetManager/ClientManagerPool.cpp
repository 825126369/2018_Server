/*
 * ClientManagerPool.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: xuke
 */

#include "ClientManagerPool.h"

namespace basic {

ClientManagerPool* ClientManagerPool::single=new ClientManagerPool;

ClientManagerPool::ClientManagerPool() {



}

ClientManagerPool::~ClientManagerPool() {
	delete single;

}

ClientManagerPool* ClientManagerPool:: getSingle()
{
		if(single==NULL)
		{
			//lock();
			if(single=NULL)
			{
				single=new ClientManagerPool();
			}
			//unlock();
		}
		return single;
}

int ClientManagerPool::AddClient(const ClientInfoPool* client)
{
	ClientList.push_back(*client);
	ClientDic.insert(pair<int,ClientInfoPool>(client->mClientInfo->mSocketInfo->_fd,*client));
	return 0;
}
int ClientManagerPool::RemoveClient(const ClientInfoPool& client)
{
	for(vector<ClientInfoPool>::iterator iter=ClientList.begin();ClientList.begin()!=ClientList.end();)
	{
		if((*iter).mClientInfo->mSocketInfo->_fd==client.mClientInfo->mSocketInfo->_fd)
		{
			ClientList.erase(iter);
		}else
		{
			iter++;
		}
	}
	return 0;
}

ClientInfoPool* ClientManagerPool::GetClient(int _fd)
{
		map<int,ClientInfoPool>::iterator iter=ClientDic.find(_fd);
		if(iter!=ClientDic.end())
		{
			return &((*iter).second);
		}
		return 0;
}

} /* namespace basic */
