#pragma once

#include "BiffRecord.h"
//#include <Logic/Biff_structures/FilePointer.h>

namespace XLS
{

class CFStreamCacheReader;

// Logical representation of BOF record in BIFF8
class BOF: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(BOF)
	BASE_OBJECT_DEFINE_CLASS_NAME(BOF)
public:
	BOF();
	~BOF();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeBOF;

	unsigned short getSubstreamType();

	typedef enum
	{
		st_Workbook = 0x0005,
		st_Globals = st_Workbook,
		st_Dialog = 0x0010,
		st_Worksheet = st_Dialog,
		st_Chart = 0x0020,
		st_Macro = 0x040
	} SubstreamType;


//-----------------------------
	BIFF_WORD vers;
	BIFF_WORD dt;
	BIFF_WORD rupBuild;
	BIFF_WORD rupYear;
	
	bool fWin;
	bool fRisc;
	bool fBeta;
	bool fWinAny;
	bool fMacAny;
	bool fBetaAny;
	bool fRiscAny;
	bool fOOM;
	bool fGlJmp;
	bool fFontLimit;
	
	BIFF_WORD verXLHigh;
	BIFF_BYTE verLowestBiff;
	BIFF_BYTE verLastXLSaved;
	ForwardOnlyParam<unsigned int> stream_ptr;
	
};

} // namespace XLS

