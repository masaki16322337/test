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
	* ���͂��ꂽ�t�@�C������Entity���W�n�Ŗ؍\�����쐬����
	*/
	void CreateTree();

	/*
	* ���͂��ꂽ�t�@�C������World���W�n�Ŗ؍\�����쐬����
	*/
	void CreateWorldTree(Segment* EntitySegment,Object* object);
	void OutTree();
	void GetSegmentSeri();
	
	void InsertLine(AdditionalLine* NewLine,bool BeginOrEnd);
/*
 * ��̈�̊O�Ȑ����쐬����
*/
	void CreateFrameCurve(int x,int y);

	int getAnchorX();
	int getAnchorY();
	int getWorldAnchorX();
	int getWorldAnchorY();
};
