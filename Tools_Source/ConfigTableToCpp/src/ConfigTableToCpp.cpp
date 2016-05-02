//============================================================================
// Name        : ConfigTableToCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <libxml/tree.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct ClassInfo {
	string classname;
	vector<string> comment;
	vector<string> datatype;
	vector<string> dataname;
};

void ReadXML(string path);
string GetTrimStr(xmlChar* str);
int GenerateConfigTableCpp(vector<ClassInfo> mClassInfoList);

string hbasename = "ConfigTableBase";
string hname = "ConfigTable.h";
string cppname = "ConfigTable.cpp";
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ReadXML("/home/xuke/Project/Git_Client/Server/Config/Data/DB_Server.xml");
	return 0;
}

void ReadXML(string path) {
	xmlDocPtr doc;
	doc = xmlParseFile(path.c_str());
	xmlNodePtr root = xmlDocGetRootElement(doc);
	cout << "Root: " << root->name << endl;
	vector<ClassInfo> mClassInfoList;

	xmlNodePtr rootchild = root->children;
	while (rootchild != NULL) {
		if (rootchild->type == XML_ELEMENT_NODE) {
			int i = 0;
			ClassInfo mClassInfo;

			cout << "rootchild: " << rootchild->name << endl;
			string tablename = (char*) rootchild->name;
			tablename.erase(tablename.end() - 1);
			tablename = "config_" + tablename;
			mClassInfo.classname = tablename;

			xmlNodePtr mNode1 = rootchild->children;
			while (mNode1 != NULL) {
				if (mNode1->type == XML_ELEMENT_NODE) {
					//cout << "mNode1: " << mNode1->name << endl;
					xmlNodePtr mNode2 = mNode1->children;
					int j = 0;
					while (mNode2 != NULL) {
						if (mNode2->type == XML_ELEMENT_NODE) {
							//cout << "mNode2:" << mNode2->name << endl;
							xmlNodePtr mNode3 = mNode2->children;
							while (mNode3 != NULL) {
								if (mNode3->type == XML_TEXT_NODE) {
									cout << mNode3->name << ": "
											<< mNode3->content << endl;
									if (i == 0) {
										mClassInfo.comment.push_back(
												(char*) mNode3->content);
									} else if (i == 1) {
										mClassInfo.datatype.push_back(
												(char*) mNode3->content);
									} else if (i == 2) {
										mClassInfo.dataname.push_back(
												(char*) mNode3->content);
									}
									j++;

								}
								mNode3 = mNode3->next;
							}

						}
						mNode2 = mNode2->next;
					}
					if (i == 2) {
						break;
					}
					i++;
				}
				mNode1 = mNode1->next;
			}
			mClassInfoList.push_back(mClassInfo);
		}
		rootchild = rootchild->next;
	}
	xmlFreeDoc(doc);

	GenerateConfigTableCpp(mClassInfoList);

}
int GenerateConfigTableCpp(vector<ClassInfo> mClassInfoList) {
	if (mClassInfoList.size() > 0) {
		cout << "数量：" << mClassInfoList.size() << endl;
		ofstream mfile;

		//生成.h文件
		mfile.open(hname.c_str(), ios_base::out | ios_base::trunc);
		string mClassStr = "";
		mClassStr +=
				"#ifndef SRC_MARIADBMANAGER_DBTABLE_H\n#define SRC_MARIADBMANAGER_DBTABLE_H\n";
		mClassStr +=
				"#include <string>\n#include <vector>\n#include \"ConfigTableManager.h\"\nusing namespace std;\n";
		mClassStr += "namespace basic{\n";
		int classId=100;
		for (vector<ClassInfo>::iterator iter = mClassInfoList.begin();
				iter < mClassInfoList.end(); iter++) {
			classId+=100;
			string classname = (*iter).classname;
			vector<string> nameList = (*iter).dataname;
			vector<string> typeList = (*iter).datatype;
			int Length = nameList.size();
			mClassStr += "class " + classname + ":public " + hbasename
					+ "\n{\npublic:\n";
			for (int i = 0; i < Length; i++) {
				string name = nameList[i];
				string type = typeList[i];
				mClassStr += "\t" + type + " get_" + name + "_value();\n";
			}
			mClassStr += "public:\n";
			mClassStr +="\tint set_fields_value(vector<string> value) override;\n";
			mClassStr +="\tint get_fields_value() override;\n";
			mClassStr +="\t"+classname+"();\n";
			mClassStr +="\tvirtual ~"+classname+"();\n";
			mClassStr += "protected:\n";
			mClassStr+= "\tvirtual int get_classId_value() override;\n";
			mClassStr += "private:\n";
			for (int i = 0; i < Length; i++) {
				string name = nameList[i];
				string type = typeList[i];
				mClassStr += "\t" + type + " " + name + ";\n";
			}
			mClassStr += "public:\n";
			mClassStr += "\tstatic int classId;\n";
			mClassStr += "};\n";
		}
		mClassStr += "ConfigTableBase* LoadTableCpp(string classname);\n";
		mClassStr += "}\n";
		mClassStr += "#endif";
		mfile << mClassStr << endl;
		mfile.close();

		//生成CPP
		mfile.open(cppname.c_str(), ios_base::out | ios_base::trunc);
		mClassStr = "";
		mClassStr += "#include \"" + hname + "\"\n";
		mClassStr += "namespace basic{\n";
		for (vector<ClassInfo>::iterator iter = mClassInfoList.begin();iter < mClassInfoList.end(); iter++) {
			classId+=1;
			string classname = (*iter).classname;
			vector<string> nameList = (*iter).dataname;
			vector<string> typeList = (*iter).datatype;
			int Length = nameList.size();

			mClassStr += "int "+classname+"::classId=0;\n";
			mClassStr += "" + classname+ "::"+classname+"()\n{\n";
			string classIdStr = "";
							static stringstream stream;
							stream << classId; //向流中传值
							stream >> classIdStr; //向result中写入值
							stream.clear();
			mClassStr += "\tclassId="+classIdStr+";\n";
			mClassStr += "}\n";

			mClassStr += "" + classname+ "::~"+classname+"()\n{\n";
						mClassStr += "}\n";

			for (int i = 0; i < Length; i++) {
				string name = nameList[i];
				string type = typeList[i];

				mClassStr += type + " " + classname + "::get_" + name
						+ "_value()\n{\n";
				mClassStr += "\treturn this->" + name + ";\n";
				mClassStr += "}\n";

			}

			mClassStr += "int " + classname
					+ "::set_fields_value(vector<string> value)\n{\n";
			for (int i = 0; i < Length; i++) {
				string name = nameList[i];
				string type = typeList[i];
				string iStr = "";
				static stringstream stream;
				stream << i; //向流中传值
				stream >> iStr; //向result中写入值
				stream.clear();
				if (type == "string") {
					mClassStr += "\tthis->" + name + "=value[" + iStr + "];\n";
				} else {
					mClassStr += "\t" + type + " str=" + hbasename
							+ "::convert<string," + type + ">(value[" + iStr
							+ "]);\n";
					mClassStr += "\tthis->" + name + "=str;\n";
				}
			}
			mClassStr += "\treturn 0;\n";
			mClassStr += "}\n";

			mClassStr += "int " + classname
					+ "::get_fields_value()\n{\n";
			mClassStr+="\tcout<<\"~~~~~~~~~~~~~~"+classname+"~~~~~~~~~~~~~~~~~\"<<endl;\n";
			for (int i = 0; i < Length; i++) {
				string name = nameList[i];
				string type = typeList[i];

				mClassStr += "\tcout<<\""+name+": \"<<this->" + name + "<<endl;\n";

			}
			mClassStr+="\tcout<<\"classId: \"<<"+classname+"::classId<<endl;\n";
			mClassStr += "\treturn 0;\n";
			mClassStr += "}\n";

			mClassStr += "int "+classname+"::get_classId_value()\n{\n";
			mClassStr +="\treturn classId;\n}\n";
		}
		mClassStr += "\n";
		mClassStr += "ConfigTableBase* LoadTableCpp(string classname)\n{\n";
		mClassStr += "\tConfigTableBase* base=NULL;\n";
		for (vector<ClassInfo>::iterator iter = mClassInfoList.begin();
				iter < mClassInfoList.end(); iter++) {
			string classname = (*iter).classname;
			if (iter == mClassInfoList.begin()) {
				mClassStr += "\tif(classname==\"" + classname + "\")\n\t{\n";
				mClassStr += "\t\tbase=new " + classname + "();\n\t}\n";
			} else {
				mClassStr += "\telse if(classname==\"" + classname
						+ "\")\n\t{\n";
				mClassStr += "\t\tbase=new " + classname + "();\n\t}\n";
			}
		}
		mClassStr += "\treturn base;\n";
		mClassStr += "}\n";
		mClassStr += "}";

		mfile << mClassStr << endl;

	}
	return 0;
}

string GetTrimStr(xmlChar* str) {
	string content = (char*) str;
	content = content.substr(content.find_first_not_of(" "),
			content.find_last_not_of(" "));
	return content;
}
