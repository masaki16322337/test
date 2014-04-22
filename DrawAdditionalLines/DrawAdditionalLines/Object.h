#pragma once

#include "FileSerialize.h"
#include "Curve.h"
#include "Field.h"
#include "AdditionalLine.h"

class Object : public FileSerialize
{
public:
	CArchive& archive;
	CArchive& archiveWrite;
	int ObjectID;
	int CountID;

	int CurveNum;

	//CArchive& archive;
	bool ObjectOrUser;

	double ObjectSizeX;
	double ObjectSizeY;
	int AnchorWorldX;
	int AnchorWorldY;
	int AnchorCoordinatesX;
	int AnchorCoordinatesY;
	int AnchorEntityX;
	int AnchorEntityY;


	enum ValueNum{
		CURVE_NUM, 
		OBJECT_SIZE_X, 
		OBJECT_SIZE_Y, 
		ANCHOR_WORLD_X,	
		ANCHOR_WORLD_Y,
		ANCHOR_COORDINATES_X,
		ANCHOR_COORDINATES_Y,
		ANCHOR_ENTITY_X,
		ANCHOR_ENTITY_Y,
	};
		
	ValueNum valueNum;

//public:
	Curve* child;
	int test;
	double d_num;

	Object *next;
	Object *prev;

	Object(CArchive& _archive,CArchive& _archiveWrite);
	~Object(void);

	void SetValue(void* value,int valueNum);

	void SetCurveNum();

/**
 * 曲線クラスのリストを作成する関数
 */
	Curve* CreateCurve();

/**
 * 曲線クラス連結リストの最後にオブジェクトを追加する関数
 * @param list ひとつ前のリスト
 */

	void AddCurve(Curve *PreCurve);

/**
 * 入力ファイルから木構造のデータを作成する関数
 * @ref 曲線のID
 */
	int CreateTree(int _CurveID);

/*
 * segmentクラスのworld座標系配列を作る
*/
	void CreateWorldTree();


	void SetNumSeri();

	void d_Serialize(CArchive& archive);

	void OutTree();

	void GetNumSeri();
	

/*
*カストリ線を挿入する関数
*/
	void InsertLine(AdditionalLine* NewLine);

/*
 * 指定した曲線オブジェクトを取り出す
*/
	bool existCurve(int _CurveID);

/*
 * 指定した曲線オブジェクトを取り出す
*/
	Curve* getCurve(int _CurveID);

/*
 * 主領域の外曲線を作成する
*/
	Curve* CreateFrameCurve();

	
};
