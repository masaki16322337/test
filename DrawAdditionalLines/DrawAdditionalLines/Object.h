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
 * �Ȑ��N���X�̃��X�g���쐬����֐�
 */
	Curve* CreateCurve();

/**
 * �Ȑ��N���X�A�����X�g�̍Ō�ɃI�u�W�F�N�g��ǉ�����֐�
 * @param list �ЂƂO�̃��X�g
 */

	void AddCurve(Curve *PreCurve);

/**
 * ���̓t�@�C������؍\���̃f�[�^���쐬����֐�
 * @ref �Ȑ���ID
 */
	int CreateTree(int _CurveID);

/*
 * segment�N���X��world���W�n�z������
*/
	void CreateWorldTree();


	void SetNumSeri();

	void d_Serialize(CArchive& archive);

	void OutTree();

	void GetNumSeri();
	

/*
*�J�X�g������}������֐�
*/
	void InsertLine(AdditionalLine* NewLine);

/*
 * �w�肵���Ȑ��I�u�W�F�N�g�����o��
*/
	bool existCurve(int _CurveID);

/*
 * �w�肵���Ȑ��I�u�W�F�N�g�����o��
*/
	Curve* getCurve(int _CurveID);

/*
 * ��̈�̊O�Ȑ����쐬����
*/
	Curve* CreateFrameCurve();

	
};
