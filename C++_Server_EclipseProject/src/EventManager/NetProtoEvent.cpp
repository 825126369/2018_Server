/*
 * NetProtoEvent.cpp
 *
 *  Created on: Mar 25, 2016
 *      Author: xuke
 */

#include "NetProtoEvent.h"

namespace basic
{

//1100
int Proto_Rec_Chat(const NetEventPackage mProtobuf)
{
	ClientSendData mChatinfo;
	mChatinfo.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	xk_Debug::Log()<<"解析数据："<<mChatinfo.sendername()<<" | "<<mChatinfo.talkmsg()<<endl;


	if(mProtobuf.mClient!=0)
	{
		ServerSendData mdata=ServerSendData();
		mdata.set_nickname("server");
		mdata.set_talkmsg("shou dao");
		mProtobuf.mClient->SendData((int)Chat,&mdata);
	}else
	{
		xk_Debug::Log()<<"事件发送者不存在"<<endl;
	}
	return 0;
}

//1101
int Proto_Recevie_RegisterAccount(const NetEventPackage mProtobuf)
{
	csRegisterAccount mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	xk_Debug::Log()<<"解析注册账号数据："<<mdata.accountname()<<" | "<<mdata.password()<<" | "<<mdata.repeatpassword()<<endl;

	scRegisterAccount mSendData;
	if(mdata.password()==mdata.repeatpassword())
	{
		game_login* mDb_Login= mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_login>();
		mDb_Login->set_key_account_value(mdata.accountname());
		bool orExist= mDb_Login->has_key_account_value();
		if(orExist)
		{
			mSendData.set_result(false);
		}else
		{
			mDb_Login->create_key_account_value();
			mDb_Login->set_password_value(mdata.password());
		}
		mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_login>();
	}else
	{
		mSendData.set_result(false);
	}

	mProtobuf.mClient->SendData(RegisterAccount,&mSendData);
}
//1102
int Proto_Receive_LoginGame(const NetEventPackage mProtobuf)
{
	csLoginGame mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	cout<<"解析登陆数据："<<mdata.accountname()<<" | "<<mdata.password()<<endl;

	game_login* m_game_login= mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_login>();
	m_game_login->set_key_account_value(mdata.accountname());
	if(m_game_login->has_key_account_value())
	{
		m_game_login->set_all_value("nimabi");
		m_game_login->get_all_value();

		if(m_game_login->get_key_account_value()==mdata.accountname() && m_game_login->get_password_value()==mdata.password())
		{
			scLoginGame mSendData;
			mSendData.set_result(true);
			mProtobuf.mClient->SendData(Login,&mSendData);
		}else
		{
			scLoginGame mSendData;
			mSendData.set_result(false);
			mProtobuf.mClient->SendData(Login,&mSendData);
		}
	}
	else
	{
		cout<<"账户名不正确"<<endl;
	}
}


}







