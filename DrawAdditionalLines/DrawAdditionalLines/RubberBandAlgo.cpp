#include "StdAfx.h"
#include "RubberBandAlgo.h"

RubberBandAlgo::RubberBandAlgo(void)
{
	LineNum = 0;
}

RubberBandAlgo::~RubberBandAlgo(void)
{
}

double RubberBandAlgo::getVectorLength(Vector2D* v){
	return pow( ( v->GetVectorX() * v->GetVectorX() ) + ( v->GetVectorY() * v->GetVectorY() ), 0.5 );
}

double RubberBandAlgo::dotProduct(Vector2D* vL,Vector2D* vR){
	return vL->GetVectorX() * vR->GetVectorX() + vL->GetVectorY() * vR->GetVectorY();
}

double RubberBandAlgo::AngleOf2Vector(Vector2D* A,Vector2D* B){

	double length_A = getVectorLength(A);
	double length_B = getVectorLength(B);

	double cosSita = dotProduct(A,B)/(length_A * length_B);

	double sita = acos(cosSita);
	//printf("sita = %f\n",sita*180/3.14);
	//sita = sita*180/3.14;
	return sita; 
}

Vector2D* RubberBandAlgo::ConvertVector(Vector2D* A,Segment* segment_b){
	Vector2D* v = new Vector2D();
	v->SetVectorWorld(segment_b->getWorldAnchorX(),segment_b->getWorldAnchorY());
	v->SetVector(segment_b->getWorldAnchorX() - A->GetVectorWorldX(),segment_b->getWorldAnchorY() - A->GetVectorWorldY());
	//�v�C���@�Z�O�����g�̔ԍ���v->SegmentNumber�ɑ��
	return v;
}

Vector2D* RubberBandAlgo::ConvertFirstVector(Segment* segment){
	Vector2D* v = new Vector2D();
	v->SetVectorWorld(segment->getWorldAnchorX(),segment->getWorldAnchorY());
	v->SetVector(0,10000);
	return v;
}


Segment* RubberBandAlgo::FindFirstPoint(Curve* curve){

	Segment* traceSegment = curve->WorldChild;
	
	int x = traceSegment->getWorldAnchorX();
	traceSegment = traceSegment->next;
		
	Segment* BaseSegment;
	for(int i=1; i< curve->SegmentNum;i++){
		if(x > traceSegment->getWorldAnchorX() ){
			x = traceSegment->getWorldAnchorX();
			BaseSegment = traceSegment;
		}
		traceSegment = traceSegment->next;
	}

	return BaseSegment;	
}

Vector2D* RubberBandAlgo::FindNextPoint(Curve* curve,Vector2D* A){

	Segment* nextSegment = curve->WorldChild;
	Segment* EndSegment;
	
	Vector2D* B;

	//��_�̃x�N�g����
	double radian = 2*3.14;
	while(nextSegment->next != NULL){
		
		B = ConvertVector(A,nextSegment);
		
		if(radian > AngleOf2Vector(A,B)){
			radian = AngleOf2Vector(A,B);
			EndSegment = nextSegment;
		}			

		if(A->GetVectorWorldX() == nextSegment->next->getWorldAnchorX() && 	A->GetVectorWorldY() == nextSegment->next->getWorldAnchorY()){
			nextSegment = nextSegment->next->next;		
		}else{
			nextSegment = nextSegment->next;
		}

	}

	B = ConvertVector(A,EndSegment);

	

	return B;
}

void RubberBandAlgo::CreateLine(Vector2D* A,Vector2D* B){
	AdditionalLine* line = new AdditionalLine();
	line->setAnchor(A->GetVectorWorldX(),A->GetVectorWorldY(),B->GetVectorWorldX(),B->GetVectorWorldY());
	AddLine.push_back(line);
	LineNum++;
}

bool RubberBandAlgo::CanCreateLine(Vector2D* A,Vector2D* B){
	Segment* segment;
	segment = SegmentA;
	//�v�C���@A��B��SegmentNumber��<�ד��m>or<1�ƍŌ�>��������false��Ԃ�
	while(segment->next = NULL){
		if(segment->getWorldAnchorX() == A->GetVectorWorldX() && segment->next->getWorldAnchorX() == B->GetVectorWorldX()){
			return false;
		}
		segment = segment->next;
	}
	return true;

}

//�v�C��

std::vector<AdditionalLine*> RubberBandAlgo::getInsertLine(Curve* curve){
	printf("------------RubberBandBegin-------------\n");	
	
	//��_�����߂āA�x�N�g����
	SegmentA = curve->WorldChild;
	//�ō��_�Əc�_�̃x�N�g�������߂�
	Vector2D* A = ConvertFirstVector(FindFirstPoint(curve));
	Vector2D* A_Main = A;
	Vector2D* B;

	

	//��_���ō��_�Ɣ������I��
	
	do{
	//��_����_���Z�o
	B = FindNextPoint(curve,A);
	//printf("%d %d %d %d",A->GetVectorWorldX(),A->GetVectorWorldY(),B->GetVectorWorldX(),B->GetVectorWorldY());
	
	//��_�Ɗ�_�̃A���J�[�|�C���g���J�X�g�����R���e�i�֊i�[
	
	
	//if(CanCreateLine(A,B) == true){
		CreateLine(A,B);
	//}
	

	//��_����_�Ƃ���
	A = B;
	
	}while(A_Main->GetVectorWorldX() != A->GetVectorWorldX());

	
	
	printf("------------RubberBandEnd-------------\n");
	return AddLine;
}


std::vector<AdditionalLine*> RubberBandAlgo::rubberBand(std::vector<Field*> field){
		printf("\naaaaa\n");
	printf("\nnum = %d\n",field[0]->inSide->SegmentNum);


	return getInsertLine(field[0]->inSide);

}