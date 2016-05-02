/*
 * main.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */
#include "NetManager/NetThreadManager.h"
#include "MariaDBManager/MariaDBSystem.h"
#include "ConfigTableManager/ConfigTableManager.h"
#include "MariaDBManager/DbTable.h"
using namespace std;
using namespace basic;
int main(int arg,char **argc)
{
	char *ip={};
	int port={};
	int maxConnect={};
	switch(arg)
	{
	case 2:
		ip=argc[1];
		port=7878;
		maxConnect=1;
		break;
	case 3:
		ip=argc[1];
		port=atoi(argc[2]);
		maxConnect=1;
		break;
	case 4:
		ip=argc[1];
		port=atoi(argc[2]);
		maxConnect=atoi(argc[3]);
		break;
	default:
		ip="192.168.1.7";
		port=7878;
		maxConnect=1;
		break;
	}
	MariaDBSystem::getSingle()->ConnectMariadb();
	NetEventManager::getSingle()->Init();
	NetThreadManger_Init(ip,port,maxConnect);

	/*game_login gl=game_login("xuk456");

	bool orE= gl.OrExistsPrimaryKey();
	if(orE)
	{
		cout<<"存在主键"<<endl;
		string password= gl.get_password_value();
		cout<<"密码："<<password<<endl;
	}else
	{
		cout<<"不存在主键"<<endl;
		gl.CreatePrimaryKey();
			gl.set_password_value("123");
			string password= gl.get_password_value();
			cout<<"密码："<<password<<endl;
	}*/

	MariaDBSystem::getSingle()->CloseMariaDb();
	return 0;
}


