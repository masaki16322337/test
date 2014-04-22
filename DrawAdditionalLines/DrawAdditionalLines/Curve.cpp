#include "StdAfx.h"
#include "Curve.h"

Curve::Curve(CArchive& _archive,CArchive& _archiveWrite) : archive(_archive),archiveWrite(_archiveWrite)
{
}

Curve::~Curve(void)
{
}

void Curve::SetSegmentNum(int value){
	SegmentNum = value;

}

void Curve::SetCloseCurve(int value){
	CloseCurve = value;
}

Segment* Curve::CreateSegment(){
	Segment* p = new Segment(archive,archiveWrite);
	if ( p == NULL){
		printf("ERROE:cannot new ");
		exit(EXIT_FAILURE);
	}
	p->prev = NULL;
	p->next = NULL;
	return p;
}

void Curve::AddSegment(Segment* PreSegment){
	Segment* newSegment = CreateSegment();

	PreSegment->next = newSegment;
			
	newSegment->prev = PreSegment;


}

void Curve::CreateTree(int _CurveID,Object* object){

	Segment* PreEntitySegment;

	CurveID = _CurveID;
	printf("---%d---\n",CurveID);

	for(int i = 0 ; i < SegmentNum;i++){

		if(i == 0){
			Segment* newEntitySegment = CreateSegment();
			
			this->EntityChild = newEntitySegment;
			
			PreEntitySegment = newEntitySegment;
			
		}else{

			AddSegment(PreEntitySegment);
			
			PreEntitySegment = PreEntitySegment->next;
		}


		PreEntitySegment->CreateTree();
		

	}


}

void Curve::CreateWorldTree(Object *object){
	Segment* PreWorldSegment;
	Segment* PreEntitySegment = EntityChild;
	printf("------%d-------\n",SegmentNum);
	
	for(int i = 0 ; i < SegmentNum;i++){

		if(i == 0){
			Segment* newWorldSegment = CreateSegment();
			
			this->WorldChild = newWorldSegment;

			PreWorldSegment = newWorldSegment;

		}else{

			AddSegment(PreWorldSegment);

			PreWorldSegment = PreWorldSegment->next;
			PreEntitySegment = PreEntitySegment->next;
		}

		PreWorldSegment->CreateWorldTree(PreEntitySegment,object);
	}
}

void Curve::SetNumSeri(){
		Serialize(archive);
		SetCloseCurve(num);
		printf("  >%d\n",num);
		
		Serialize(archive);
		SetSegmentNum(num);
		printf("  >%d\n",num);

}

void Curve::OutTree(){

	num = CloseCurve;
	Serialize(archiveWrite);
	num = SegmentNum;
	Serialize(archiveWrite);
	EntityChild->OutTree();
	if(next != NULL){


	next->OutTree();
	}

	
}

void Curve::InsertLine(AdditionalLine* NewLine){
	SegmentNum = 2;
	CloseCurve = 0;

	Segment* newSegmentBegin = CreateSegment();
	Segment* newSegmentEnd = CreateSegment();
	
	this->EntityChild = newSegmentBegin;
	newSegmentBegin->next = newSegmentEnd;
	newSegmentEnd->prev = newSegmentBegin;
	
	newSegmentBegin->InsertLine(NewLine,true);
	newSegmentEnd->InsertLine(NewLine,false);
	
}


Curve* Curve::getCurve(int _CurveID){

	Curve *NewCurve;
	NewCurve = this;

	while(1){
		if(NewCurve->CurveID == _CurveID){
			return NewCurve;
		}

		NewCurve = NewCurve->next;
	
	}

}

bool Curve::existCurveID(int _CurveID){
	if(CurveID == _CurveID){
		return true;
	}
	return false;
	
}

void Curve::CreateFrameCurve(){

	SegmentNum = 4;
	Segment* segment = CreateSegment();
	WorldChild = segment;
	segment->CreateFrameCurve(0,0);
	
	Segment* segment_a = CreateSegment();
	segment->next = segment_a;
	segment_a->CreateFrameCurve(60000,0);
	
	Segment* segment_b = CreateSegment();
	segment_a->next = segment_b;
	segment_b->CreateFrameCurve(60000,250000);

	Segment* segment_c = CreateSegment();
	segment_b->next = segment_c;
	segment_c->CreateFrameCurve(0,250000);
}