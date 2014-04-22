#include "StdAfx.h"
#include "Field.h"

Field::Field()
{
	AdditionalLineNum = 0;
}

Field::~Field(void)
{
}

void Field::SetProperty(int _Property){

	Property = _Property;

}

void Field::SetInCurveNum(int _InCurveNum){
	InCurveNum = _InCurveNum;
}

//—vC³


bool Field::canAddLine(){
	CalcFieldSize();
	if(Size > 200000000 && Property == 1){
	//if(Property == 1){
		return true;
	}

	return false;

}


void Field::CalcFieldSize(){
	printf("outSideFieldSize = %.0f\n",OutSideFieldSize());
	printf("inSideFieldSize  = %.0f\n",InSideFieldSize());
	printf("FieldSize        = %.0f\n",OutSideFieldSize() - InSideFieldSize());
	Size = OutSideFieldSize() - InSideFieldSize();
}

double Field::InSideFieldSize(){
	double InSideFieldSizeValue = 0;

	for(int i = 0;i<InCurveNum;i++){
	InSideFieldSizeValue += CalcInSideFieldSize(i);
	//printf("%f\n",InSideFieldSizeValue);
	}

	return InSideFieldSizeValue;

}

double Field::CalcInSideFieldSize(int i){
	
	Segment* segment_a = inSide->WorldChild;
	Segment* segment = inSideField[i]->WorldChild;

	//printf("--%d\n",inSideField[i]->WorldChild->AnchorX);

	double x1,y1 = 0;
	double inFieldSize = 0;
	
	x1 = segment->getWorldAnchorX();
	y1 = segment->getWorldAnchorY();


	for(int k = 0; k < inSide->SegmentNum-1;k++){
		inFieldSize += segment->getWorldAnchorX() * segment->next->getWorldAnchorY();
		inFieldSize -= segment->next->getWorldAnchorX() * segment->getWorldAnchorY();

		segment = segment->next;
	}


		inFieldSize += segment->getWorldAnchorX() * y1;
		inFieldSize -= x1 * segment->getWorldAnchorY();

	return fabs(inFieldSize);


}

double Field::OutSideFieldSize(){
	Segment* segment = outSide->WorldChild;

	double x1,y1 = 0;
	double outFieldSize = 0;
	
	x1 = segment->getWorldAnchorX();
	y1 = segment->getWorldAnchorY();
	

	for(int i = 0; i < outSide->SegmentNum-1;i++){
		outFieldSize += segment->getWorldAnchorX() * segment->next->getWorldAnchorY();
		outFieldSize -= segment->next->getWorldAnchorX() * segment->getWorldAnchorY();
		segment = segment->next;
	//	printf("--%d--\n",outFieldSize);
	}

	//printf("-------------------\n");
		outFieldSize += segment->getWorldAnchorX() * y1;
		outFieldSize -= x1 * segment->getWorldAnchorY();


	
	return fabs(outFieldSize);

}


AdditionalLine* Field::getAdditionalLine(int i){
	return AddLine[i];
}