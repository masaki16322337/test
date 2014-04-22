#pragma once

#include "FileSerialize.h"
#include "AdditionalLine.h"


class Object;

class Segment : public FileSerialize
{
private:
	CArchive& archive;
	CArchive& archiveWrite;

	int AnchorX;
	int AnchorY;
	int HandleX1;
	int HandleX2;
	int HandleY1;
	int HandleY2;
	int Angle;

	int WorldAnchorX;
	int WorldAnchorY;
	int WorldHandleX1;
	int WorldHandleX2;
	int WorldHandleY1;
	int WorldHandleY2;
	int WorldAngle;

public:

	Segment* next;
	Segment* prev;


	Segment(CArchive& _archive,CArchive& _archiveWrite);
	~Segment(void);

	/*
	* 入力されたファイルからEntity座標系で木構造を作成する
	*/
	void CreateTree();

	/*
	* 入力されたファイルからWorld座標系で木構造を作成する
	*/
	void CreateWorldTree(Segment* EntitySegment,Object* object);
	void OutTree();
	void GetSegmentSeri();
	
	void InsertLine(AdditionalLine* NewLine,bool BeginOrEnd);
/*
 * 主領域の外曲線を作成する
*/
	void CreateFrameCurve(int x,int y);

	int getAnchorX();
	int getAnchorY();
	int getWorldAnchorX();
	int getWorldAnchorY();
};
