#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class ConfFile
{
private:
	string str;
	int data;
	bool b_data;
	ifstream &ifs;
	int FieldNum;//—Ìˆæ”
	int FieldParam;//—Ìˆæ‘®«
	int InFieldNum;//“à‘¤—Ìˆæ”
	vector<int> InFieldID;//“à‘¤—Ìˆæ‚Ì”Ô†
	int OutFieldID;//ŠO‘¤—Ìˆæ‚Ì”Ô†

public:
	void SetConfFile();
	void ResetConfFile();
	int GetFieldParam();
	int GetFieldNum();
	int GetInFieldNum();
	vector<int> GetInFieldID();
	int GetOutFieldID();
	ConfFile(ifstream& _ifs);
	~ConfFile(void);
};
