#include "StdAfx.h"
#include "AdditionalLineManager.h"

AdditionalLineManager::AdditionalLineManager(void)
{
}

AdditionalLineManager::~AdditionalLineManager(void)
{
}

vector<AdditionalLine*> AdditionalLineManager::AddLine(vector<Field*> field){

	//�A���S���Y���N���X�̐錾
	
	RubberBandAlgo* rubberBandAlgo = new RubberBandAlgo();
	EdgeLine* edgeLines = new EdgeLine();

	//�փS���@
	//vector<AdditionalLine*> addLine = rubberBandAlgo->rubberBand(field);

	//�܂�ږ@
	vector<AdditionalLine*> addLine = edgeLines->edgeLine(field);

	//�J�X�g������ǉ�����
	line.insert(line.end(),addLine.begin(),addLine.end());
	
	return line;
}
