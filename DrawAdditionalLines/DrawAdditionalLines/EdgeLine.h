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
	//�̈�ɑ΂��Đ܂�ږ@�ő}������ׂ��J�X�g�������i�[�����R���e�i��Ԃ��֐�
	std::vector<AdditionalLine*> getInsertLine(Curve* curve);
	void getInsertLinew(Curve* curve);
public:
	EdgeLine(void);
	~EdgeLine(void);
//�փS���@�̃C���^�[�t�F�[�X�֐�
	std::vector<AdditionalLine*> edgeLine(std::vector<Field*> field);
	
};
