#include "StdAfx.h"
#include "FileSerialize.h"



void FileSerialize::Serialize(CArchive& ar){
		if(ar.IsLoading()){
			ar >> num;
		
		}else{
			ar << num;
		
		}
}



IMPLEMENT_SERIAL(FileSerialize, CObject,1)