#pragma once

#include "FileSerialize.h"
#include "test.h"
#include "object.h"
#include "Field.h"
#include "Curve.h"
#include "AdditionalLine.h"

class GroupObject : public FileSerialize
{
private:
	CArchive& archive;
	CArchive& archiveWrite;

	int	ObjectNum;
	int CountID;

public:
	Object* child;
	double d_num;
	int b;
	
	GroupObject(CArchive& _archive,CArchive& _archiveWrite);
	~GroupObject(void);

/*
* �v�f��0�̘A�����X�g���쐬����֐�
*/
Object* CreateLinkedListObject();

/**
 * �I�u�W�F�N�g�̐��������龯��
 */
	void SetObjectNum(int _num);

/*
 *�I�u�W�F�N�g�̐����擾����Q�b�^�[
*/
	int GetObjectNum();

/**
 * ���X�g���쐬����֐�
 */	
	Object* CreateObject();

/**
 * �A�����X�g�̍Ō�ɃI�u�W�F�N�g��ǉ�����֐�
 * @param list �ЂƂO�̃��X�g
 */
	void AddObject(Object* PreObjec);


/**
 * �؍\�����쐬���邽�߂̊֐�
 */
	void CreateTree();

/*
 *�V���A���C�Y�����l��Object�I�u�W�F�N�g�̃����o�ϐ��Ɋi�[����
*/
	void SetObjectNumSeri();

/*
* �؍\����H��֐�
*/
	void OutTree();

/*
 * �w�肵���Ȑ��I�u�W�F�N�g�����o��
*/
	Curve* getCurve(int CurveID);

/*
 * ��̈�ƂȂ�Ȑ��I�u�W�F�N�g���쐬����
*/
	Curve* CreateFrameCurve();

/*
*�J�X�g������}������֐�
*/
	void InsertLine(AdditionalLine* NewLine);


	
};
