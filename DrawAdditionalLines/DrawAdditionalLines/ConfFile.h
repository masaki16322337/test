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
	int FieldNum;//�̈搔
	int FieldParam;//�̈摮��
	int InFieldNum;//�����̈搔
	vector<int> InFieldID;//�����̈�̔ԍ�
	int OutFieldID;//�O���̈�̔ԍ�

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
