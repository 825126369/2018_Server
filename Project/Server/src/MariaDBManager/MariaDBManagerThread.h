#ifndef MariaDBManagerThread_H
#define MariaDBManagerThread_H
#include <pthread.h>
#include <ctime>
#include <mysql.h>
#include <iostream>
#include "MariaDBSystem.h"

using namespace std;
namespace basic
{
class MariaDBSystem;
void InitTrhead(MariaDBSystem* connection);

void* Fun_ping(void * aaa);

void Check_Ping();


}
#endif
