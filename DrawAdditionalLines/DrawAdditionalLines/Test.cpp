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
	//////////////////領域化///////////////////////
	for(int i = 0;i < confFile->GetFieldNum();i++){
		if(i != 0){
			confFile->ResetConfFile();//領域情報を再取得
			fields.push_back(CreateNewField(confFile,groupObject));//領域の作成
		}else{
			fields.push_back(CreateMainField(confFile,groupObject));//主領域の作成
		}
	}
	//printf("\nnumP = %d\n",fields[0]->Property);
	
	//データ構造にカストリ線のオブジェクトを追加する
	////////////////////////////////////////////////
	///////////////カストリ線挿入処理///////////////
	InsertLines(groupObject,fields);//

	////////////////////////////////////////////////
	printf("-----Output File-----\n");
	groupObject->OutTree();//出力処理

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

	//要修正
	//作成領域の内側領域数と属性を入力
	NewField->SetInCurveNum(confFile->GetInFieldNum());
	NewField->SetProperty(confFile->GetFieldParam());

	//内側領域を作成
	for(int i = 0;i < confFile->GetInFieldNum() ; i++){
		NewField->inSide = groupObject->getCurve(confFile->GetInFieldID()[i]);
		NewField->inSideField.push_back(groupObject->getCurve(confFile->GetInFieldID()[i]));
	}
	//外側領域を作成
	NewField->outSide = groupObject->CreateFrameCurve();

	return NewField;
}



void Test::InsertLines(GroupObject* groupObject,vector<Field*> field){

	//要修正
	//与えられた領域にカストリ線を引く
	//field[0]->GetInsertLineValue();

	
	lines = addLineManager.AddLine(field);

	//カストリ線の数だけオブジェクトの数を追加する
	int a = lines.size();

	for(int i = 0; i<a;i++){
		groupObject->InsertLine(lines[i]);
	}


}