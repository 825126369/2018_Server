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
			mSendData.set_result(3);
		}else
		{
			mDb_Login->create_key_account_value();
			mDb_Login->set_password_value(mdata.password());
			mSendData.set_result(1);
		}
		delete mDb_Login;
	}else
	{
		mSendData.set_result(3);
	}
	if(mSendData.result()==1)
	{
		cout<<"Register Success"<<endl;
	}else
	{
		cout<<"Register Failed"<<mSendData.result()<<endl;
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
	bool orSuccess=false;
	if(m_game_login->has_key_account_value())
	{
		if(m_game_login->get_key_account_value()==mdata.accountname() && m_game_login->get_password_value()==mdata.password())
		{
			mSendData.set_result(1);
		}else
		{
			mSendData.set_result(3);
		}
	}
	else
	{
		cout<<"Account No Find"<<endl;
		mSendData.set_result(3);
		cout<<"Login Failed"<<endl;
		orSuccess=false;	
	}
	if(mSendData.result()==1)
	{
		game_server* m_game_server=mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_server>();
		m_game_server->set_key_account_value(mdata.accountname());
		if(m_game_server->has_key_account_value())
		{
			unsigned int lastLoginServerId=m_game_server->get_lastloginserverid_value();
			if(lastLoginServerId>0)
			{
				mSendData.set_lastselecserverid(lastLoginServerId);
			}
			db_loginallserverinfo* otherInfo=m_game_server->get_custom_db_loginallserverinfo_value();
			if(otherInfo!=NULL && otherInfo->allserverinfo_size()>0)
			{		
				for(int i=0;i<otherInfo->allserverinfo_size();i++)
				{
					const db_protobuf::serverinfo m_serverinfo=otherInfo->allserverinfo(i);
					mSendData.add_beforeloginrecordserverlist(m_serverinfo.serverid());	
				}
			}else
			{
				cerr<<"all server info size is zero"<<endl;
			}
		}else
		{
			m_game_server->create_key_account_value();
			cerr<<"Find account serverinfo failed"<<endl;
		}
	}
	if(mSendData.result()==1)
	{
		cout<<"Login Success"<<endl;
	}else
	{
		cout<<"Login Failed"<<mSendData.result()<<endl;
	}
	mProtobuf.mClient->SendData(PROTO_LOGIN,&mSendData);
	delete m_game_login;
}
//1103:SelectServer
int Proto_Receive_SelectServer(const NetEventPackage mProtobuf)
{
	xk_protobuf_data::csSelectServer mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	cout<<"Receive Select Server:"<<mdata.id()<<endl;

	xk_protobuf_data::scSelectServer mSendData;
	mSendData.set_result(1);
		
	game_server* m_game_server=mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_server>();
	if(m_game_server->has_key_account_value())
	{
		m_game_server->set_lastloginserverid_value(mdata.id());
	
		db_loginallserverinfo* otherInfo=m_game_server->get_custom_db_loginallserverinfo_value();
		if(otherInfo!=NULL && otherInfo->allserverinfo_size()>0)
		{		
			for(int i=0;i<otherInfo->allserverinfo_size();i++)
			{
				const db_protobuf::serverinfo m_serverinfo=otherInfo->allserverinfo(i);
				if(m_serverinfo.serverid()==mdata.id())
				{
					const unsigned long lastSelectRoleId= m_serverinfo.lastloginroleid();
					mSendData.set_lastselectroleid(lastSelectRoleId);
					if(m_serverinfo.roleid_size()>0)
					{
						for(int i=0;i<m_serverinfo.roleid_size();i++)
						{
							const unsigned long roleId=m_serverinfo.roleid(i);	
							game_role* m_game_role=mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_role>();
							m_game_role->set_key_roleId_value(roleId);
							if(m_game_role->has_key_roleId_value())
							{
								xk_protobuf_data::struct_PlayerDetailInfo* mRoleInfo= mSendData.add_rolelist();
								mRoleInfo->set_id(roleId);
								mRoleInfo->set_level(m_game_role->get_level_value());					
								mRoleInfo->set_name(m_game_role->get_name_value());
								mRoleInfo->set_gender(m_game_role->get_gender_value());
								mRoleInfo->set_profession(m_game_role->get_profession_value());
							}
						}
					}
				}
			}
		}else
		{
			cerr<<"all server info size is zero"<<endl;
		}
	}else
	{
		cerr<<"Find account serverinfo failed"<<endl;
	}
	mProtobuf.mClient->SendData(PROTO_SELECTSERVER,&mSendData);
}
//1104:CreateRole
int Proto_Receive_CreateRole(const NetEventPackage mProtobuf)
{
	csCreateRole mdata;
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	mdata.DebugString();
 	xk_protobuf_data::scCreateRole mSendData;
	string name= mdata.name();
	uint gender=mdata.sex();
	uint profession=mdata.profession();
	bool name_result=false;
	if(name!="" && name.length()<5)
	{
		name_result=true;
	}
	bool gender_result=false;
	if(gender==1 || gender==2)
	{
		gender_result=true;
	}
	bool profession_result=false;
	if(profession==1 || profession==2 || profession==3)
	{
		profession_result=true;
	}		
	if(name_result==true && gender_result==true && profession_result==true)
	{
		mSendData.set_result(1);
	}else
	{
		mSendData.set_result(3);
	}
	if(mSendData.result()==1)
	{
		game_role* mDb_role=mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_role>();
		unsigned long roleId=generateUUID();
		mDb_role->set_key_roleId_value(roleId,true);
		mDb_role->set_name_value(name);
		mDb_role->set_gender_value(gender);
		mDb_role->set_profession_value(profession);
		mDb_role->set_level_value(1);

		game_server* mDb_server=mProtobuf.mClient->mClientInfo->mDbManager.GetDbTable<game_server>();
		db_protobuf::db_loginallserverinfo* mserverinfo=mDb_server->get_custom_db_loginallserverinfo_value();
		bool orHaveServer=false;
		if(mserverinfo!=NULL)
		{
			for(int i=0;i<mserverinfo->allserverinfo_size();i++)
			{
		 		serverinfo* mCurrentServerInfo=mserverinfo->mutable_allserverinfo(i);	
				if(mCurrentServerInfo->serverid()==mDb_server->get_lastloginserverid_value())
				{
					mCurrentServerInfo->add_roleid(roleId);	
					orHaveServer=true;
				}
			}
		}else
		{
			mserverinfo=new db_loginallserverinfo();
		}
		if(orHaveServer==false)
		{
			cerr<<"this server id not find"<<endl;
			db_protobuf::serverinfo* maddserverinfo=mserverinfo->add_allserverinfo();
			maddserverinfo->set_serverid(mDb_server->get_lastloginserverid_value());
			maddserverinfo->add_roleid(roleId);
		}
		mDb_server->set_custom_db_loginallserverinfo_value(mserverinfo);

		struct_PlayerDetailInfo* mCreateRoledata=new struct_PlayerDetailInfo();
		mCreateRoledata->set_id(roleId);
		mCreateRoledata->set_name(name);
		mCreateRoledata->set_level(1);
		mCreateRoledata->set_gender(gender);
		mCreateRoledata->set_profession(profession);
		mSendData.set_allocated_role(mCreateRoledata);
	}
	mProtobuf.mClient->SendData(PROTO_CREATEROLE,&mSendData);
}
//1105:SelectRole
int Proto_Receive_SelectRole(const NetEventPackage mProtobuf)
{
	csSelectRole mdata=csSelectRole();
	mdata.ParseFromArray(mProtobuf.protobuf_msg,mProtobuf.protobuf_Length);
	mdata.DebugString();
		
	scSelectRole mSendData;
	mSendData.set_result(1);

	mProtobuf.mClient->SendData(PROTO_SELECTROLE,&mSendData);
}




}







