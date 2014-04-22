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


	int FieldID;//領域の番号
	double Size;//領域の面積
	int InCurveNum;//領域の内領域数

	vector<AdditionalLine*> AddLine;//カストリ線を格納 

	/*
	* 領域の面積を計算する
	*/
	void CalcFieldSize();
	
	/*
	* 内側の領域の面積を合算する	
	*/
	double InSideFieldSize();
	
	/*
	* 外側領域の面積を計算する
	*/
	double OutSideFieldSize();

	/*
	* 内側領域の面積を計算する
	*/
	double CalcInSideFieldSize(int i);

public:
	int AdditionalLineNum;//カストリ線の数
		int Property;//領域の属性
	Curve *inSide;//内領域
	Curve *outSide;//外領域
	vector<Curve*> inSideField;
	
	Field();
	~Field(void);

	/*
	* 領域の属性値を入力するセッター
	*/
	void SetProperty(int prop);

	/*
	* 領域の内領域数を入力するセッター
	*/
	void SetInCurveNum(int _InCurveNum);

	/*
	* 指定面積以上でかつイキ領域の場合true
	*/
	bool canAddLine();

	/*
	* 主領域の外側曲線(枠線)を作成
	*/
	void CreateFrameCurve();

	/*
	*カストリ線を返す関数
	*/
	AdditionalLine* getAdditionalLine(int i);
	
	void CreateInField(Curve*);
};
