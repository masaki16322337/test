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

	
	//�̈���w�肷��ƃJ�X�g������Ԃ�
	vector<AdditionalLine*> AddLine(vector<Field*> field);

	
};
