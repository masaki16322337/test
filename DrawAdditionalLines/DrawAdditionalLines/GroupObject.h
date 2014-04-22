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
* 要素数0の連結リストを作成する関数
*/
Object* CreateLinkedListObject();

/**
 * オブジェクトの数を代入するｾｯﾀｰ
 */
	void SetObjectNum(int _num);

/*
 *オブジェクトの数を取得するゲッター
*/
	int GetObjectNum();

/**
 * リストを作成する関数
 */	
	Object* CreateObject();

/**
 * 連結リストの最後にオブジェクトを追加する関数
 * @param list ひとつ前のリスト
 */
	void AddObject(Object* PreObjec);


/**
 * 木構造を作成するための関数
 */
	void CreateTree();

/*
 *シリアライズした値をObjectオブジェクトのメンバ変数に格納する
*/
	void SetObjectNumSeri();

/*
* 木構造を辿る関数
*/
	void OutTree();

/*
 * 指定した曲線オブジェクトを取り出す
*/
	Curve* getCurve(int CurveID);

/*
 * 主領域となる曲線オブジェクトを作成する
*/
	Curve* CreateFrameCurve();

/*
*カストリ線を挿入する関数
*/
	void InsertLine(AdditionalLine* NewLine);


	
};
