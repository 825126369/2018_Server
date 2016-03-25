/*
 * NetUtility.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: xuke
 */

#include "../../basicModule/NetManager/NetUtility.h"
namespace basic {

NetUtility::NetUtility() {
	// TODO Auto-generated constructor stub

}

NetUtility::~NetUtility() {
	// TODO Auto-generated destructor stub
}

void NetUtility::printServerinfo(const socket_class& _socket)
{
	//cout<<"Socket Net:  IP:"<<(_socket._addr.sin_addr.s_addr)<<"    端口："<<(_socket._addr.sin_port)<<endl;
	//cout<<"Socket Local: IP:"<<inet_ntoa(_socket._addr.sin_addr)<<"    端口："<<(ntohs(_socket._addr.sin_port))<<endl;
	cout<<"Server:  描数字："<<_socket._fd<<"  IP:"<<inet_ntoa(_socket._addr.sin_addr)<<"    端口："<<(ntohs(_socket._addr.sin_port))<<endl;
}

void NetUtility::printClientinfo(const socket_class& _socket)
{
	//cout<<"Socket Net:  IP:"<<(_socket._addr.sin_addr.s_addr)<<"    端口："<<(_socket._addr.sin_port)<<endl;
	//cout<<"Socket Local: IP:"<<inet_ntoa(_socket._addr.sin_addr)<<"    端口："<<(ntohs(_socket._addr.sin_port))<<endl;
	cout<<"Client:  描数字："<<_socket._fd<<"  IP:"<<inet_ntoa(_socket._addr.sin_addr)<<"    端口："<<(ntohs(_socket._addr.sin_port))<<endl;
}

void NetUtility::printClientPoolinfo(const vector<socket_class>& list)
{
	cout<<"客户连接池信息："<<endl;
	for_each(list.begin(),list.end(),printClientinfo);
	cout<<"池容量："<<list.capacity()<<endl;
	cout<<"池客户数量："<<list.size()<<endl;
}
void NetUtility::removeClientinfo(vector<socket_class>& list,socket_class client)
{
	vector<socket_class>::iterator iter=list.begin();
	while(iter!=list.end())
	{
		if((*iter)._fd==client._fd)
		{
			iter=list.erase(iter);
		}else
		{
			iter++;
		}
	}
}



} /* namespace basic */
