#ifndef __APP_CALC_SRC_CALCHEXIMPL_H__
#define __APP_CALC_SRC_CALCHEXIMPL_H__

#include "CalcBaseImpl.h"

class CCalcHexImpl : public CCalcBaseImpl
{
public:
	CCalcHexImpl();
	virtual ~CCalcHexImpl();

	virtual INT16 offsetLeft(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 offsetRight(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 bitAnd(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 bitOr(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);

private:
	BOOL hasHexPrefix(const CHAR8 *number);
	const CHAR8 *getOutputFormat(BOOL hasPrefix);
};

#endif

