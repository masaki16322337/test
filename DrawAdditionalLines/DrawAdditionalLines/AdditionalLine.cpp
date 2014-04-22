#include "StdAfx.h"
#include "AdditionalLine.h"

AdditionalLine::AdditionalLine(void)
{
}

AdditionalLine::~AdditionalLine(void)
{
}

void AdditionalLine::setAnchor(int _anchorX1,int _anchorY1,
							int _anchorX2,int _anchorY2){
 								
anchorX1 = _anchorX1;
anchorY1 = _anchorY1;
anchorX2 = _anchorX2;
anchorY2 = _anchorY2;

}