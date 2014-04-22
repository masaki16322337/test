#pragma once

class AdditionalLine
{


public:
	int anchorX1;
	int anchorY1;
	int anchorX2;
	int	anchorY2;
	AdditionalLine(void);
	~AdditionalLine(void);
	/*
	* アンカーポイントの入力
	*/
	void setAnchor(int _anchorX1,int _anchorY1,int _anchorX2,int _anchorY2);

};
