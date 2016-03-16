/*
 * main.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */

#include <iostream>
#include "NetManager/NetManager.h"
using namespace std;
using namespace basic;
int main()
{
	NetManager mNetManager;
	mNetManager.InitNet("192.168.1.4",7878);
	mNetManager.NetConnectServer();
	mNetManager.closeNet();
	return 0;
}


