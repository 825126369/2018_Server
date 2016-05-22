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
	MariaDBSystem::getSingle()->Init();
	NetEventManager::getSingle()->Init();
	ConfigTableManager::getSingle()->Init();
	NetManager::getSingle()->Init();

	NetManager::getSingle()->CloseNet();
	MariaDBSystem::getSingle()->CloseMariaDb();
	return 0;
}


