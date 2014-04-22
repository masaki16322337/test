#pragma once

#include "FileSerialize.h"

//#include "Field.h"
#include "Segment.h"
#include "AdditionalLine.h"

class Object;

class Curve : public FileSerialize
{
private:
	CArchive& archive;
	CArchive& archiveWrite;




public:
	int CurveID;
	Curve *next;
	Curve *prev;
	Segment* EntityChild;
	Segment* WorldChild;
	//Object* object;



	int SegmentNum;
	int CloseCurve;

	Curve(CArchive& _archive,CArchive& _archiveWrite);
	~Curve(void);
	void SetSegmentNum(int value);
	void SetCloseCurve(int value);
	Segment* CreateSegment();
	void AddSegment(Segment* PreSegment);

/*
 * 入力ファイルから木構造のデータを作成する関数
 * @ref 曲線のID
 */
	void CreateTree(int _CurveID,Object* object);

/*
 * segmentクラスのworld座標系配列を作る
*/
	void CreateWorldTree(Object* object);

	void SetNumSeri();
	void OutTree();
	void InsertLine(AdditionalLine* NewLine);

	/*
	*　指定したCurveIDと一致したらtrueを返す
	*/
	bool existCurveID(int _CurveID);

/*
 * 指定した曲線オブジェクトを取り出す
 */
	Curve* getCurve(int CurveID);

/*
 * 主領域の外曲線を作成する
*/
	void CreateFrameCurve();
};
