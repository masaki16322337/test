#include "StdAfx.h"
#include "Object.h"

Object::Object(CArchive& _archive,CArchive& _archiveWrite) : 
archive(_archive),archiveWrite(_archiveWrite)
{
	CountID = 0;
}

Object::~Object(void)
{
}

void Object::SetValue(void* value,int valueNumber){

	
	int *iValue;//intŒ^—p‚Ì“ü—Í•Ï”
	double *dValue;//doubleŒ^—p‚Ì“ü—Í•Ï”

	//@double/intŒ^‚Ì“ü—Í•Ï”‚Ì€”õ
	if(valueNumber == 1 || valueNumber == 2){
		dValue = (double *)value;
	}else{
		iValue = (int *)value;
	}

	//valueNumber‚Ì’l‚É]‚Á‚Ä’l‚Ì‘ã“ü
	switch(valueNumber){
	case CURVE_NUM:
		CurveNum = *iValue;
		break;
	case OBJECT_SIZE_X:
		ObjectSizeX = *dValue;
		break;
	case OBJECT_SIZE_Y:
		ObjectSizeY = *dValue;
		break;
	case ANCHOR_WORLD_X:
		AnchorWorldX = *iValue;
		break;
	case ANCHOR_WORLD_Y:
		AnchorWorldY = *iValue;
		break;
	case ANCHOR_COORDINATES_X:
		AnchorCoordinatesX = *iValue;
		break;
	case ANCHOR_COORDINATES_Y:
		AnchorCoordinatesY = *iValue;
		break;
	case ANCHOR_ENTITY_X:
		AnchorEntityX = *iValue;
		break;
	case ANCHOR_ENTITY_Y:
		AnchorEntityY = *iValue;
		break;
	default:
		printf("’l‚ª³‚µ‚­“ü—Í‚³‚ê‚Ü‚¹‚ñ‚Å‚µ‚½\n");
		exit(1);
		break;
		
	}
}

Curve* Object::CreateCurve(){
	Curve* p = new Curve(archive,archiveWrite);
	if ( p == NULL){
		printf("ERROE:cannot new ");
		exit(EXIT_FAILURE);
	}
	p->prev = NULL;
	p->next = NULL;
	return p;
}

 
void Object::AddCurve(Curve *PreCurve){
	Curve* newCurve = CreateCurve();
	PreCurve->next = newCurve;
	newCurve->prev = PreCurve;
}



int Object::CreateTree(int CountID){
	Curve* PreCurve;

	for(int i = 0 ; i < CurveNum;i++){
		if(i == 0){
			Curve* newCurve = CreateCurve();
			this->child = newCurve;
			PreCurve = newCurve;		
		}else{
			AddCurve(PreCurve);
			PreCurve = PreCurve->next;
		}	

		PreCurve->SetNumSeri();
		PreCurve->CreateTree(CountID++,this);

	}
	return CountID;

}

void Object::CreateWorldTree(){
	
	Curve* PreCurve = child;
	
	for(int i = 0 ; i < CurveNum;i++){
			PreCurve->CreateWorldTree(this);
			PreCurve = PreCurve->next;
	}
}


void Object::SetCurveNum(){
	Serialize(archive);
	CurveNum = num;
	printf(" >%d\n",num);
}



void Object::SetNumSeri(){
	
	d_Serialize(archive);
	ObjectSizeX = d_num;
	printf(">%f\n",d_num);
	
	d_Serialize(archive);
	ObjectSizeY = d_num;
	printf(">%f\n",d_num);

	Serialize(archive);
	AnchorWorldX = num;
	printf(">%d\n",num);

	Serialize(archive);
	AnchorWorldY = num;
	printf(">%d\n",num);

	Serialize(archive);
	AnchorCoordinatesX = num;
	printf(">%d\n",num);

	Serialize(archive);
	AnchorCoordinatesY = num;
	printf(">%d\n",num);

	Serialize(archive);
	AnchorEntityX = num;
	printf(">%d\n",num);

	Serialize(archive);
	AnchorEntityY = num;
	printf(">%d\n",num);
}


void Object::d_Serialize(CArchive& archive){
		if(archive.IsLoading()){
			archive >> d_num;
		
		}else{
			archive << d_num;
		
		}

}

void Object::OutTree(){

	num = CurveNum;
	Serialize(archiveWrite);
				
	child->OutTree();
	GetNumSeri();
	if(next != NULL){
	next->OutTree();
	}

}

void Object::GetNumSeri(){
	
	
	d_num = ObjectSizeX;
	d_Serialize(archiveWrite);

	d_num = ObjectSizeY;
	d_Serialize(archiveWrite);
	
	num = AnchorWorldX;
	Serialize(archiveWrite);

	num = AnchorWorldY;
	Serialize(archiveWrite);

	num = AnchorCoordinatesX;
	Serialize(archiveWrite);

	num = AnchorCoordinatesY;
	Serialize(archiveWrite);

	num = AnchorEntityX;
	Serialize(archiveWrite);

	num = AnchorEntityY;
	Serialize(archiveWrite);
	
}

void Object::InsertLine(AdditionalLine* NewLine){

	CurveNum = 1;
	ObjectSizeX = 1.0;
	ObjectSizeY = 1.0;
	AnchorWorldX = 0;
	AnchorWorldY = 0;
	AnchorCoordinatesX = 0;
	AnchorCoordinatesY = 0;
	AnchorEntityX = 0;
	AnchorEntityY = 0;
	
	Curve* newCurve = CreateCurve();
	child = newCurve;
	newCurve->CurveID = 0;
	child->InsertLine(NewLine);


}


bool Object::existCurve(int _CurveID){
	
	Curve* curve = child;
	
	while(curve != NULL){
		if(curve->CurveID == _CurveID){
			return true;
		}
		curve = curve->next;
	}
	return false;
}

Curve* Object::getCurve(int _CurveID){
	return child->getCurve(_CurveID);
}

Curve* Object::CreateFrameCurve(){
	Curve* curve = CreateCurve();
	child = curve;
	curve->CreateFrameCurve();
	return curve;
}