#pragma once

#include "FileSerialize.h"
#include "GroupObject.h"
#include "Field.h"
#include <fstream>
#include "AdditionalLine.h"
#include "ConfFile.h"
#include <vector>
#include <iostream>
#include "AdditionalLineManager.h"

using namespace std;
class GroupObject;

class Test 
{
private:

	FileSerialize Serial;
	Field field;
	vector<AdditionalLine*> lines;
	AdditionalLineManager addLineManager;
	
	//主領域を作成する関数
	Field* CreateMainField(ConfFile* confFile,GroupObject* groupObject);
	
	//領域にカストリ線を引くクラス
	void InsertLines(GroupObject* groupObject,vector<Field*> field);

public:

	Test(void);
	~Test(void);

	void DoTest();
	void InFile();
	void OutFile();
	void MakeField();
	//void InsertLine(CArchive& ar,CArchive& _ar);


	/*
	* 新しい領域を作成する関数
	*/
	Field* CreateNewField(ConfFile* confFile,GroupObject* groupObject);

};
