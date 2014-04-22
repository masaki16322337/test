#pragma once

#include <vector>
#include <iostream>
#include <math.h>
#include "AdditionalLine.h"
#include "Field.h"
#include "Curve.h"
#include "Segment.h"
#include "Vector2D.h"

class Field;

class RubberBandAlgo
{
	
	std::vector<AdditionalLine*> AddLine;

	//�x�N�g���̒������v�Z����
	double getVectorLength(Vector2D* vector);

	//�x�N�g������
	double dotProduct(Vector2D* vectorL,Vector2D* vectorR);

	//2�̃x�N�g��AB�̃��W�A�������߂�
	double AngleOf2Vector(Vector2D* A,Vector2D* B);

	//�Z�O�����g�̃x�N�g����
	Vector2D* ConvertVector(Vector2D* A,Segment* segment_b);

	//��_�̃x�N�g����
	Vector2D* ConvertFirstVector(Segment* segment);

	//�ō��[�̃Z�O�����g��������
	Segment* FindFirstPoint(Curve* curve);

	//��_����_��Ԃ�
	Vector2D* FindNextPoint(Curve* curve,Vector2D* A);
	
	//�n�_�ƏI�_�̃Z�O�����g����J�X�g������Ԃ�
	void CreateLine(Vector2D* A,Vector2D* B);
	
	//��_�Ɗ�_���ׂ荇���Ă����false��Ԃ�
	bool CanCreateLine(Vector2D* A,Vector2D* B);

	//�̈�ɑ΂��ėփS���@�ő}������ׂ��J�X�g�������i�[�����R���e�i��Ԃ��֐�
	std::vector<AdditionalLine*> getInsertLine(Curve* curve);
	
public:
	int LineNum;
	Segment* SegmentA;

	RubberBandAlgo();
	~RubberBandAlgo(void);
	
	//�փS���@�̃C���^�[�t�F�[�X�֐�
	std::vector<AdditionalLine*> rubberBand(std::vector<Field*> field);
	
};
