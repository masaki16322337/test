#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include "AdditionalLine.h"
#include "Field.h"
#include "Curve.h"
#include "Segment.h"

class Field;
class EdgeLine
{
	std::vector<AdditionalLine*> AddLine;
	//領域に対して折り目法で挿入するべきカストリ線を格納したコンテナを返す関数
	std::vector<AdditionalLine*> getInsertLine(Curve* curve);
	void getInsertLinew(Curve* curve);
public:
	EdgeLine(void);
	~EdgeLine(void);
//輪ゴム法のインターフェース関数
	std::vector<AdditionalLine*> edgeLine(std::vector<Field*> field);
	
};
