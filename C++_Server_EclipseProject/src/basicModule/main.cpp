/*
 * main.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */
#include "../basicModule/NetManager/NetThreadManager.h"
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
		ip="192.168.1.4";
		port=7878;
		maxConnect=1;
		break;
	}
	NetEventManager::getSingle()->Init();
	NetThreadManger_Init(ip,port,maxConnect);
	return 0;
}


