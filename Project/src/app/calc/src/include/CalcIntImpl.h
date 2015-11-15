#ifndef __APP_CALC_SRC_CALCINTIMPL_H__
#define __APP_CALC_SRC_CALCINTIMPL_H__

#include "CalcBaseImpl.h"

class CCalcIntImpl : public CCalcBaseImpl
{
public:
	CCalcIntImpl();
	virtual ~CCalcIntImpl();

	virtual INT16 offsetLeft(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 offsetRight(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 add(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 minus(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 multiply(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 divide(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 mod(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 bitAnd(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
	virtual INT16 bitOr(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize);
};

#endif

