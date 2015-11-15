
#include "CalcBaseImpl.h"

#include <stdio.h>

CCalcBaseImpl::CCalcBaseImpl()
{
}

CCalcBaseImpl::~CCalcBaseImpl()
{
}

INT16 CCalcBaseImpl::offsetLeft(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}

INT16 CCalcBaseImpl::offsetRight(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}


INT16 CCalcBaseImpl::add(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}

INT16 CCalcBaseImpl::minus(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}

INT16 CCalcBaseImpl::multiply(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}


INT16 CCalcBaseImpl::divide(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}

INT16 CCalcBaseImpl::mod(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}

INT16 CCalcBaseImpl::bitAnd(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}

INT16 CCalcBaseImpl::bitOr(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	return echoInValidOperate();
}


INT16 CCalcBaseImpl::echoNaN()
{
	printf("NaN\n");
	return 0;
}

INT16 CCalcBaseImpl::echoInValidParams()
{
	printf("Invalid params\n");
	return 0;
}

INT16 CCalcBaseImpl::echoInValidOperate()
{
	printf("Invalid opertate\n");
	return 0;
}



