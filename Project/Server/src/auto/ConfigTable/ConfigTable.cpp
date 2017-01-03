#include "ConfigTable.h"
namespace basic{
int config_HeroAttDB::classId=0;
config_HeroAttDB::config_HeroAttDB()
{
	classId=801;
}
config_HeroAttDB::~config_HeroAttDB()
{
}
int config_HeroAttDB::get_id_value()
{
	return this->id;
}
string config_HeroAttDB::get_heroAtlas_value()
{
	return this->heroAtlas;
}
string config_HeroAttDB::get_heroIcon_value()
{
	return this->heroIcon;
}
string config_HeroAttDB::get_heroModelBundle_value()
{
	return this->heroModelBundle;
}
string config_HeroAttDB::get_HeroModelName_value()
{
	return this->HeroModelName;
}
int config_HeroAttDB::get_Hp_value()
{
	return this->Hp;
}
int config_HeroAttDB::get_Level_value()
{
	return this->Level;
}
int config_HeroAttDB::get_MPType_value()
{
	return this->MPType;
}
int config_HeroAttDB::get_MPValue_value()
{
	return this->MPValue;
}
int config_HeroAttDB::get_MP_value()
{
	return this->MP;
}
int config_HeroAttDB::get_LevelAddAttackPercent_value()
{
	return this->LevelAddAttackPercent;
}
int config_HeroAttDB::get_LevelAddMAttackPercent_value()
{
	return this->LevelAddMAttackPercent;
}
int config_HeroAttDB::get_LevelAddDefPercent_value()
{
	return this->LevelAddDefPercent;
}
int config_HeroAttDB::get_fff1_value()
{
	return this->fff1;
}
int config_HeroAttDB::get_LevelAddMDefPercent_value()
{
	return this->LevelAddMDefPercent;
}
int config_HeroAttDB::get_MoveSpeed_value()
{
	return this->MoveSpeed;
}
int config_HeroAttDB::get_LevelAddMoveSpeed_value()
{
	return this->LevelAddMoveSpeed;
}
int config_HeroAttDB::get_HPSpeed_value()
{
	return this->HPSpeed;
}
int config_HeroAttDB::get_LevelAddHpSpeedPercent_value()
{
	return this->LevelAddHpSpeedPercent;
}
int config_HeroAttDB::get_qweqe_value()
{
	return this->qweqe;
}
int config_HeroAttDB::get_t_value()
{
	return this->t;
}
int config_HeroAttDB::set_fields_value(vector<string> value)
{
	int str0=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str0;
	this->heroAtlas=value[1];
	this->heroIcon=value[2];
	this->heroModelBundle=value[3];
	this->HeroModelName=value[4];
	int str5=ConfigTableBase::convert<string,int>(value[5]);
	this->Hp=str5;
	int str6=ConfigTableBase::convert<string,int>(value[6]);
	this->Level=str6;
	int str7=ConfigTableBase::convert<string,int>(value[7]);
	this->MPType=str7;
	int str8=ConfigTableBase::convert<string,int>(value[8]);
	this->MPValue=str8;
	int str9=ConfigTableBase::convert<string,int>(value[9]);
	this->MP=str9;
	int str10=ConfigTableBase::convert<string,int>(value[10]);
	this->LevelAddAttackPercent=str10;
	int str11=ConfigTableBase::convert<string,int>(value[11]);
	this->LevelAddMAttackPercent=str11;
	int str12=ConfigTableBase::convert<string,int>(value[12]);
	this->LevelAddDefPercent=str12;
	int str13=ConfigTableBase::convert<string,int>(value[13]);
	this->fff1=str13;
	int str14=ConfigTableBase::convert<string,int>(value[14]);
	this->LevelAddMDefPercent=str14;
	int str15=ConfigTableBase::convert<string,int>(value[15]);
	this->MoveSpeed=str15;
	int str16=ConfigTableBase::convert<string,int>(value[16]);
	this->LevelAddMoveSpeed=str16;
	int str17=ConfigTableBase::convert<string,int>(value[17]);
	this->HPSpeed=str17;
	int str18=ConfigTableBase::convert<string,int>(value[18]);
	this->LevelAddHpSpeedPercent=str18;
	int str19=ConfigTableBase::convert<string,int>(value[19]);
	this->qweqe=str19;
	int str20=ConfigTableBase::convert<string,int>(value[20]);
	this->t=str20;
	return 0;
}
int config_HeroAttDB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_HeroAttDB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	cout<<"heroAtlas: "<<this->heroAtlas<<endl;
	cout<<"heroIcon: "<<this->heroIcon<<endl;
	cout<<"heroModelBundle: "<<this->heroModelBundle<<endl;
	cout<<"HeroModelName: "<<this->HeroModelName<<endl;
	cout<<"Hp: "<<this->Hp<<endl;
	cout<<"Level: "<<this->Level<<endl;
	cout<<"MPType: "<<this->MPType<<endl;
	cout<<"MPValue: "<<this->MPValue<<endl;
	cout<<"MP: "<<this->MP<<endl;
	cout<<"LevelAddAttackPercent: "<<this->LevelAddAttackPercent<<endl;
	cout<<"LevelAddMAttackPercent: "<<this->LevelAddMAttackPercent<<endl;
	cout<<"LevelAddDefPercent: "<<this->LevelAddDefPercent<<endl;
	cout<<"fff1: "<<this->fff1<<endl;
	cout<<"LevelAddMDefPercent: "<<this->LevelAddMDefPercent<<endl;
	cout<<"MoveSpeed: "<<this->MoveSpeed<<endl;
	cout<<"LevelAddMoveSpeed: "<<this->LevelAddMoveSpeed<<endl;
	cout<<"HPSpeed: "<<this->HPSpeed<<endl;
	cout<<"LevelAddHpSpeedPercent: "<<this->LevelAddHpSpeedPercent<<endl;
	cout<<"qweqe: "<<this->qweqe<<endl;
	cout<<"t: "<<this->t<<endl;
	cout<<"classId: "<<config_HeroAttDB::classId<<endl;
	return 0;
}
int config_HeroAttDB::get_classId_value()
{
	return classId;
}


int config_ItemDB::classId=0;
config_ItemDB::config_ItemDB()
{
	classId=802;
}
config_ItemDB::~config_ItemDB()
{
}
int config_ItemDB::get_id_value()
{
	return this->id;
}
string config_ItemDB::get_ItemTypeName_value()
{
	return this->ItemTypeName;
}
vector<int> config_ItemDB::get_SubItemArray_value()
{
	return this->SubItemArray;
}
int config_ItemDB::get_CompoundPrice_value()
{
	return this->CompoundPrice;
}
int config_ItemDB::get_SellPricePercent_value()
{
	return this->SellPricePercent;
}
int config_ItemDB::get_pileCout_value()
{
	return this->pileCout;
}
int config_ItemDB::get_ItemLimitId_value()
{
	return this->ItemLimitId;
}
vector<int> config_ItemDB::get_ItemAttGroup_value()
{
	return this->ItemAttGroup;
}
vector<int> config_ItemDB::get_skillGroup_value()
{
	return this->skillGroup;
}
string config_ItemDB::get_simpleDes_value()
{
	return this->simpleDes;
}
int config_ItemDB::set_fields_value(vector<string> value)
{
	int str0=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str0;
	this->ItemTypeName=value[1];
	SubItemArray={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size();
	for(int k=0;k<length2;k++)
	{
		int str=ConfigTableBase::convert<string,int>(value2[k]);
		this->SubItemArray.push_back(str);
	}
	int str3=ConfigTableBase::convert<string,int>(value[3]);
	this->CompoundPrice=str3;
	int str4=ConfigTableBase::convert<string,int>(value[4]);
	this->SellPricePercent=str4;
	int str5=ConfigTableBase::convert<string,int>(value[5]);
	this->pileCout=str5;
	int str6=ConfigTableBase::convert<string,int>(value[6]);
	this->ItemLimitId=str6;
	ItemAttGroup={};
	vector<string> value7=StrToVector(value[7],"#");
	int length7=value7.size();
	for(int k=0;k<length7;k++)
	{
		int str=ConfigTableBase::convert<string,int>(value7[k]);
		this->ItemAttGroup.push_back(str);
	}
	skillGroup={};
	vector<string> value8=StrToVector(value[8],"#");
	int length8=value8.size();
	for(int k=0;k<length8;k++)
	{
		int str=ConfigTableBase::convert<string,int>(value8[k]);
		this->skillGroup.push_back(str);
	}
	this->simpleDes=value[9];
	return 0;
}
int config_ItemDB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_ItemDB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	cout<<"ItemTypeName: "<<this->ItemTypeName<<endl;
	for(int value : SubItemArray)
	{
			cout<<"SubItemArray: "<<value<<endl;
	}
	cout<<"CompoundPrice: "<<this->CompoundPrice<<endl;
	cout<<"SellPricePercent: "<<this->SellPricePercent<<endl;
	cout<<"pileCout: "<<this->pileCout<<endl;
	cout<<"ItemLimitId: "<<this->ItemLimitId<<endl;
	for(int value : ItemAttGroup)
	{
			cout<<"ItemAttGroup: "<<value<<endl;
	}
	for(int value : skillGroup)
	{
			cout<<"skillGroup: "<<value<<endl;
	}
	cout<<"simpleDes: "<<this->simpleDes<<endl;
	cout<<"classId: "<<config_ItemDB::classId<<endl;
	return 0;
}
int config_ItemDB::get_classId_value()
{
	return classId;
}


int config_SkillDB::classId=0;
config_SkillDB::config_SkillDB()
{
	classId=803;
}
config_SkillDB::~config_SkillDB()
{
}
int config_SkillDB::get_id_value()
{
	return this->id;
}
int config_SkillDB::get_ownerType_value()
{
	return this->ownerType;
}
int config_SkillDB::get_ownerID_value()
{
	return this->ownerID;
}
string config_SkillDB::get_ownerName_value()
{
	return this->ownerName;
}
int config_SkillDB::get_exclusionSkillGroupId_value()
{
	return this->exclusionSkillGroupId;
}
int config_SkillDB::get_skilltype_value()
{
	return this->skilltype;
}
int config_SkillDB::get_skillCD_value()
{
	return this->skillCD;
}
string config_SkillDB::get_skillDes_value()
{
	return this->skillDes;
}
int config_SkillDB::get_arg1_value()
{
	return this->arg1;
}
int config_SkillDB::get_arg2_value()
{
	return this->arg2;
}
int config_SkillDB::set_fields_value(vector<string> value)
{
	int str0=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str0;
	int str1=ConfigTableBase::convert<string,int>(value[1]);
	this->ownerType=str1;
	int str2=ConfigTableBase::convert<string,int>(value[2]);
	this->ownerID=str2;
	this->ownerName=value[3];
	int str4=ConfigTableBase::convert<string,int>(value[4]);
	this->exclusionSkillGroupId=str4;
	int str5=ConfigTableBase::convert<string,int>(value[5]);
	this->skilltype=str5;
	int str6=ConfigTableBase::convert<string,int>(value[6]);
	this->skillCD=str6;
	this->skillDes=value[7];
	int str8=ConfigTableBase::convert<string,int>(value[8]);
	this->arg1=str8;
	int str9=ConfigTableBase::convert<string,int>(value[9]);
	this->arg2=str9;
	return 0;
}
int config_SkillDB::get_fields_value()
{
	cout<<"~~~~~~~~~~~~~~config_SkillDB~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"id: "<<this->id<<endl;
	cout<<"ownerType: "<<this->ownerType<<endl;
	cout<<"ownerID: "<<this->ownerID<<endl;
	cout<<"ownerName: "<<this->ownerName<<endl;
	cout<<"exclusionSkillGroupId: "<<this->exclusionSkillGroupId<<endl;
	cout<<"skilltype: "<<this->skilltype<<endl;
	cout<<"skillCD: "<<this->skillCD<<endl;
	cout<<"skillDes: "<<this->skillDes<<endl;
	cout<<"arg1: "<<this->arg1<<endl;
	cout<<"arg2: "<<this->arg2<<endl;
	cout<<"classId: "<<config_SkillDB::classId<<endl;
	return 0;
}
int config_SkillDB::get_classId_value()
{
	return classId;
}


int config_Sheet1DB::classId=0;
config_Sheet1DB::config_Sheet1DB()
{
	classId=804;
}
config_Sheet1DB::~config_Sheet1DB()
{
}
int config_Sheet1DB::get_id_value()
{
	return this->id;
}
vector<string> config_Sheet1DB::get_fff1_value()
{
	return this->fff1;
}
vector<string> config_Sheet1DB::get_fff2_value()
{
	return this->fff2;
}
vector<string> config_Sheet1DB::get_fff3_value()
{
	return this->fff3;
}
vector<string> config_Sheet1DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet1DB::set_fields_value(vector<string> value)
{
	int str0=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str0;
	fff1={};
	vector<string> value1=StrToVector(value[1],"#");
	int length1=value1.size();
	for(int k=0;k<length1;k++)
	{
		this->fff1.push_back(value1[k]);
	}
	fff2={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size();
	for(int k=0;k<length2;k++)
	{
		this->fff2.push_back(value2[k]);
	}
	fff3={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size();
	for(int k=0;k<length3;k++)
	{
		this->fff3.push_back(value3[k]);
	}
	fff4={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size();
	for(int k=0;k<length4;k++)
	{
		this->fff4.push_back(value4[k]);
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
	classId=805;
}
config_Sheet2DB::~config_Sheet2DB()
{
}
int config_Sheet2DB::get_id_value()
{
	return this->id;
}
vector<string> config_Sheet2DB::get_fff1_value()
{
	return this->fff1;
}
vector<string> config_Sheet2DB::get_fff2_value()
{
	return this->fff2;
}
vector<string> config_Sheet2DB::get_fff3_value()
{
	return this->fff3;
}
vector<string> config_Sheet2DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet2DB::set_fields_value(vector<string> value)
{
	int str0=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str0;
	fff1={};
	vector<string> value1=StrToVector(value[1],"#");
	int length1=value1.size();
	for(int k=0;k<length1;k++)
	{
		this->fff1.push_back(value1[k]);
	}
	fff2={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size();
	for(int k=0;k<length2;k++)
	{
		this->fff2.push_back(value2[k]);
	}
	fff3={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size();
	for(int k=0;k<length3;k++)
	{
		this->fff3.push_back(value3[k]);
	}
	fff4={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size();
	for(int k=0;k<length4;k++)
	{
		this->fff4.push_back(value4[k]);
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
	classId=806;
}
config_Sheet3DB::~config_Sheet3DB()
{
}
int config_Sheet3DB::get_id_value()
{
	return this->id;
}
vector<string> config_Sheet3DB::get_fff1_value()
{
	return this->fff1;
}
vector<string> config_Sheet3DB::get_fff2_value()
{
	return this->fff2;
}
vector<string> config_Sheet3DB::get_fff3_value()
{
	return this->fff3;
}
vector<string> config_Sheet3DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet3DB::set_fields_value(vector<string> value)
{
	int str0=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str0;
	fff1={};
	vector<string> value1=StrToVector(value[1],"#");
	int length1=value1.size();
	for(int k=0;k<length1;k++)
	{
		this->fff1.push_back(value1[k]);
	}
	fff2={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size();
	for(int k=0;k<length2;k++)
	{
		this->fff2.push_back(value2[k]);
	}
	fff3={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size();
	for(int k=0;k<length3;k++)
	{
		this->fff3.push_back(value3[k]);
	}
	fff4={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size();
	for(int k=0;k<length4;k++)
	{
		this->fff4.push_back(value4[k]);
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
	classId=807;
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
vector<int> config_Sheet4DB::get_fff6_value()
{
	return this->fff6;
}
vector<string> config_Sheet4DB::get_fff1_value()
{
	return this->fff1;
}
vector<string> config_Sheet4DB::get_fff2_value()
{
	return this->fff2;
}
vector<string> config_Sheet4DB::get_fff3_value()
{
	return this->fff3;
}
vector<string> config_Sheet4DB::get_fff4_value()
{
	return this->fff4;
}
int config_Sheet4DB::set_fields_value(vector<string> value)
{
	int str0=ConfigTableBase::convert<string,int>(value[0]);
	this->id=str0;
	this->fff0=value[1];
	fff6={};
	vector<string> value2=StrToVector(value[2],"#");
	int length2=value2.size();
	for(int k=0;k<length2;k++)
	{
		int str=ConfigTableBase::convert<string,int>(value2[k]);
		this->fff6.push_back(str);
	}
	fff1={};
	vector<string> value3=StrToVector(value[3],"#");
	int length3=value3.size();
	for(int k=0;k<length3;k++)
	{
		this->fff1.push_back(value3[k]);
	}
	fff2={};
	vector<string> value4=StrToVector(value[4],"#");
	int length4=value4.size();
	for(int k=0;k<length4;k++)
	{
		this->fff2.push_back(value4[k]);
	}
	fff3={};
	vector<string> value5=StrToVector(value[5],"#");
	int length5=value5.size();
	for(int k=0;k<length5;k++)
	{
		this->fff3.push_back(value5[k]);
	}
	fff4={};
	vector<string> value6=StrToVector(value[6],"#");
	int length6=value6.size();
	for(int k=0;k<length6;k++)
	{
		this->fff4.push_back(value6[k]);
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
	if(classname=="config_HeroAttDB")
	{
		base=new config_HeroAttDB();
	}
	else if(classname=="config_ItemDB")
	{
		base=new config_ItemDB();
	}
	else if(classname=="config_SkillDB")
	{
		base=new config_SkillDB();
	}
	else if(classname=="config_Sheet1DB")
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
