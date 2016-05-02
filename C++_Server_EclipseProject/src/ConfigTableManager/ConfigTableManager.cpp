/*
 * ConfigTableManager.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: xuke
 */

#include "ConfigTableManager.h"

namespace basic {
ConfigTableManager ConfigTableManager::single;

ConfigTableManager::ConfigTableManager() {
	// TODO Auto-generated constructor stub

}

ConfigTableManager::~ConfigTableManager() {
	// TODO Auto-generated destructor stub
}
ConfigTableManager* ConfigTableManager::getSingle()
{
	return &single;
}
int ConfigTableManager::ReadXML(string path) {
	xmlDocPtr doc;
	doc = xmlParseFile(path.c_str());
	xmlNodePtr root = xmlDocGetRootElement(doc);
	cout << "Root: " << root->name << endl;

	int n=10;
	xmlNodePtr rootchild = root->children;
	while (rootchild != NULL) {
		if (rootchild->type == XML_ELEMENT_NODE) {
			int i = 0;
			map<int, ConfigTableBase*> mMap;
			int classId=0;
			cout << "rootchild: " << rootchild->name << endl;
			string tablename = (char*) rootchild->name;
			tablename.erase(tablename.end() - 1);
			tablename = "config_" + tablename;

			string classname = tablename;
			xmlNodePtr mNode1 = rootchild->children;
			while (mNode1 != NULL) {
				if (mNode1->type == XML_ELEMENT_NODE) {
					cout << "mNode1: " << mNode1->name << endl;
					xmlNodePtr mNode2 = mNode1->children;
					int j=0;
					ConfigTableBase* mClassInfo = LoadTableCpp(classname);
					int id=0;
					if (mClassInfo == NULL) {
						cout << "NULLLLLLL" << endl;
						continue;
					}
					if (i >= 3) {
						vector<string> dataList;
						while (mNode2 != NULL) {
							if (mNode2->type == XML_ELEMENT_NODE) {
								cout << "mNode2:" << mNode2->name << endl;
								xmlNodePtr mNode3 = mNode2->children;
								while (mNode3 != NULL) {
									if (mNode3->type == XML_TEXT_NODE) {
										cout << mNode3->name << ": "
												<< mNode3->content << endl;

										dataList.push_back(
												(char*) mNode3->content);
										if(j==0)
										{
											static stringstream ss;
											ss<<mNode3->content;
											ss>>id;
											ss.clear();
											classId=mClassInfo->get_classId_value();
										}

										j++;

									}
									mNode3 = mNode3->next;
								}

							}
							mNode2 = mNode2->next;
						}
						mClassInfo->set_fields_value(dataList);
						mMap.insert(pair<int, ConfigTableBase*>(id, mClassInfo));
					}
					i++;
				}
				mNode1 = mNode1->next;
			}
			cout << "Collec Size:" << mMap.size() << endl;
			mTableMap.insert(pair<int, map<int, ConfigTableBase*> >(classId, mMap));
			n++;
		}
		rootchild = rootchild->next;
	}
	cout << "CollecList Size:" << mTableMap.size() << endl;
	xmlFreeDoc(doc);

}
int ConfigTableManager::test()
{
	for(map<int,map<int,ConfigTableBase*> >::iterator iter=mTableMap.begin();iter!=mTableMap.end();iter++)
		{
			cout<<"Dic id: "<<(*iter).first<<endl;
			map<int,ConfigTableBase*> aaa=(*iter).second;
			for(map<int,ConfigTableBase*>::iterator iter1=aaa.begin();iter1!=aaa.end();iter1++)
			{
				ConfigTableBase* bbb=(*iter1).second;
				bbb->get_fields_value();
			}
		}
	return 0;
}

ConfigTableBase::ConfigTableBase() {

}

ConfigTableBase::~ConfigTableBase() {

}

} /* namespace basic */
