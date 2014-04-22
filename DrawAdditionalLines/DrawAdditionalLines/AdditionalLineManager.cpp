#include "StdAfx.h"
#include "AdditionalLineManager.h"

AdditionalLineManager::AdditionalLineManager(void)
{
}

AdditionalLineManager::~AdditionalLineManager(void)
{
}

vector<AdditionalLine*> AdditionalLineManager::AddLine(vector<Field*> field){

	//アルゴリズムクラスの宣言
	
	RubberBandAlgo* rubberBandAlgo = new RubberBandAlgo();
	EdgeLine* edgeLines = new EdgeLine();

	//輪ゴム法
	//vector<AdditionalLine*> addLine = rubberBandAlgo->rubberBand(field);

	//折り目法
	vector<AdditionalLine*> addLine = edgeLines->edgeLine(field);

	//カストリ線を追加する
	line.insert(line.end(),addLine.begin(),addLine.end());
	
	return line;
}
