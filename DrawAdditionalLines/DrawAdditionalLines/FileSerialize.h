#pragma once

class FileSerialize : public CObject
{
// imprement must

protected:
	DECLARE_SERIAL(FileSerialize)
public:
				

	int num;
	CString str;

	virtual void Serialize(CArchive& ar);

};
