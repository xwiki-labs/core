#pragma once

#include "BiffRecord.h"
#include <Logic/Biff_structures/BiffString.h>
#include <Logic/Biff_structures/DVParsedFormula.h>
#include <Logic/Biff_structures/SqRefU.h>

namespace XLS
{


// Logical representation of Dv record in BIFF8
class Dv: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Dv)
	BASE_OBJECT_DEFINE_CLASS_NAME(Dv)
public:
	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeDv;

//-----------------------------
	BIFF_BYTE valType;
	BIFF_BYTE errStyle;
	bool fStrLookup;
	bool fAllowBlank;
	bool fSuppressCombo;
	BIFF_BYTE mdImeMode;
	bool fShowInputMsg;
	bool fShowErrorMsg;
	BIFF_BYTE typOperator;

	XLUnicodeString PromptTitle;
	XLUnicodeString ErrorTitle;
	XLUnicodeString Prompt;
	XLUnicodeString Error;
	DVParsedFormula formula1;
	DVParsedFormula formula2;
	SqRefU sqref;
public:
	//BO_ATTRIB_MARKUP_BEGIN
		//BO_ATTRIB_MARKUP_ATTRIB(valType)
		//BO_ATTRIB_MARKUP_ATTRIB(errStyle)
		//BO_ATTRIB_MARKUP_ATTRIB(fStrLookup)
		//BO_ATTRIB_MARKUP_ATTRIB(fAllowBlank)
		//BO_ATTRIB_MARKUP_ATTRIB(fSuppressCombo)
		//BO_ATTRIB_MARKUP_ATTRIB(mdImeMode)
		//BO_ATTRIB_MARKUP_ATTRIB(fShowInputMsg)
		//BO_ATTRIB_MARKUP_ATTRIB(fShowErrorMsg)
		//BO_ATTRIB_MARKUP_ATTRIB(typOperator)

		//BO_ATTRIB_MARKUP_ATTRIB(PromptTitle)
		//BO_ATTRIB_MARKUP_ATTRIB(ErrorTitle)
		//BO_ATTRIB_MARKUP_ATTRIB(Prompt)
		//BO_ATTRIB_MARKUP_ATTRIB(Error)
		//BO_ATTRIB_MARKUP_COMPLEX(formula1)
		//BO_ATTRIB_MARKUP_COMPLEX(formula2)
		//BO_ATTRIB_MARKUP_COMPLEX(formula2)
	//BO_ATTRIB_MARKUP_END

};

} // namespace XLS

