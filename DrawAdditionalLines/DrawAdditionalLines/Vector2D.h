#pragma once

class Vector2D
{
private:
	int x;
	int y;
	int WorldX;
	int WorldY;
	int SegmentNumber;

public:
	Vector2D(void);
	~Vector2D(void);
	void SetVector(int _x,int _y);
	void SetVectorWorld(int _WorldX,int _WorldY);
	int GetVectorX();
	int GetVectorY();
	int GetVectorWorldX();
	int GetVectorWorldY();
};
