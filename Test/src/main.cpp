#include <stdio.h>  
#include <uuid/uuid.h>
#include <iostream>
#include <cstring>
#include "db_protobuf.pb.h"
#include "db_protobuf_struct.pb.h"
using namespace std;
using namespace db_protobuf;

int main()   
{
	db_protobuf::db_loginallserverinfo mdata;
	db_protobuf::serverinfo* madd=mdata.add_allserverinfo();
	madd->set_serverid(100);
	madd->set_lastloginroleid(200);

	size_t length=mdata.ByteSize();
	cout<<"protobuf length: "<<length<<endl;
	char* ddd=new char[length];
	mdata.SerializeToArray(ddd,length);
	cout<<ddd<<endl;
	string dddd=ddd;
	cout<<dddd<<endl;
	cout<<"string length:"<<dddd.length()<<endl;
	return 0;
}   
  
