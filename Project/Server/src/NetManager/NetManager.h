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
#include "EncryptionManager.h":
#include "libev_NetManager.h"
using namespace std;
namespace basic
{
class NetManager;
class ClientInfoPool;
class NetOutStream;
class Protobuf;
class NetEventPackage;
class Encryption_AES;
class NetEncryptionInputStream;
class NetEncryptionOutStream;
class NetEncryptionStream;
class NetManager {

public:
	virtual ~NetManager();
	int Init();
	struct socket_class getServerSocketInfo();
	int CloseNet();
	int NetAcceptClient_Block(socket_class& client);
	int NetAcceptClient_NoBlock(socket_class& client);
	static NetManager* getSingle();
private:
	NetManager();
	int InitNet();
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
	int NetReceiveMsg_Block();
	int NetReceiveMsg_NoBlock();
	int NetSendMsg_Block(const unsigned char* msg,const int Length);
	int NetSendMsg_NoBlock(const unsigned char* msg,const int Length);
	int PackagePoolParseData(const unsigned char* msg,int msg_Length);
	int ParseData(const unsigned char* msg,const int Length);
	int CloseNet();
public:
	ClientInfo* mClientInfo;
private:
	NetPackageReceivePool* mNetPackageReceivePool;
};

class ClientManagerPool {

public:
	static ClientManagerPool* getSingle();

	int InitClient(socket_class* info);

	int AddClient(ClientInfoPool* client);

	int RemoveClient(ClientInfoPool* client);

	ClientInfoPool* GetClient(int fd);

	vector<ClientInfoPool*> GetClientPool();
private:
	int printClientPoolinfo();
	int InitLock();
	ClientManagerPool();
	~ClientManagerPool();

private:
	static ClientManagerPool* single;
	pthread_rwlock_t m_mutex_ClientList_t;
	pthread_rwlock_t m_mutex_ClientDic_t;
	static pthread_rwlock_t m_mutex_single_t;
	static bool orInit_mutex_single;
	vector<ClientInfoPool*> ClientList;
	map<int,ClientInfoPool*> ClientDic;
	//创建单例销毁工人
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if(ClientManagerPool::single!=NULL)
			{
				delete ClientManagerPool::single;
			}
		}
	};
	static CGarbo Garbo;
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~网络加标志流~~~~~~~~~~~~~~~~~~~~~~~~~~~
const int stream_head_Length=2;
const int stream_tail_Length=2;
const int msg_head_Length=4;
class NetEncryptionStream
{
public:
	//const int stream_head_Length=2;
	//const int stream_tail_Length=2;
	//const int msg_head_Length=4;
};

class NetEncryptionInputStream:public NetEncryptionStream
{
public:
	int bodyLength;
	unsigned char* bodyData;

public:
	void SetData(const unsigned char* msg,const int Length);
	NetEncryptionInputStream();
	virtual ~NetEncryptionInputStream();
};

class NetEncryptionOutStream:public NetEncryptionStream
{
public:
	int Length;
	unsigned char* encryption_data;
public:
	void SetData(const unsigned char* msg,const int Length);
	NetEncryptionOutStream();
	virtual ~NetEncryptionOutStream();
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~网络包接收/发送池~~~~~~~~~~~~~~~~~~~~~~~~~~~
class NetPackageReceivePool:public NetEncryptionInputStream
{
public:
	int InputStreamLength;
	unsigned char* mInputStream;
public:
	void ReceiveNetMsg(const unsigned char* msg,const int Length);
	void GetPackage();
	~NetPackageReceivePool();
	NetPackageReceivePool();

};

class NetPackageSendPool:public NetEncryptionOutStream
{
public:
	void SendNetMsg(const unsigned char* msg,const int Length);
	//~NetPackageSendPool();
	//NetPackageSendPool();

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
	const int command_Length=4;

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
private:
	NetEncryptionInputStream mEncryptionInputStream;



};

class NetOutStream:public NetStream
{
public:
	NetOutStream(const int command,int Length, const unsigned char* msg);
public:
	unsigned char* msg;
	int msg_Length;

private:
	NetEncryptionOutStream mEncryptionOutStream;

};


} /* namespace basic */

#endif /* SRC_NETMANAGER_NETMANAGER_H_ */
