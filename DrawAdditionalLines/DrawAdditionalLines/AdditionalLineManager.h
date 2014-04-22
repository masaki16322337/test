#pragma once
#include "Field.h"
#include "AdditionalLine.h"
#include "RubberBandAlgo.h"
#include "EdgeLine.h"
#include <vector>
#include <iostream>



class AdditionalLineManager
{
private:
	vector<Field*> field;
	vector<AdditionalLine*> line;

public:
	AdditionalLineManager(void);
	~AdditionalLineManager(void);

	
	//領域を指定するとカストリ線を返す
	vector<AdditionalLine*> AddLine(vector<Field*> field);

	
};
