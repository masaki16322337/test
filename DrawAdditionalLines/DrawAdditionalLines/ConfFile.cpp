#include "StdAfx.h"
#include "ConfFile.h"

ConfFile::ConfFile(ifstream& _ifs):ifs(_ifs)
{

}

ConfFile::~ConfFile(void)
{
}

void ConfFile::SetConfFile(){

	ifs >> str;
	ifs >> data;
	cout << str << data << endl;
	FieldNum = data;

	ifs >> str;
	ifs >> data;
	cout << str << data << endl;
	FieldParam = data;

	ifs >> str;
	ifs >> data;
	cout << str << data << endl;
	OutFieldID = data;

	ifs >> str;
	ifs >> data;
	cout << str << data << endl;
	InFieldNum = data;



	printf("%d\n",InFieldNum);
	for(int i = 0 ;i < InFieldNum ; i++){
		ifs >> str;
		ifs >> data;
		cout << str << data << endl;
		InFieldID.push_back(data);
	}

}

void ConfFile::ResetConfFile(){

	ifs >> str;
	ifs >> data;
	cout << str << data << endl;
	FieldParam = data;

	ifs >> str;
	ifs >> data;
	cout << str << data << endl;
	OutFieldID = data;

	ifs >> str;
	ifs >> data;
	cout << str << data << endl;
	InFieldNum = data;
	printf("a");
	InFieldID.clear();
	for(int i = 0 ;i < InFieldNum ; i++){
		ifs >> str;
		ifs >> data;
		cout << str << data << endl;
		InFieldID.push_back(data);
	}
}

int ConfFile::GetFieldParam(){
	return FieldParam;
}

int ConfFile::GetFieldNum(){
	return FieldNum;
}

int ConfFile::GetInFieldNum(){
	return InFieldNum;
}


vector<int> ConfFile::GetInFieldID(){
	return InFieldID;
}

int ConfFile::GetOutFieldID(){
	return OutFieldID;

}