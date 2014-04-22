#include "StdAfx.h"
#include "EdgeLine.h"

EdgeLine::EdgeLine(void)
{
}

EdgeLine::~EdgeLine(void)
{
}

std::vector<AdditionalLine*> EdgeLine::getInsertLine(Curve* curve){

	AdditionalLine* line = new AdditionalLine();
	line->setAnchor(0,10000,10000,0);
	AddLine.push_back(line);
	
	return AddLine;
}

void EdgeLine::getInsertLinew(Curve* curve){

	AdditionalLine* line = new AdditionalLine();
	line->setAnchor(0,10000,10000,0);
	AddLine.push_back(line);
	
}


//std::vector<AdditionalLine*> EdgeLine::edgeLine(std::vector<Field*> field){

//	getInsertLinew(field[0]->inSide);
	
//	return AddLine;

//}

std::vector<AdditionalLine*> EdgeLine::edgeLine(std::vector<Field*> field){

	
	AdditionalLine* line = new AdditionalLine();
	line->setAnchor(0,10000,10000,0);
	AddLine.push_back(line);
	return AddLine;

}