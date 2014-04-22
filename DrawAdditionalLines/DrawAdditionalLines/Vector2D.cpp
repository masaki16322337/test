#include "StdAfx.h"
#include "Vector2D.h"

Vector2D::Vector2D(void)
{
}

Vector2D::~Vector2D(void)
{
}

void Vector2D::SetVector(int _x,int _y){
	x = _x;
	y = _y;
}

void Vector2D::SetVectorWorld(int _WorldX,int _WorldY){
	WorldX = _WorldX;
	WorldY = _WorldY;
}

int Vector2D::GetVectorX(){
	return x;
}

int Vector2D::GetVectorY(){
	return y;
}

int Vector2D::GetVectorWorldX(){
	return WorldX;
}

int Vector2D::GetVectorWorldY(){
	return WorldY;
}

