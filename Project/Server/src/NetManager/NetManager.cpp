/*
 * NetManager.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */

#include "NetManager.h"

namespace basic {
NetManager NetManager::single;
NetManager::NetManager() {
	// TODO Auto-generated constructor stub
}

NetManager::~NetManager() {
	// TODO Auto-generated destructor stub
}
NetManager* NetManager::getSingle()
{
	return &single;
}
int NetManager::Init()
{
	if(InitNet()==-1)
	{
		CloseNet();
		return -1;
	}
	cout<<"Net Init Finish"<<endl;
	NetThreadManger_Init(this);
	return 0;
}

int NetManager::InitNet()
{
	const char* ipStr="192.168.1.109";
	const int port=7878;
	const int maxConnectCout=0;

	Server=socket_class();
	//memset(&Server,0,sizeof(Server));
	
	if((Server._fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
	{
		xk_Debug::LogSystemError("Init Server_fd Error:");
		return -1;
	}
	int reuse=1;
    if (setsockopt(Server._fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse))==-1)
    {
            xk_Debug::LogSystemError("setsockopet error:");
            return -1;
    }
	//Socket
	Server._addr.sin_addr.s_addr=inet_addr(ipStr);
   	//Server._addr.sin_addr.s_addr=INADDR_ANY;
	Server._addr.sin_family=AF_INET;
	Server._addr.sin_port=htons(port);
	printServerinfo(Server);

	if(bind(Server._fd,(const struct sockaddr *)&Server._addr,sizeof(Server._addr))==-1)
	{
		xk_Debug::LogSystemError("Bind error:");
		return -1;
	}
	if(listen(Server._fd,maxConnectCout)==-1)
	{
		xk_Debug::LogSystemError("Listen Error:");
		return -1;
	}
	xk_Debug::Log()<<"Start Listening"<<endl;
	return 0;
}

int NetManager::NetAcceptClient(socket_class& client)
{
		socklen_t len;
		if((client._fd=accept(Server._fd,(struct sockaddr*)&(client._addr),&len))==-1)
		{
			xk_Debug::LogSystemError("Accept Error:");
			return -1;
		}
		return 0;
}

//成功则返回0，错误返回-1
int NetManager::CloseNet()
{
	//shutdown(server_fd,SHUT_WR);
	if(close(Server._fd)==-1)
	{
		xk_Debug::LogSystemError("Close Server Error:");
		return -1;
	}
	xk_Debug::Log()<<"Server Closed"<<endl;
	return 0;
}

int NetManager::printServerinfo(const socket_class& _socket)
{
	cout<<"Server:  File ID:"<<_socket._fd<<"  IP:"<<inet_ntoa(_socket._addr.sin_addr)<<" Port:"<<(ntohs(_socket._addr.sin_port))<<endl;
}

ClientInfoPool::ClientInfoPool(socket_class* socket_r)
{
	mClientInfo=new ClientInfo();
	mClientInfo->mSocketInfo=socket_r;
}

ClientInfoPool::~ClientInfoPool() {
	delete mClientInfo;
}
int ClientInfoPool::run()
{
	NetReceiveMsg();
	return 0;
}

int ClientInfoPool::NetReceiveMsg()
{
	const socket_class& client=*(mClientInfo->mSocketInfo);
	while(3)
	{
		unsigned char msg[1024]={};
		ssize_t receiveMsgLength=recv(client._fd,&msg,1024,0);
		if(receiveMsgLength==-1)
		{
			xk_Debug::LogSystemError("NetReceiveMsg Error:");
			CloseNet();
			return -1;
		}else if(receiveMsgLength==0)
		{
			if(close(client._fd)==-1)
			{
				xk_Debug::LogSystemError("Client Close Error:");
			}
			xk_Debug::Log()<<"client DisConnected： "<<endl;
			printClientinfo();
			break;
		}else if(receiveMsgLength>0)
		{
			xk_Debug::Log()<<"Receive Info Length:"<<receiveMsgLength<<endl;
			for(int i=0;i<receiveMsgLength;i++)
			{
				xk_Debug::Log()<<(int)msg[i]<<" | ";
			}
			xk_Debug::Log()<<endl;

			ParseData(msg,receiveMsgLength);
		}
	}
	return 0;
}

int ClientInfoPool::ParseData(const unsigned char* msg,int msg_Length)
{
	NetEventPackage mProtobuf=NetEventPackage();
	mProtobuf.mClient=this;
	mProtobuf.DeSerializeStream(msg,msg_Length);

	NetEventManager::getSingle()->handleEvent(mProtobuf);
	return 0;
}

int ClientInfoPool::SendData(int command,google::protobuf::Message* msgClass)
{
	Protobuf mProtobuf=Protobuf(command,msgClass);
	NetOutStream mNetOutStream=mProtobuf.SerializeMsgObj();
	NetSendMsg(mNetOutStream.msg,mNetOutStream.msg_Length);
	return 0;
}

int ClientInfoPool::NetSendMsg(const unsigned char* msg,const int Length)
{
	const socket_class& client=*mClientInfo->mSocketInfo;

	xk_Debug::Log()<<"发送密文字节流，长度："<<Length<<endl;
	for(int i=0;i<Length;i++)
	{
		cout<<(int)(msg[i])<<" | ";
	}
	xk_Debug::Log()<<endl;

	if(send(client._fd,msg,Length,0)==-1)
	{
		xk_Debug::LogSystemError("Send Error:");
		return -1;
	}
	return 0;
}
int ClientInfoPool::CloseNet()
{
	close(mClientInfo->mSocketInfo->_fd);
}
int ClientInfoPool::printClientinfo()
{
	cout<<"Client:  描数字："<<mClientInfo->mSocketInfo->_fd<<"  IP:"<<inet_ntoa(mClientInfo->mSocketInfo->_addr.sin_addr)<<"    端口："<<(ntohs(mClientInfo->mSocketInfo->_addr.sin_port))<<endl;
}

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
			if(single==NULL)
			{
				single=new ClientManagerPool();
			}
			//unlock();
		}
		return single;
}

int ClientManagerPool::InitClient(socket_class* info)
{
	ClientInfoPool* mClient=new ClientInfoPool(info);
	AddClient(mClient);
	printClientPoolinfo();
	mClient->run();
	RemoveClient(mClient);
	printClientPoolinfo();
	delete mClient;
}

int ClientManagerPool::AddClient(ClientInfoPool* client)
{
	ClientList.push_back(client);
	ClientDic.insert(pair<int,ClientInfoPool*>(client->mClientInfo->mSocketInfo->_fd,client));

	return 0;
}
int ClientManagerPool::RemoveClient(ClientInfoPool* client)
{
	for(vector<ClientInfoPool*>::iterator iter=ClientList.begin();ClientList.begin()!=ClientList.end();)
	{
		if((*iter)->mClientInfo->mSocketInfo->_fd==client->mClientInfo->mSocketInfo->_fd)
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
		map<int,ClientInfoPool*>::iterator iter=ClientDic.find(_fd);
		if(iter!=ClientDic.end())
		{
			return ((*iter).second);
		}
		return 0;
}

int ClientManagerPool::printClientPoolinfo()
{
	cout<<"客户连接池信息："<<endl;
	for(vector<ClientInfoPool*>::iterator iter=ClientList.begin();iter!=ClientList.end();iter++)
	{
		(*(*(iter))).printClientinfo();
	}
	cout<<"池容量："<<ClientList.capacity()<<endl;
	cout<<"池客户数量："<<ClientList.size()<<endl;
}
Protobuf::Protobuf()
{
	protobuf_command=-1;
	protobuf_msgObj=0;
	protobuf_Length=-1;
	protobuf_msg=0;
}

Protobuf::Protobuf(int command,google::protobuf::Message* obj)
{
	protobuf_command=command;
	protobuf_msgObj=obj;
	protobuf_Length=obj->ByteSize();
	protobuf_msg=0;
}

NetOutStream Protobuf::SerializeMsgObj()
{
	unsigned char* buffer=new unsigned char[protobuf_Length];
	protobuf_msgObj->SerializeToArray(buffer,protobuf_Length);
	NetOutStream mStream=NetOutStream(protobuf_command,protobuf_Length,buffer);
	return mStream;
}

int Protobuf::DeSerializeStream(const unsigned char* msg,int Length)
{
	NetInputStream mStream=NetInputStream(msg,Length);
	protobuf_msg=mStream.buffer;
	protobuf_command=mStream.command;
	protobuf_Length=mStream.buffer_Length;

	return 0;

}

NetInputStream::NetInputStream(const unsigned char* msg1,const int msg1Length)
{
		char* ivStr1=new char[strlen(ivStr)];
		strcpy(ivStr1,(char*)ivStr);

		unsigned char* msg= Encryption_AES::getSingle()->Decryption_CBC(msg1,msg1Length,(unsigned char*)keyStr,(unsigned char*)ivStr1);
		int msgLength=Encryption_AES::getSingle()->GetStreamLength(msg,msg1Length);

		cout<<"收到明文字节流，长度:"<<msgLength<<endl;
		for(int i=0;i<msgLength;i++)
		{
			cout<<(int)msg[i]<<" | ";
		}
		cout<<endl;
		this->command=(msg[4]<<24 | msg[3]<<16 | msg[2]<<8 | msg[1]);
		cout<<"命令："<<command<<endl;

		int Length={};
		Length=msg[8]<<24 | msg[7]<<16 | msg[6]<<8 | msg[5];
		cout<<"protobuf Length："<<Length<<endl;
		buffer_Length=Length;

		buffer=new unsigned char[Length];
		for(int i=head_Length+msg_head_Length;i<msg_head_Length+head_Length+Length;i++)
		{
			buffer[i-head_Length-msg_head_Length]=msg[i];
		}
}

NetOutStream:: NetOutStream(const int command,const int Length,const unsigned char* data)
{
		unsigned char msg_head=255;
		unsigned char msg_tail=255;

		unsigned char head[4]={};
		head[0]=command;
		head[1]=command>>8;
		head[2]=command>>16;
		head[3]=command>>24;

		unsigned char lengStr[4]={};
		lengStr[0]=Length;
		lengStr[1]=Length>>8;
		lengStr[2]=Length>>16;
		lengStr[3]=Length>>24;

		const int sumLength=msg_head_Length+head_Length+Length+msg_tail_Length;
		vector<unsigned char> msgStream={};
		for(int i=0;i<sumLength;i++)
		{
			if(i==0)
			{
				msgStream[0]=msg_head;
			}
			else if(i<msg_head_Length+command_Length && i>=msg_head_Length)
			{
				msgStream[i]=head[i-msg_head_Length];
			}else if(i>=msg_head_Length+command_Length && i<msg_head_Length+command_Length+buffer_Length)
			{
				msgStream[i]=lengStr[i-msg_head_Length-command_Length];
			}else if(i>=head_Length+msg_head_Length && i<head_Length+msg_head_Length+Length)
			{
				msgStream[i]=data[i-msg_head_Length-head_Length];
			}else
			{
				msgStream[i]=msg_tail;
			}
		}

		cout<<"发送明文字节流，长度:"<<sumLength<<endl;
		for(int i=0;i<sumLength;i++)
		{
			cout<<(int)msgStream[i]<<" | ";
		}
		cout<<endl;

		char* ivStr1=new char[16];
		strcpy(ivStr1,ivStr);

		msg_Length= Encryption_AES::getSingle()->GetCipherLength(sumLength);
		//填充为PKCS7格式，否则，客户端无法解密
		unsigned char* msgStream1=new unsigned char[msg_Length];
		for(int i=0;i<msg_Length;i++)
		{
			if(i<sumLength)
			{
				msgStream1[i]=msgStream[i];
			}else
			{
				msgStream1[i]=msg_Length-sumLength;
			}
		}
		this->msg= Encryption_AES::getSingle()->Encryption_CBC(msgStream1,msg_Length,(unsigned char*)keyStr,(unsigned char*)ivStr1);

}

} /* namespace basic */

