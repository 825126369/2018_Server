//============================================================================
// Name        : MariaDbToCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <mysql.h>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;

int ConnectMariadb();
int ReSolveTableInfo();
string ChangeFieldType(string name,enum_field_types value);
class TableInfo {
public:
	static string db;
	string table;
	string primarykey;
	vector<string> datanameList;
	vector<string> datatypeList;
};
int GenerateCpp(vector<TableInfo> mClassInfoList);
void Help();
void PrintConnectionInfo();
MYSQL* connection;
string db = "game";
string ip = "127.0.0.1";
string user = "root";
string password = "123456";
string TableInfo::db = "game";
string hname = "DbTable.h";
string cppname = "DbTable.cpp";
string hbasename = "DbTableBase";
string customFieldPrefix="custom_";

int main(int length, char** msg) {
	if (length < 5) 
	{
		string args="";
		for(int i=0;i<length;i++)
		{
			args+=msg[i];
			
		}
		cout<<args<<endl;
		
	} else {
		ip = msg[1];
		user = msg[2];
		password = msg[3];
		db = msg[4];
	}
	PrintConnectionInfo();
	ConnectMariadb();
	mysql_close(connection);
	cout << "Finish MariaDB To CPP" << endl;
	return 0;
}
void Help() {
	cout << "Help:" << endl;
	cout << "arg1 ：mariadb server ip address" << endl;
	cout << "arg2 ：user name" << endl;
	cout << "arg3 ：user password" << endl;
	cout << "arg4 ：database name" << endl;
}
void PrintConnectionInfo() {
	cout << "connect mariadb server ip address: " << ip << endl;
	cout << "user name : " << user << endl;
	cout << "user password : " << password << endl;
	cout << "database name: " << db << endl;
}

int ConnectMariadb() {
	connection = mysql_init(NULL);
	connection = mysql_real_connect(connection, ip.c_str(), user.c_str(),
			password.c_str(), NULL, 0, NULL, 0);
	if (connection == NULL) {
		cerr << "mysql connection Error: MYSQL* is NULL" << endl;
		exit(1);
	}
	string sqlcommand = "use " + db;

	int aaa = mysql_query(connection, sqlcommand.c_str());
	cout << "connect databse :" << db << endl;
	ReSolveTableInfo();
	return 0;
}
//Find ALL Table Structure Info
int ReSolveTableInfo() 
{
	string command = "show tables";
	cout << "sql command:" << command << endl;
	int EffectRows = mysql_query(connection, command.c_str());
	cout << "effect rows:" << EffectRows << endl;
	if (EffectRows == 1) 
	{
		cerr << "sql Error:" << mysql_error(connection) << endl;
		exit(1);
	}
	MYSQL_RES* res = mysql_store_result(connection);
	if (res) 
	{
		vector<TableInfo> mClassInfoList;
		while (true) 
		{
			MYSQL_ROW row = mysql_fetch_row(res);
			if (row != NULL) 
			{
				for (int r = 0; r < mysql_num_fields(res); r++) 
				{
					TableInfo mTableInfo;
					string str = row[r];
					cout << "table name : " << str << endl;
					mTableInfo.table = str;
					string sqlcommand = "select * from " + str;
					cout << "sql command:" << sqlcommand << endl;
					int EffectRows = mysql_query(connection,sqlcommand.c_str());
					cout << "effect rows:" << EffectRows << endl;
					if (EffectRows == 1) 
					{
						cerr << "sql Error:" << mysql_error(connection) << endl;
						exit(1);
					}
					MYSQL_RES* res1 = mysql_store_result(connection);
					if (res1) 
					{
						while (true) 
						{
							MYSQL_FIELD * mArray0 = mysql_fetch_field(res1);
							if (mArray0 != NULL) 
							{
								cout << mArray0->name << endl;
								cout << mArray0->type << endl;
								mTableInfo.datanameList.push_back(mArray0->name);
								mTableInfo.datatypeList.push_back(ChangeFieldType(mArray0->name,mArray0->type));
								if ((mArray0->flags & PRI_KEY_FLAG)) 
								{
									if (mArray0->flags & AUTO_INCREMENT_FLAG) 
									{
										cerr << "FLAG:  main key setting error" << endl;
									} else 
									{
										cout << "FLAG:  " << mArray0->flags<< endl;
										cout << "key:  "<< (mArray0->flags & PRI_KEY_FLAG) << endl;
										cout << "unqiue:  "<< (mArray0->flags & UNIQUE_KEY_FLAG)<< endl;
										cout << "AUTO_INCREMENT_FLAG:  "<< (mArray0->flags & AUTO_INCREMENT_FLAG)<< endl;
										mTableInfo.primarykey = mArray0->name;
									}
								}
							} else 
							{
								break;
							}
						}
					}
					mClassInfoList.push_back(mTableInfo);
					cout << "class cout ：" << mClassInfoList.size() << endl;
				}
				GenerateCpp(mClassInfoList);
			} else 
			{
				break;
			}
		}
	}
	//free result memory
	mysql_free_result(res);
}

string ChangeFieldType(string name,enum_field_types value) 
{
	string str = "";
	if(name.find(customFieldPrefix)!=-1)
	{
		int pos1=name.find(customFieldPrefix);
		str=name.substr(pos1+7)+"*";	
	}else
	{				
		switch (value) 
		{
		case MYSQL_TYPE_TINY:
			str = "unsigned char";
			break;
		case MYSQL_TYPE_LONG:
			str = "unsigned int";
			break;
		case MYSQL_TYPE_LONGLONG:
			str="unsigned long";
			break;
		case MYSQL_TYPE_VAR_STRING:
			str = "string";
			break;
		case MYSQL_TYPE_BLOB:
			str = "vector<unsigned char>*";
			break;
		default:
			cerr << "type Change Failed:" << value << "error" << endl;
			abort();
			break;
		}
	}
	return str;
}

int GenerateCpp(vector<TableInfo> mClassInfoList) 
{
	if (mClassInfoList.size() > 0) 
	{
		cout << "class cout：" << mClassInfoList.size() << endl;
		string dbname = TableInfo::db;
		//generate .h file
		ofstream mfile;
		mfile.open(hname.c_str(), ios_base::out | ios_base::trunc);
		string mClassStr = "";
		mClassStr +="#ifndef SRC_MARIADBMANAGER_DBTABLE_H\n#define SRC_MARIADBMANAGER_DBTABLE_H\n";
		mClassStr += "#include <string>\n#include \"MariaDBSystem.h\"\n#include \"db_protobuf.pb.h\"\n#include \"db_protobuf_struct.pb.h\"\nusing namespace db_protobuf;\nusing namespace std;\n";
		mClassStr += "namespace basic\n{\n";

		for (vector<TableInfo>::iterator iter = mClassInfoList.begin();iter < mClassInfoList.end(); iter++) 
		{
			string classname = (*iter).table;
			vector<string> nameList = (*iter).datanameList;
			vector<string> typeList = (*iter).datatypeList;
			string keyname = (*iter).primarykey;
			int Length = nameList.size();
			mClassStr += "class " + classname + ":public " + hbasename + "\n{\npublic:\n";
			mClassStr += "\t" + classname + "();\n";
			string gouzaoStr2="\t" + classname + "(";
			string gouzaoStr = "\t" + classname + "(";
			string setallStr = "\tint set_all_value(";
			string getallStr = "\tint get_all_value();";
			string otherStr = "";
			string keyStr = "";
			string primarykeyStr = "\tint set_primarykey_value(";
			for (int i = 0; i < Length; i++) 
			{
				string name = nameList[i];
				string type = typeList[i];
				if (keyname == name) 
				{
					keyStr += "\tint create_key_" + name + "_value();\n";
					keyStr += "\tbool has_key_" + name + "_value();\n";
					keyStr += "\t" + type + " get_key_" + name + "_value();\n\n";

					gouzaoStr += type + " " + name + "_value);\n";
					gouzaoStr2+=type + " " + name + "_value,bool OrAutoCreateDb);\n\n";

					primarykeyStr = "\tint set_key_" + name + "_value(" + type + " value,bool orAutoCreateDb=false);\n";
				} else 
				{
					if(name.find(customFieldPrefix)!=-1)
					{
						otherStr += "\tint set_" + name + "_value(" + type+ " value);\n";	
						//mClassStr+="\tbool has_"+name+"_value(" + type+ " value);\n";
						otherStr += "\t" + type + " get_" + name + "_value();\n";
						setallStr += type + " " + name + "_value,";
					}else
					{
						otherStr += "\tint set_" + name + "_value(" + type+ " value);\n";
						//mClassStr+="\tbool has_"+name+"_value(" + type+ " value);\n";
						otherStr += "\t" + type + " get_" + name + "_value();\n";
						setallStr += type + " " + name + "_value,";
					}
				}
			}
			mClassStr += gouzaoStr;
			mClassStr+=gouzaoStr2;
			mClassStr += primarykeyStr;
			mClassStr += keyStr;
			mClassStr += otherStr;
			setallStr.erase(setallStr.end() - 1);
			mClassStr += "\n" + setallStr + ");\n";
			mClassStr += getallStr + "\n";
			mClassStr += "protected:\n";
			mClassStr += "\tvirtual string get_database_value();\n";
			mClassStr += "\tvirtual string get_tablename_value();\n";
			mClassStr += "\tvirtual string get_primarykeyname_value();\n";
			mClassStr += "private:\n";
			for (int i = 0; i < Length; i++) 
			{
				string name = nameList[i];
				string type = typeList[i];
				mClassStr += "\t" + type + " " + name + ";\n";
				mClassStr += "\tbool OrGetDb_" + name + ";\n";
			}

			mClassStr += "\tstatic string database;\n";
			mClassStr += "\tstatic string tablename;\n";
			mClassStr += "\tstatic string primarykeyname;\n";

			mClassStr += "public:\n";
			mClassStr += "\tstatic int classId;\n";
			mClassStr += "};\n";
		}
		mClassStr += "}\n";
		mClassStr += "#endif";
		mfile << mClassStr << endl;
		mfile.close();

		//generate CPP
		mfile.open(cppname.c_str(), ios_base::out | ios_base::trunc);
		mClassStr = "";
		mClassStr += "#include \"" + hname + "\"\n";
		mClassStr += "namespace basic{\n";
		int classID = 100;
		for (vector<TableInfo>::iterator iter = mClassInfoList.begin();iter < mClassInfoList.end(); iter++) 
		{
			string dbname = db;
			string classname = (*iter).table;
			string primarykey = (*iter).primarykey;
			classID += 1;
			vector<string> nameList = (*iter).datanameList;
			vector<string> typeList = (*iter).datatypeList;
			int Length = nameList.size();

			mClassStr += "string " + classname + "::database=\"" + dbname+ "\";\n";
			mClassStr += "string " + classname + "::tablename=\"" + classname+ "\";\n";
			mClassStr += "string " + classname + "::primarykeyname=\""+ primarykey + "\";\n";

			string classId = "";
			stringstream ss;
			ss << classID;
			ss >> classId;
			mClassStr += "int " + classname + "::classId=" + classId + ";\n";

			string gouzaoStr = classname + "::" + classname + "(";
			string gouzaoStr1=classname + "::" + classname + "()\n{\n";
			string gouzaoStr2=classname + "::" + classname + "(";

			int getallLength=0;
			string getallStrHead="int "+classname+"::get_all_value()\n{\n";
			getallStrHead+="\tstring fieldlist[]={";
			string getallStrEnd="";

			string setallStrHead="int "+classname+"::set_all_value(";
			string setallStrHead1="";
			string setallStrHead2="\tstring fieldlist[]={";
			//mClassStr += classname + "::" + classname+ "()\n{\n";
			//mClassStr += "\n}\n";
			for (int i = 0; i < Length; i++) 
			{
				string name = nameList[i];
				string type = typeList[i];
				string custom_typename ={};
				if(name.find(customFieldPrefix)!=-1)
				{
					int pos1=name.find(customFieldPrefix);
					custom_typename=name.substr(pos1+7);
				}
				gouzaoStr1+="\tOrGetDb_"+name+"=false"+";\n";

				if (primarykey == name) 
				{
					mClassStr += "int " + classname + "::create_key_" + name+ "_value()\n{\n";
					mClassStr += "\tCreatePrimaryKey(\"" + name+ "\",primarykeyvalue);\n";
					mClassStr += "\treturn 0;\n";
					mClassStr += "}\n";

					mClassStr += "bool " + classname + "::has_key_" + name+ "_value()\n{\n";
					mClassStr += "\tget_key_" + name+ "_value();\n\treturn OrGetDb_"+name+";\n}\n";

					gouzaoStr += type + " " + name + "_value)\n{\n";
					gouzaoStr += "\tset_key_"+name+"_value("+name+"_value,false);\n";
					gouzaoStr+="\t"+classname+"();\n}\n";

					gouzaoStr2 += type + " " + name + "_value,bool OrAutoCreate)\n{\n";
					gouzaoStr2 += "\tset_key_"+name+"_value("+name+"_value,OrAutoCreate);\n";
					gouzaoStr2+="\t"+classname+"();\n}\n";
					if (type == "string") 
					{
						mClassStr += type + " " + classname + "::get_key_"+ name + "_value()\n{\n";
						mClassStr += "\tif(OrGetDb_" + name + "==false)\n\t{\n";
						mClassStr += "\t\tstring str=get_field_value(\"" + name+ "\");\n";
						mClassStr += "\t\t" + name + "=str;\n";
						mClassStr +="\t\tif(str==primarykeyvalue && str!=\"\")\n\t\t{\n";
						mClassStr += "\t\t\tOrGetDb_" + name+ "=true;\n\t\t}\n\t}\n";
						mClassStr += "\treturn " + name + ";\n";
						mClassStr += "}\n";

						mClassStr += "int " + classname + "::set_key_" + name+ "_value(" + type + " " + name+ "_value,bool orAutoCreateDb)\n{\n";
						mClassStr += "\t" + name + "=" + name + "_value;\n";
						mClassStr += "\tprimarykeyvalue=" + name+ "_value;\n";

						mClassStr+="\tif(orAutoCreateDb==true && has_key_"+name+"_value()==false)\n\t{\n";
						mClassStr+="\t\tcreate_key_"+name+"_value();\n\t}\n}\n";

					} else 
					{
						mClassStr += type + " " + classname + "::get_key_"+ name + "_value()\n{\n";
						mClassStr += "\tif(OrGetDb_" + name + "==false)\n\t{\n";
						mClassStr += "\t\tstring str=get_field_value(\"" + name+ "\");\n";
						mClassStr += "\t\t" + type + " value=" + hbasename+ "::convert<string," + type + ">(str);\n";
						mClassStr += "\t\t" + name + "=value;\n";
						mClassStr +="\t\tif(str==primarykeyvalue && str!=\"\")\n\t\t{\n";
						mClassStr += "\t\t\tOrGetDb_" + name+ "=true;\n\t\t}\n\t}\n";
						mClassStr += "\treturn " + name + ";\n";
						mClassStr += "}\n";


						mClassStr += "int " + classname + "::set_key_" + name + "_value(" + type + " " + name+ "_value,bool orAutoCreateDb)\n{\n";
						mClassStr += "\t" + name + "=" + name + "_value;\n";
						mClassStr += "\tstring str=" + hbasename + "::convert<"+ type + ",string>(" + name + "_value);\n";
						mClassStr += "\tprimarykeyvalue=str;\n";
						mClassStr+="\tif(orAutoCreateDb==true && has_key_"+name+"_value()==false)\n\t{\n";
						mClassStr+="\t\tcreate_key_"+name+"_value();\n\t}\n}\n";
					}
				} else 
				{
					setallStrHead+=type+" "+name+"_value,";
					setallStrHead1+="\t"+name+"="+name+"_value;\n";
					setallStrHead1+="\tOrGetDb_"+name+"=true;\n";
					setallStrHead2+="\""+name+"\","+name+"Str,";

					getallStrHead+="\""+name+"\",";
					getallStrEnd+="\tOrGetDb_"+name+"=true;\n";
					string getallLengthStr="";
					stringstream ss;
					ss<<getallLength;
					ss>>getallLengthStr;
					ss.clear();
					if (type == "string") 
					{
						mClassStr += "int " + classname + "::set_" + name+ "_value(" + type + " value)\n{\n";
						mClassStr+="\t"+name+"=value;\n";
						mClassStr+="\tOrGetDb_"+name+"=true;\n";
						mClassStr += "\tset_field_value(\"" + name+ "\",value);\n";
						mClassStr += "\treturn 0;\n";
						mClassStr += "}\n";

						mClassStr += type + " " + classname + "::get_" + name+ "_value()\n{\n";
						mClassStr += "\tif(OrGetDb_" + name + "==false)\n\t{\n";
						mClassStr += "\t\tstring str=get_field_value(\"" + name+ "\");\n";
						mClassStr += "\t\t" + name + "=str;\n";
						mClassStr += "\t\tOrGetDb_" + name + "=true;\n"+ "\t}\n";
						mClassStr += "\treturn " + name + ";\n";
						mClassStr += "}\n";

						getallStrEnd+="\t"+name+"=valuelist["+getallLengthStr+"];\n";
						setallStrHead1+="\tstring "+name+"Str="+name+"_value;\n";
					} else
					{
						if(name.find(customFieldPrefix)!=-1)
						{
							mClassStr += "int " + classname + "::set_" + name+ "_value(" + type + " value)\n{\n";
							mClassStr+="\t"+name+"=value;\n";
						}else
						{
							mClassStr += "int " + classname + "::set_" + name+ "_value(" + type + " value)\n{\n";
							mClassStr+="\t"+name+"=value;\n";
						}
						mClassStr+="\tOrGetDb_"+name+"=true;\n";
						if(name.find(customFieldPrefix)!=-1)
						{
							mClassStr += "\tstring str=" + hbasename + "::Serialize<"+ custom_typename + ">("+name+");\n";
						}else
						{
							mClassStr += "\tstring str=" + hbasename + "::convert<"+ type + ",string>("+name+");\n";
						}
						mClassStr += "\t" + hbasename + "::set_field_value(\""+ name + "\",str);\n ";
						mClassStr += "\treturn 0;\n";
						mClassStr += "}\n";

						mClassStr += type + " " + classname + "::get_" + name+ "_value()\n{\n";
						mClassStr += "\tif(OrGetDb_" + name + "==false)\n\t{\n";
						mClassStr += "\t\tstring str=get_field_value(\"" + name+ "\");\n";
						if(name.find(customFieldPrefix)!=-1)
						{
							mClassStr += "\t\t" + type + " value=" + hbasename+ "::DeSerialize<"+custom_typename+">(str);\n";
						}else
						{
							mClassStr += "\t\t" + type + " value=" + hbasename+ "::convert<string," + type + ">(str);\n";
						}
						mClassStr += "\t\t" + name + "=value;\n";
						mClassStr += "\t\tOrGetDb_" + name + "=true;\n"+ "\t}\n";
						mClassStr += "\treturn " + name + ";\n}\n";
						if(name.find(customFieldPrefix)!=-1)
						{	
							getallStrEnd+= "\t"+name+"=" + hbasename+ "::DeSerialize<" + custom_typename + ">(valuelist["+getallLengthStr+"]);\n";
							setallStrHead1+="\tstring "+name+"Str="+hbasename+ "::Serialize<"+custom_typename+">("+name+");\n";
						}else
						{
							getallStrEnd+= "\t"+name+"=" + hbasename+ "::convert<string," + type + ">(valuelist["+getallLengthStr+"]);\n";
							setallStrHead1+="\tstring "+name+"Str="+hbasename+ "::convert<"+type+",string>("+name+");\n";
						}			
					}
					getallLength++;
				}
			}
			mClassStr+=gouzaoStr1+"}\n";
			mClassStr += gouzaoStr;
			mClassStr += gouzaoStr2;

			getallStrHead.erase(getallStrHead.end()-1);
			getallStrHead+="};\n";
			mClassStr+=getallStrHead;
			mClassStr+="\tsize_t length=sizeof(fieldlist)/sizeof(string);\n";
			mClassStr+="\tvector<string> result(fieldlist,fieldlist+length);\n";
			mClassStr+="\tvector<string> valuelist="+hbasename+"::get_all_value(result);\n";
			mClassStr+=getallStrEnd;
			mClassStr+="\treturn 0;\n";
			mClassStr+= "}\n";

			setallStrHead.erase(setallStrHead.end()-1);
			setallStrHead+=")\n{\n";
			setallStrHead2.erase(setallStrHead2.end()-1);
			setallStrHead2+="};\n";
			mClassStr+= setallStrHead;
			mClassStr+= setallStrHead1;
			mClassStr+= setallStrHead2;
			mClassStr+="\tsize_t length=sizeof(fieldlist)/sizeof(string);\n";
			mClassStr+="\tvector<string> result(fieldlist,fieldlist+length);\n";
			mClassStr+="\t"+hbasename+"::set_all_value(result);\n";
			mClassStr+="\treturn 0;\n";
			mClassStr+= "}\n";

			mClassStr += "string " + classname + "::get_database_value()\n{\n";
			mClassStr += "\treturn database;\n}\n";
			mClassStr += "string " + classname + "::get_tablename_value()\n{\n";
			mClassStr += "\treturn tablename;\n}\n";
			mClassStr += "string " + classname+ "::get_primarykeyname_value()\n{\n";
			mClassStr += "\treturn primarykeyname;\n}\n";
			mClassStr += "\n";
		}
		mClassStr += "}";
		mfile << mClassStr << endl;
	}
	return 0;

}
