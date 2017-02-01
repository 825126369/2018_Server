/*
 * main.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: xuke
 */
#include "NetManager.h"
#include "MariaDBSystem.h"
#include "ConfigTableManager.h"
#include "Environment.h"
using namespace std;
using namespace basic;
int main(int arg,char **argc)
{
	CheckEnvironment();	
	MariaDBSystem::getSingle()->Init();
	NetEventManager::getSingle()->Init();
	ConfigTableManager::getSingle()->Init();
	NetManager::getSingle()->Init();
	NetManager::getSingle()->CloseNet();
	MariaDBSystem::getSingle()->CloseMariaDb();
	return 0;
}


