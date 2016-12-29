/*
 * NetManager.h
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */

#ifndef SRC_NETMANAGER_NETMANAGER_H_
#define SRC_NETMANAGER_NETMANAGER_H_
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <iostream>
#include "NetDefine.h"
#include "NetEventManager.h"
#include <cstring>
#include "EncryptionManager.h"
#include "NetThreadManager.h"
using namespace std;

namespace basic
{
class NetManager;
class ClientInfoPool;
class NetOutStream;
class Protobuf;
class NetEventPackage;
class Encryption_AES;

class NetManager {

public:
	 NetManager();
	 virtual ~NetManager();
	int Init();
	int InitNet();
	int CloseNet();
	int NetAcceptClient(socket_class& client);
	static NetManager* getSingle();
private:
	int printServerinfo(const socket_class& _socket);
private:
	struct socket_class Server;
	static NetManager single;
};

class ClientInfoPool
{
public:
	ClientInfoPool(socket_class* socket_r);
	virtual ~ClientInfoPool();
	int run();
	int SendData(int command,google::protobuf::Message* msgClass);
	int printClientinfo();
private:
	int NetReceiveMsg();
	int NetSendMsg(const unsigned char* msg,const int Length);
	int ParseData(const unsigned char* msg,const int Length);
	int CloseNet();
public:
	ClientInfo* mClientInfo;
};

class ClientManagerPool {

public:
	static ClientManagerPool* getSingle();

	int InitClient(socket_class* info);

	int AddClient(ClientInfoPool* client);

	int RemoveClient(ClientInfoPool* client);

	ClientInfoPool* GetClient(int fd);
private:
	int printClientPoolinfo();
	ClientManagerPool();
	~ClientManagerPool();

private:
	static ClientManagerPool* single;
public:
	vector<ClientInfoPool*> ClientList;
	map<int,ClientInfoPool*> ClientDic;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~数据包定义~~~~~~~~~~~~~~~~~~~~~~~~~~~
class  Package
{


};
class Protobuf:public Package
{
public:
	int protobuf_command;
	google::protobuf::Message*  protobuf_msgObj;
	int protobuf_Length;
	unsigned char* protobuf_msg;
public:
	Protobuf();
	Protobuf(int command,google::protobuf::Message* obj);
	NetOutStream SerializeMsgObj();
	int DeSerializeStream(const unsigned char* msg,int Length);

};

class NetEventPackage:public Protobuf
{
public:
	ClientInfoPool* mClient;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~网络流编码~~~~~~~~~~~~~~~~~~~~~~~~~~~
class NetEncryption
{


};
class NetEncryption_md5:NetEncryption
{


};
//~~~~~~~~~~~~~~~~~~~~~~~~~~网络流定义~~~~~~~~~~~~~~~~~~~~~~~~~~~
class NetBitStream
{


};

class NetBitFun
{

};


class NetStream:public NetBitStream
{
public:
	const int msg_head_Length=1;
	const int head_Length=10;
	const int command_Length=4;
	const int buffer_Length=4;
	const int msg_tail_Length=1;

	const char* keyStr="1234567891234567";
	const char* ivStr="1234567891234567";
	const int cipherTextLength=32;
};

class NetInputStream:public NetStream
{
public:
	NetInputStream(const unsigned char* msg,const int Length);
public:
	int command;
	unsigned char* buffer;
	int buffer_Length;



};

class NetOutStream:public NetStream
{
public:
	NetOutStream(const int command,int Length, const unsigned char* msg);
public:
	unsigned char* msg;
	int msg_Length;


};


} /* namespace basic */

#endif /* SRC_NETMANAGER_NETMANAGER_H_ */
