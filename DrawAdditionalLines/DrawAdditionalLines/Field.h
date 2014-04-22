#pragma once

#include <vector>
#include <iostream>
#include <math.h>
#include "Curve.h"
#include "AdditionalLine.h"
#include "RubberBandAlgo.h"

class Segment;
using namespace std;

class Field
{


	int FieldID;//�̈�̔ԍ�
	double Size;//�̈�̖ʐ�
	int InCurveNum;//�̈�̓��̈搔

	vector<AdditionalLine*> AddLine;//�J�X�g�������i�[ 

	/*
	* �̈�̖ʐς��v�Z����
	*/
	void CalcFieldSize();
	
	/*
	* �����̗̈�̖ʐς����Z����	
	*/
	double InSideFieldSize();
	
	/*
	* �O���̈�̖ʐς��v�Z����
	*/
	double OutSideFieldSize();

	/*
	* �����̈�̖ʐς��v�Z����
	*/
	double CalcInSideFieldSize(int i);

public:
	int AdditionalLineNum;//�J�X�g�����̐�
		int Property;//�̈�̑���
	Curve *inSide;//���̈�
	Curve *outSide;//�O�̈�
	vector<Curve*> inSideField;
	
	Field();
	~Field(void);

	/*
	* �̈�̑����l����͂���Z�b�^�[
	*/
	void SetProperty(int prop);

	/*
	* �̈�̓��̈搔����͂���Z�b�^�[
	*/
	void SetInCurveNum(int _InCurveNum);

	/*
	* �w��ʐψȏ�ł��C�L�̈�̏ꍇtrue
	*/
	bool canAddLine();

	/*
	* ��̈�̊O���Ȑ�(�g��)���쐬
	*/
	void CreateFrameCurve();

	/*
	*�J�X�g������Ԃ��֐�
	*/
	AdditionalLine* getAdditionalLine(int i);
	
	void CreateInField(Curve*);
};
