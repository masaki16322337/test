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
 * ���̓t�@�C������؍\���̃f�[�^���쐬����֐�
 * @ref �Ȑ���ID
 */
	void CreateTree(int _CurveID,Object* object);

/*
 * segment�N���X��world���W�n�z������
*/
	void CreateWorldTree(Object* object);

	void SetNumSeri();
	void OutTree();
	void InsertLine(AdditionalLine* NewLine);

	/*
	*�@�w�肵��CurveID�ƈ�v������true��Ԃ�
	*/
	bool existCurveID(int _CurveID);

/*
 * �w�肵���Ȑ��I�u�W�F�N�g�����o��
 */
	Curve* getCurve(int CurveID);

/*
 * ��̈�̊O�Ȑ����쐬����
*/
	void CreateFrameCurve();
};
