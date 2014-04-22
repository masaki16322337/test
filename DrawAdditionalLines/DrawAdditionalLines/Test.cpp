#include "StdAfx.h"
#include "Test.h"

vector<Field*> fields;	

Test::Test(void)
{
}

Test::~Test(void)
{
}

void Test::DoTest(){
	InFile();
}

void Test::InFile(){

	//CFile f(_T("data/RubberBand.ojl"), CFile::modeRead);
	//CFile f(_T("data/demo1.ojl"), CFile::modeRead);
	CFile f(_T("data/demo1.ojl"), CFile::modeRead);

	//CFile f(_T("rdg_4.ojl"), CFile::modeRead);
	CArchive ar(&f, CArchive::load);
	CFile _f(_T("data/demo1_insert.ojl"), (CFile::modeCreate | CFile::modeWrite));
	CArchive _ar(&_f, CArchive::store);

	//insert file
	//////////////////////////////////////////////
	GroupObject* groupObject = new GroupObject(ar,_ar);
	groupObject->SetObjectNumSeri();
	groupObject->CreateTree();
	ar.Close();

	//insert config
	printf("-----Insert Config-----\n");
	//////////////////////////////////////////////
	ifstream ifs("MultiInFields.txt");
	//ifstream ifs("FieldData.txt");
	ConfFile* confFile = new ConfFile(ifs);
	confFile->SetConfFile();
	AdditionalLine* NewLine = new AdditionalLine();
	
	//create fields
	printf("-----Create Fields-----\n");
	
	///////////////////////////////////////////////
	//////////////////�̈扻///////////////////////
	for(int i = 0;i < confFile->GetFieldNum();i++){
		if(i != 0){
			confFile->ResetConfFile();//�̈�����Ď擾
			fields.push_back(CreateNewField(confFile,groupObject));//�̈�̍쐬
		}else{
			fields.push_back(CreateMainField(confFile,groupObject));//��̈�̍쐬
		}
	}
	//printf("\nnumP = %d\n",fields[0]->Property);
	
	//�f�[�^�\���ɃJ�X�g�����̃I�u�W�F�N�g��ǉ�����
	////////////////////////////////////////////////
	///////////////�J�X�g�����}������///////////////
	InsertLines(groupObject,fields);//

	////////////////////////////////////////////////
	printf("-----Output File-----\n");
	groupObject->OutTree();//�o�͏���

	_ar.Close();

	////////////////////////////////////////////////
}

void Test::OutFile(){
}

void Test::MakeField(){
}

Field* Test::CreateNewField(ConfFile* confFile,GroupObject* groupObject){

	Field* NewField = new Field();
	NewField->SetInCurveNum(confFile->GetInFieldNum());

	for(int i = 0;i < confFile->GetInFieldNum() ; i++){
		NewField->inSide = groupObject->getCurve(confFile->GetInFieldID()[i]);
		NewField->inSideField.push_back(groupObject->getCurve(confFile->GetInFieldID()[i]));
	}

	NewField->outSide = groupObject->getCurve(confFile->GetOutFieldID());
	NewField->SetProperty(confFile->GetFieldParam());

	return NewField;

}

Field* Test::CreateMainField(ConfFile* confFile,GroupObject* groupObject){
	Field* NewField = new Field();

	//�v�C��
	//�쐬�̈�̓����̈搔�Ƒ��������
	NewField->SetInCurveNum(confFile->GetInFieldNum());
	NewField->SetProperty(confFile->GetFieldParam());

	//�����̈���쐬
	for(int i = 0;i < confFile->GetInFieldNum() ; i++){
		NewField->inSide = groupObject->getCurve(confFile->GetInFieldID()[i]);
		NewField->inSideField.push_back(groupObject->getCurve(confFile->GetInFieldID()[i]));
	}
	//�O���̈���쐬
	NewField->outSide = groupObject->CreateFrameCurve();

	return NewField;
}



void Test::InsertLines(GroupObject* groupObject,vector<Field*> field){

	//�v�C��
	//�^����ꂽ�̈�ɃJ�X�g����������
	//field[0]->GetInsertLineValue();

	
	lines = addLineManager.AddLine(field);

	//�J�X�g�����̐������I�u�W�F�N�g�̐���ǉ�����
	int a = lines.size();

	for(int i = 0; i<a;i++){
		groupObject->InsertLine(lines[i]);
	}


}