#include "ConfigTable.h"
namespace basic{
int config_Sheet1DB::classId=0;
config_Sheet1DB::config_Sheet1DB()
{
	classId=501;
}
config_Sheet1DB::~config_Sheet1DB()
{
}
int config_Sheet1DB::get_id_value()
{
	return this->id;
}
array<string,3> config_Sheet1DB::get_fff1_value()
{
	return this->fff1;
}
array<string,4> config_Sheet1DB::get_fff2_value()
{
	return this->fff2;
}
array<string,5> config_Sheet1DB::get_fff3_value()
{
	return this->fff3;
}
array<string,6> config_Sheet1DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet1DB::set_fields_value(vector<string> value)
{
	int str=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str;
	fff1={};
	vector<string> value1=StrToVector(value[1],"#");
	int length1=value1.size()<fff1.size()? value1.size():fff1.size();
	for(int k=0;k<length1;k++)
	{
		this->fff1[k]=value1[k];
	}
	fff2={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size()<fff2.size()? value2.size():fff2.size();
	for(int k=0;k<length2;k++)
	{
		this->fff2[k]=value2[k];
	}
	fff3={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size()<fff3.size()? value3.size():fff3.size();
	for(int k=0;k<length3;k++)
	{
		this->fff3[k]=value3[k];
	}
	fff4={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size()<fff4.size()? value4.size():fff4.size();
	for(int k=0;k<length4;k++)
	{
		this->fff4[k]=value4[k];
	}
	return 0;
}
int config_Sheet1DB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_Sheet1DB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	for(string value : fff1)
	{
			cout<<"fff1: "<<value<<endl;
	}
	for(string value : fff2)
	{
			cout<<"fff2: "<<value<<endl;
	}
	for(string value : fff3)
	{
			cout<<"fff3: "<<value<<endl;
	}
	for(string value : fff4)
	{
			cout<<"fff4: "<<value<<endl;
	}
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
	classId=502;
}
config_Sheet2DB::~config_Sheet2DB()
{
}
int config_Sheet2DB::get_id_value()
{
	return this->id;
}
array<string,3> config_Sheet2DB::get_fff1_value()
{
	return this->fff1;
}
array<string,4> config_Sheet2DB::get_fff2_value()
{
	return this->fff2;
}
array<string,5> config_Sheet2DB::get_fff3_value()
{
	return this->fff3;
}
array<string,6> config_Sheet2DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet2DB::set_fields_value(vector<string> value)
{
	int str=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str;
	fff1={};
	vector<string> value1=StrToVector(value[1],"#");
	int length1=value1.size()<fff1.size()? value1.size():fff1.size();
	for(int k=0;k<length1;k++)
	{
		this->fff1[k]=value1[k];
	}
	fff2={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size()<fff2.size()? value2.size():fff2.size();
	for(int k=0;k<length2;k++)
	{
		this->fff2[k]=value2[k];
	}
	fff3={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size()<fff3.size()? value3.size():fff3.size();
	for(int k=0;k<length3;k++)
	{
		this->fff3[k]=value3[k];
	}
	fff4={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size()<fff4.size()? value4.size():fff4.size();
	for(int k=0;k<length4;k++)
	{
		this->fff4[k]=value4[k];
	}
	return 0;
}
int config_Sheet2DB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_Sheet2DB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	for(string value : fff1)
	{
			cout<<"fff1: "<<value<<endl;
	}
	for(string value : fff2)
	{
			cout<<"fff2: "<<value<<endl;
	}
	for(string value : fff3)
	{
			cout<<"fff3: "<<value<<endl;
	}
	for(string value : fff4)
	{
			cout<<"fff4: "<<value<<endl;
	}
	cout<<"classId: "<<config_Sheet2DB::classId<<endl;
	return 0;
}
int config_Sheet2DB::get_classId_value()
{
	return classId;
}


int config_Sheet3DB::classId=0;
config_Sheet3DB::config_Sheet3DB()
{
	classId=503;
}
config_Sheet3DB::~config_Sheet3DB()
{
}
int config_Sheet3DB::get_id_value()
{
	return this->id;
}
array<string,3> config_Sheet3DB::get_fff1_value()
{
	return this->fff1;
}
array<string,4> config_Sheet3DB::get_fff2_value()
{
	return this->fff2;
}
array<string,5> config_Sheet3DB::get_fff3_value()
{
	return this->fff3;
}
array<string,6> config_Sheet3DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet3DB::set_fields_value(vector<string> value)
{
	int str=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str;
	fff1={};
	vector<string> value1=StrToVector(value[1],"#");
	int length1=value1.size()<fff1.size()? value1.size():fff1.size();
	for(int k=0;k<length1;k++)
	{
		this->fff1[k]=value1[k];
	}
	fff2={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size()<fff2.size()? value2.size():fff2.size();
	for(int k=0;k<length2;k++)
	{
		this->fff2[k]=value2[k];
	}
	fff3={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size()<fff3.size()? value3.size():fff3.size();
	for(int k=0;k<length3;k++)
	{
		this->fff3[k]=value3[k];
	}
	fff4={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size()<fff4.size()? value4.size():fff4.size();
	for(int k=0;k<length4;k++)
	{
		this->fff4[k]=value4[k];
	}
	return 0;
}
int config_Sheet3DB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_Sheet3DB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	for(string value : fff1)
	{
			cout<<"fff1: "<<value<<endl;
	}
	for(string value : fff2)
	{
			cout<<"fff2: "<<value<<endl;
	}
	for(string value : fff3)
	{
			cout<<"fff3: "<<value<<endl;
	}
	for(string value : fff4)
	{
			cout<<"fff4: "<<value<<endl;
	}
	cout<<"classId: "<<config_Sheet3DB::classId<<endl;
	return 0;
}
int config_Sheet3DB::get_classId_value()
{
	return classId;
}


int config_Sheet4DB::classId=0;
config_Sheet4DB::config_Sheet4DB()
{
	classId=504;
}
config_Sheet4DB::~config_Sheet4DB()
{
}
int config_Sheet4DB::get_id_value()
{
	return this->id;
}
string config_Sheet4DB::get_fff0_value()
{
	return this->fff0;
}
array<int,10> config_Sheet4DB::get_fff6_value()
{
	return this->fff6;
}
array<string,3> config_Sheet4DB::get_fff1_value()
{
	return this->fff1;
}
array<string,4> config_Sheet4DB::get_fff2_value()
{
	return this->fff2;
}
array<string,5> config_Sheet4DB::get_fff3_value()
{
	return this->fff3;
}
array<string,6> config_Sheet4DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet4DB::set_fields_value(vector<string> value)
{
	int str=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str;
	this->fff0=value[1];
	fff6={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size()<fff6.size()? value2.size():fff6.size();
	for(int k=0;k<length2;k++)
	{
		int str=ConfigTableBase::convert<string,int>(value2[k]);
		this->fff6[k]=str;
	}
	fff1={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size()<fff1.size()? value3.size():fff1.size();
	for(int k=0;k<length3;k++)
	{
		this->fff1[k]=value3[k];
	}
	fff2={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size()<fff2.size()? value4.size():fff2.size();
	for(int k=0;k<length4;k++)
	{
		this->fff2[k]=value4[k];
	}
	fff3={};
	vector<string> value5=StrToVector(value[5],"#");
	int length5=value5.size()<fff3.size()? value5.size():fff3.size();
	for(int k=0;k<length5;k++)
	{
		this->fff3[k]=value5[k];
	}
	fff4={};
	vector<string> value6=StrToVector(value[6],"#");
	int length6=value6.size()<fff4.size()? value6.size():fff4.size();
	for(int k=0;k<length6;k++)
	{
		this->fff4[k]=value6[k];
	}
	return 0;
}
int config_Sheet4DB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_Sheet4DB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	cout<<"fff0: "<<this->fff0<<endl;
	for(int value : fff6)
	{
			cout<<"fff6: "<<value<<endl;
	}
	for(string value : fff1)
	{
			cout<<"fff1: "<<value<<endl;
	}
	for(string value : fff2)
	{
			cout<<"fff2: "<<value<<endl;
	}
	for(string value : fff3)
	{
			cout<<"fff3: "<<value<<endl;
	}
	for(string value : fff4)
	{
			cout<<"fff4: "<<value<<endl;
	}
	cout<<"classId: "<<config_Sheet4DB::classId<<endl;
	return 0;
}
int config_Sheet4DB::get_classId_value()
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
	else if(classname=="config_Sheet3DB")
	{
		base=new config_Sheet3DB();
	}
	else if(classname=="config_Sheet4DB")
	{
		base=new config_Sheet4DB();
	}
	return base;
}
}
