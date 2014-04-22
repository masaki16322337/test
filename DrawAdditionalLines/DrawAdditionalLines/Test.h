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
	
	//��̈���쐬����֐�
	Field* CreateMainField(ConfFile* confFile,GroupObject* groupObject);
	
	//�̈�ɃJ�X�g�����������N���X
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
	* �V�����̈���쐬����֐�
	*/
	Field* CreateNewField(ConfFile* confFile,GroupObject* groupObject);

};
