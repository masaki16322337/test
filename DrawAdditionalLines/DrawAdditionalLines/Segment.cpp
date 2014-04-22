#include "StdAfx.h"
#include "Segment.h"
#include "Object.h"




Segment::Segment(CArchive& _archive,CArchive& _archiveWrite) : 
archive(_archive),archiveWrite(_archiveWrite)
{

}

Segment::~Segment(void)
{
}

void Segment::CreateTree(){

	Serialize(archive);
	printf("   >%d\n",num);
	AnchorX = num;
	
	Serialize(archive);
	printf("   >%d\n",num);
	AnchorY = num;
	
	Serialize(archive);
	printf("   >%d\n",num);
	HandleX1 = num;

	Serialize(archive);
	printf("   >%d\n",num);
	HandleY1 = num;
	
	Serialize(archive);
	printf("   >%d\n",num);
	HandleX2 = num;

	Serialize(archive);
	printf("   >%d\n",num);
	HandleY2 = num;

	Serialize(archive);
	printf("   >%d\n",num);
	Angle = num;
						
}

void Segment::OutTree(){

	GetSegmentSeri();

	if(next != NULL){
		next->OutTree();
	}
}

void Segment::GetSegmentSeri(){

	num = AnchorX;
	Serialize(archiveWrite);
	num = AnchorY;
	Serialize(archiveWrite);
	num = HandleX1;
	Serialize(archiveWrite);
	num = HandleY1;
	Serialize(archiveWrite);
	num = HandleX2;
	Serialize(archiveWrite);
	num = HandleY2;
	Serialize(archiveWrite);
	num = Angle;
	Serialize(archiveWrite);

	
}

void Segment::CreateWorldTree(Segment* EntitySegment,Object* object){
	
	

	double _WorldAnchorX = 0;
	double _WorldAnchorY = 0;
	double _WorldHandleX1 = EntitySegment->AnchorX + EntitySegment->HandleX1;
	double _WorldHandleX2 = EntitySegment->AnchorX + EntitySegment->HandleX2;
	double _WorldHandleY1 = EntitySegment->AnchorY + EntitySegment->HandleY1;
	double _WorldHandleY2 = EntitySegment->AnchorY + EntitySegment->HandleY2;
	


	// W=(E-EA)*A
	_WorldAnchorX = (EntitySegment->AnchorX - object->AnchorEntityX) * object->ObjectSizeX;
	_WorldAnchorX += ( (_WorldAnchorX > 0) - (_WorldAnchorX < 0) ) * 0.5;
	_WorldAnchorX += object->AnchorWorldX;
	WorldAnchorX = (int)(_WorldAnchorX);
	
	//printf("%d\n",WorldAnchorX);

	_WorldAnchorY = (EntitySegment->AnchorY - object->AnchorEntityY) * object->ObjectSizeY;
	_WorldAnchorY += ( (_WorldAnchorY > 0) - (_WorldAnchorY < 0) ) * 0.5;
	_WorldAnchorY += object->AnchorWorldY;
	WorldAnchorY = (int)(_WorldAnchorY);
	//printf("%d\n",WorldAnchorY);
	
	_WorldHandleX1 = (_WorldHandleX1 - object->AnchorEntityX) * object->ObjectSizeX;
		_WorldHandleX1 += ( (_WorldHandleX1 > 0) - (_WorldHandleX1 < 0) ) * 0.5;
	_WorldHandleX1 += object->AnchorWorldX;
	WorldHandleX1 = (int)(_WorldHandleX1);
	//printf("%d\n",WorldHandleX1);

	_WorldHandleY1 = (_WorldHandleY1 - object->AnchorEntityY) * object->ObjectSizeY;
	_WorldHandleY1 += ( (_WorldHandleY1 > 0) - (_WorldHandleY1 < 0) ) * 0.5;
	_WorldHandleY1 += object->AnchorWorldY;
	WorldHandleY1 = (int)(_WorldHandleY1);
	//printf("%d\n",WorldHandleY1);

	_WorldHandleX2 = (_WorldHandleX2 - object->AnchorEntityX) * object->ObjectSizeX;
	_WorldHandleX2 += ( (_WorldHandleX2 > 0) - (_WorldHandleX2 < 0) ) * 0.5;
	_WorldHandleX2 += object->AnchorWorldX;
	WorldHandleX2 = (int)(_WorldHandleX2);
	//printf("%d\n",WorldHandleX2);


	_WorldHandleY2 = (_WorldHandleY2 - object->AnchorEntityY) * object->ObjectSizeY;
	_WorldHandleY2 += ( (_WorldHandleY2 > 0) - (_WorldHandleY2 < 0) ) * 0.5;
	_WorldHandleY2 += object->AnchorWorldY;
	WorldHandleY2 = (int)(_WorldHandleY2);
	//printf("%d\n\n",WorldHandleY2);
	
}

void Segment::InsertLine(AdditionalLine* NewLine,bool BeginOrEnd){

	if(BeginOrEnd == true){
		AnchorX = NewLine->anchorX1;
	
		AnchorY = NewLine->anchorY1;
	}else{
		AnchorX = NewLine->anchorX2;
	
		AnchorY = NewLine->anchorY2;
	}

	HandleX1 = 0;

	HandleX2 = 0;

	HandleY1 = 0;

	HandleY2 = 0;

	Angle = 0;
}

void Segment::CreateFrameCurve(int x,int y){

	WorldAnchorX = x;
	
	WorldAnchorY = y;

	WorldHandleX1 = 0;

	WorldHandleX2 = 0;

	WorldHandleY1 = 0;

	WorldHandleY2 = 0;

	WorldAngle = 0;
}

int Segment::getAnchorX(){
return AnchorX;
}

int Segment::getAnchorY(){
return AnchorY;
}

int Segment::getWorldAnchorX(){
return WorldAnchorX;
}

int Segment::getWorldAnchorY(){
return WorldAnchorY;
}