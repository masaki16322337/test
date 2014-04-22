#include "StdAfx.h"
#include "GroupObject.h"

GroupObject::GroupObject(CArchive& _archive,CArchive& _archiveWrite) : 
archive(_archive),archiveWrite(_archiveWrite)
{
	CountID = 0;
}

GroupObject::~GroupObject(void)
{
}

void GroupObject::SetObjectNum(int _num){
	ObjectNum = _num;
}

int GroupObject::GetObjectNum(){
	return ObjectNum;
}

Object* GroupObject::CreateObject(){
	Object *p = new Object(archive,archiveWrite);
	if ( p == NULL){
		printf("ERROE:cannot new ");
		exit(EXIT_FAILURE);
	}
	p->prev = NULL;
	p->next = NULL;
	return p;
}

void GroupObject::AddObject(Object *PreObject){
	Object* newObject = CreateObject();
	PreObject->next = newObject;
	newObject->prev = PreObject;
	newObject->next = NULL;
}

void GroupObject::CreateTree(){

	Object* PreObject;
	int CountID = 0;
	
	for(int i = 0 ; i < ObjectNum;i++){
		if(i == 0){
			Object* newObject = CreateObject();
			this->child = newObject;
			PreObject = newObject;
		}else{
			AddObject(PreObject);
			PreObject = PreObject->next;
		}
	
		
		PreObject->SetCurveNum();//子オブジェクト以下の曲線の数を代入
		CountID = PreObject->CreateTree(CountID);//子オブジェクトを木構造で
		PreObject->SetNumSeri();//オブジェクトの後半値をシリアライズ
		PreObject->CreateWorldTree();
		
	}

}

void GroupObject::SetObjectNumSeri(){
	Serialize(archive);
	ObjectNum = num;
	printf(">%d\n",num);
}

void GroupObject::OutTree(){
		
	num = ObjectNum;
	Serialize(archiveWrite);
	child->OutTree();
	
}


Curve* GroupObject::getCurve(int _CurveID){

	Object* object = child;
	while(object->existCurve(_CurveID) != true){
		object = object->next;
		}
	Curve* NewCurve = object->getCurve(_CurveID);

	return NewCurve;

}

Curve* GroupObject::CreateFrameCurve(){
	Object* object = CreateObject();
	Curve *curve = object->CreateFrameCurve();
	//printf("----%d %d----\n",curve->WorldChild->next->getWorldAnchorX(),curve->WorldChild->next->getWorldAnchorY());
	return curve;
}

void GroupObject::InsertLine(AdditionalLine* NewLine){
	
	//InsertLine* insertLine;
	ObjectNum++;
	Object* object;
	object = child;

	while(object->next != NULL){
		object = object->next;	
	}
	
	AddObject(object);

	object->next->ObjectID = object->ObjectID + 1;
	object->next->InsertLine(NewLine);

}


