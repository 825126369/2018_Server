/*
 * NetProtoEvent.cpp
 * 3d month
 * Created on: Mar 25, 2016
 * Author: xuke
 */

#include "NetProtoEvent.h"

namespace basic
{
//1100:Chat
int Proto_Rec_Chat(const NetEventPackage mProtobuf)
{
	csChatData mChatinfo;
	mChatinfo.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	xk_Debug::Log()<<"Receive Chat Info："<<mChatinfo.channelid()<<" | "<<mChatinfo.talkmsg()<<endl;

	if(mProtobuf.mClient!=0)
	{
		vector<ClientInfoPool*> mClientList= ClientManagerPool::getSingle()->GetClientPool();
		for(auto a:mClientList)
		{
			scChatData mdata=scChatData();
			mdata.set_result(1);
			a->SendData(PROTO_CHAT,&mdata);
		}
	}else
	{
		xk_Debug::Log()<<"Client is no Find"<<endl;
	}
	return 0;
}

//1101:RegisterAccount
int Proto_Recevie_RegisterAccount(const NetEventPackage mProtobuf)
{
	csRegisterAccount mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	xk_Debug::Log()<<"Receive Register Account："<<mdata.accountname()<<" | "<<mdata.password()<<" | "<<mdata.repeatpassword()<<endl;

	scRegisterAccount mSendData;
	if(mdata.password()==mdata.repeatpassword())
	{
		game_login* mDb_Login=new game_login();
		mDb_Login->set_key_account_value(mdata.accountname());
		bool orExist= mDb_Login->has_key_account_value();
		if(orExist)
		{
			mSendData.set_result(false);
		}else
		{
			mDb_Login->create_key_account_value();
			mDb_Login->set_password_value(mdata.password());
			mSendData.set_result(true);
		}
		delete mDb_Login;
	}else
	{
		mSendData.set_result(false);
	}

	mProtobuf.mClient->SendData(PROTO_REGISTERACCOUNT,&mSendData);
}
//1102,AccountLogin
int Proto_Receive_LoginGame(const NetEventPackage mProtobuf)
{
	csLoginGame mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	cout<<"Receive Account Login Info："<<mdata.accountname()<<" | "<<mdata.password()<<endl;

	game_login* m_game_login=new game_login();
	m_game_login->set_key_account_value(mdata.accountname());
	scLoginGame mSendData;
	if(m_game_login->has_key_account_value())
	{
		if(m_game_login->get_key_account_value()==mdata.accountname() && m_game_login->get_password_value()==mdata.password())
		{
			mSendData.set_result(true);
			cout<<"Login Success"<<endl;
		}else
		{
			mSendData.set_result(false);
			cout<<"Login Failed"<<endl;
		}
	}
	else
	{
		cout<<"Account No Find"<<endl;
		mSendData.set_result(false);
		cout<<"Login Failed"<<endl;
	}
	mProtobuf.mClient->SendData(PROTO_LOGIN,&mSendData);
	delete m_game_login;
}
//1103:SelectServer
int Proto_Receive_SelectServer(const NetEventPackage mProtobuf)
{
	csSelectServer mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	cout<<"Receive Select Server:"<<mdata.id()<<endl;

	scSelectServer mSendData;
	mSendData.set_result(1);
	mProtobuf.mClient->SendData(PROTO_SELECTSERVER,&mSendData);
}
//1104:CreateRole
int Proto_Receive_CreateRole(const NetEventPackage mProtobuf)
{
	csCreateRole mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	cout<<"Receive CreateRole： "<<mdata.name()<<mdata.sex()<<mdata.profession()<<endl;

	scCreateRole mSendData;
	mSendData.set_result(1);
	mProtobuf.mClient->SendData(PROTO_CREATEROLE,&mSendData);
}

}







