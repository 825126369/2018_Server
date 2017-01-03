#ifndef SRC_MARIADBMANAGER_DBTABLE_H
#define SRC_MARIADBMANAGER_DBTABLE_H
#include <string>
#include <vector>
#include <array>
#include "ConfigTableManager.h"
using namespace std;
namespace basic{
class config_HeroAttDB:public ConfigTableBase
{
public:
	int get_id_value();
	string get_heroAtlas_value();
	string get_heroIcon_value();
	string get_heroModelBundle_value();
	string get_HeroModelName_value();
	int get_Hp_value();
	int get_Level_value();
	int get_MPType_value();
	int get_MPValue_value();
	int get_MP_value();
	int get_LevelAddAttackPercent_value();
	int get_LevelAddMAttackPercent_value();
	int get_LevelAddDefPercent_value();
	int get_fff1_value();
	int get_LevelAddMDefPercent_value();
	int get_MoveSpeed_value();
	int get_LevelAddMoveSpeed_value();
	int get_HPSpeed_value();
	int get_LevelAddHpSpeedPercent_value();
	int get_qweqe_value();
	int get_t_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_HeroAttDB();
	virtual ~config_HeroAttDB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	string heroAtlas;
	string heroIcon;
	string heroModelBundle;
	string HeroModelName;
	int Hp;
	int Level;
	int MPType;
	int MPValue;
	int MP;
	int LevelAddAttackPercent;
	int LevelAddMAttackPercent;
	int LevelAddDefPercent;
	int fff1;
	int LevelAddMDefPercent;
	int MoveSpeed;
	int LevelAddMoveSpeed;
	int HPSpeed;
	int LevelAddHpSpeedPercent;
	int qweqe;
	int t;
public:
	static int classId;
};
class config_ItemDB:public ConfigTableBase
{
public:
	int get_id_value();
	string get_ItemTypeName_value();
	vector<int> get_SubItemArray_value();
	int get_CompoundPrice_value();
	int get_SellPricePercent_value();
	int get_pileCout_value();
	int get_ItemLimitId_value();
	vector<int> get_ItemAttGroup_value();
	vector<int> get_skillGroup_value();
	string get_simpleDes_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_ItemDB();
	virtual ~config_ItemDB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	string ItemTypeName;
	vector<int> SubItemArray;
	int CompoundPrice;
	int SellPricePercent;
	int pileCout;
	int ItemLimitId;
	vector<int> ItemAttGroup;
	vector<int> skillGroup;
	string simpleDes;
public:
	static int classId;
};
class config_SkillDB:public ConfigTableBase
{
public:
	int get_id_value();
	int get_ownerType_value();
	int get_ownerID_value();
	string get_ownerName_value();
	int get_exclusionSkillGroupId_value();
	int get_skilltype_value();
	int get_skillCD_value();
	string get_skillDes_value();
	int get_arg1_value();
	int get_arg2_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_SkillDB();
	virtual ~config_SkillDB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	int ownerType;
	int ownerID;
	string ownerName;
	int exclusionSkillGroupId;
	int skilltype;
	int skillCD;
	string skillDes;
	int arg1;
	int arg2;
public:
	static int classId;
};
class config_Sheet1DB:public ConfigTableBase
{
public:
	int get_id_value();
	vector<string> get_fff1_value();
	vector<string> get_fff2_value();
	vector<string> get_fff3_value();
	vector<string> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet1DB();
	virtual ~config_Sheet1DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	vector<string> fff1;
	vector<string> fff2;
	vector<string> fff3;
	vector<string> fff4;
public:
	static int classId;
};
class config_Sheet2DB:public ConfigTableBase
{
public:
	int get_id_value();
	vector<string> get_fff1_value();
	vector<string> get_fff2_value();
	vector<string> get_fff3_value();
	vector<string> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet2DB();
	virtual ~config_Sheet2DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	vector<string> fff1;
	vector<string> fff2;
	vector<string> fff3;
	vector<string> fff4;
public:
	static int classId;
};
class config_Sheet3DB:public ConfigTableBase
{
public:
	int get_id_value();
	vector<string> get_fff1_value();
	vector<string> get_fff2_value();
	vector<string> get_fff3_value();
	vector<string> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet3DB();
	virtual ~config_Sheet3DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	vector<string> fff1;
	vector<string> fff2;
	vector<string> fff3;
	vector<string> fff4;
public:
	static int classId;
};
class config_Sheet4DB:public ConfigTableBase
{
public:
	int get_id_value();
	string get_fff0_value();
	vector<int> get_fff6_value();
	vector<string> get_fff1_value();
	vector<string> get_fff2_value();
	vector<string> get_fff3_value();
	vector<string> get_fff4_value();
public:
	int set_fields_value(vector<string> value) override;
	int get_fields_value() override;
	config_Sheet4DB();
	virtual ~config_Sheet4DB();
protected:
	virtual int get_classId_value() override;
private:
	int id;
	string fff0;
	vector<int> fff6;
	vector<string> fff1;
	vector<string> fff2;
	vector<string> fff3;
	vector<string> fff4;
public:
	static int classId;
};
ConfigTableBase* LoadTableCpp(string classname);
}
#endif
