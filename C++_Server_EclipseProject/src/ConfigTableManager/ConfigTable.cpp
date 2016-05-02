#include "ConfigTable.h"
namespace basic{
int config_Sheet1DB::classId=0;
config_Sheet1DB::config_Sheet1DB()
{
	classId=301;
}
config_Sheet1DB::~config_Sheet1DB()
{
}
int config_Sheet1DB::get_id_value()
{
	return this->id;
}
string config_Sheet1DB::get_fff1_value()
{
	return this->fff1;
}
string config_Sheet1DB::get_fff2_value()
{
	return this->fff2;
}
string config_Sheet1DB::get_fff3_value()
{
	return this->fff3;
}
string config_Sheet1DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet1DB::set_fields_value(vector<string> value)
{
	int str=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str;
	this->fff1=value[1];
	this->fff2=value[2];
	this->fff3=value[3];
	this->fff4=value[4];
	return 0;
}
int config_Sheet1DB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_Sheet1DB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	cout<<"fff1: "<<this->fff1<<endl;
	cout<<"fff2: "<<this->fff2<<endl;
	cout<<"fff3: "<<this->fff3<<endl;
	cout<<"fff4: "<<this->fff4<<endl;
	cout<<"classId: "<<config_Sheet1DB::classId<<endl;
	return 0;
}
int config_Sheet1DB::get_classId_value()
{
	return classId;
}
int config_Sheet2DB::classId=0;
config_Sheet2DB::config_Sheet2DB()
{
	classId=302;
}
config_Sheet2DB::~config_Sheet2DB()
{
}
int config_Sheet2DB::get_id_value()
{
	return this->id;
}
string config_Sheet2DB::get_fff1_value()
{
	return this->fff1;
}
string config_Sheet2DB::get_fff2_value()
{
	return this->fff2;
}
string config_Sheet2DB::get_fff3_value()
{
	return this->fff3;
}
string config_Sheet2DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet2DB::set_fields_value(vector<string> value)
{
	int str=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str;
	this->fff1=value[1];
	this->fff2=value[2];
	this->fff3=value[3];
	this->fff4=value[4];
	return 0;
}
int config_Sheet2DB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_Sheet2DB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	cout<<"fff1: "<<this->fff1<<endl;
	cout<<"fff2: "<<this->fff2<<endl;
	cout<<"fff3: "<<this->fff3<<endl;
	cout<<"fff4: "<<this->fff4<<endl;
	cout<<"classId: "<<config_Sheet2DB::classId<<endl;
	return 0;
}
int config_Sheet2DB::get_classId_value()
{
	return classId;
}

ConfigTableBase* LoadTableCpp(string classname)
{
	ConfigTableBase* base=NULL;
	if(classname=="config_Sheet1DB")
	{
		base=new config_Sheet1DB();
	}
	else if(classname=="config_Sheet2DB")
	{
		base=new config_Sheet2DB();
	}
	return base;
}
}
