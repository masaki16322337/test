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

	//ベクトルの長さを計算する
	double getVectorLength(Vector2D* vector);

	//ベクトル内積
	double dotProduct(Vector2D* vectorL,Vector2D* vectorR);

	//2つのベクトルABのラジアンを求める
	double AngleOf2Vector(Vector2D* A,Vector2D* B);

	//セグメントのベクトル化
	Vector2D* ConvertVector(Vector2D* A,Segment* segment_b);

	//基準点のベクトル化
	Vector2D* ConvertFirstVector(Segment* segment);

	//最左端のセグメントを見つける
	Segment* FindFirstPoint(Curve* curve);

	//基準点より基次点を返す
	Vector2D* FindNextPoint(Curve* curve,Vector2D* A);
	
	//始点と終点のセグメントからカストリ線を返す
	void CreateLine(Vector2D* A,Vector2D* B);
	
	//基準点と基次点が隣り合っていればfalseを返す
	bool CanCreateLine(Vector2D* A,Vector2D* B);

	//領域に対して輪ゴム法で挿入するべきカストリ線を格納したコンテナを返す関数
	std::vector<AdditionalLine*> getInsertLine(Curve* curve);
	
public:
	int LineNum;
	Segment* SegmentA;

	RubberBandAlgo();
	~RubberBandAlgo(void);
	
	//輪ゴム法のインターフェース関数
	std::vector<AdditionalLine*> rubberBand(std::vector<Field*> field);
	
};
