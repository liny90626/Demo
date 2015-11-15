
#include "CalcIntImpl.h"

#include <stdio.h>
#include <stdlib.h>

#include "mytype.h"

CCalcIntImpl::CCalcIntImpl()
{
}

CCalcIntImpl::~CCalcIntImpl()
{
}

INT16 CCalcIntImpl::offsetLeft(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumber || NULL == inOffset)
	{
		return echoInValidParams();
	}

	INT16 number = atoi(inNumber);
	INT16 offset = atoi(inOffset);
	INT16 result = offset > 0 ? (number << offset) : (number >> -offset);
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

INT16 CCalcIntImpl::offsetRight(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumber || NULL == inOffset)
	{
		return echoInValidParams();
	}

	INT16 number = atoi(inNumber);
	INT16 offset = atoi(inOffset);
	INT16 result = offset > 0 ? (number >> offset) : (number << -offset);;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

INT16 CCalcIntImpl::add(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	INT16 numLeft = atoi(inNumLeft);
	INT16 numRight = atoi(inNumRight);
	INT16 result = numLeft + numRight;

	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

INT16 CCalcIntImpl::minus(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	INT16 numLeft = atoi(inNumLeft);
	INT16 numRight = atoi(inNumRight);
	INT16 result = numLeft - numRight;

	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

INT16 CCalcIntImpl::multiply(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	INT16 numLeft = atoi(inNumLeft);
	INT16 numRight = atoi(inNumRight);
	INT16 result = numLeft * numRight;

	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}


INT16 CCalcIntImpl::divide(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	INT16 numLeft = atoi(inNumLeft);
	INT16 numRight = atoi(inNumRight);
	if (0 == numRight)
	{
		return echoNaN();
	}
	
	INT16 result = numLeft / numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

INT16 CCalcIntImpl::mod(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	INT16 numLeft = atoi(inNumLeft);
	INT16 numRight = atoi(inNumRight);
	if (0 == numRight)
	{
		return echoNaN();
	}
	
	INT16 result = numLeft % numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

INT16 CCalcIntImpl::bitAnd(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	INT16 numLeft = atoi(inNumLeft);
	INT16 numRight = atoi(inNumRight);
	INT16 result = numLeft & numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

INT16 CCalcIntImpl::bitOr(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	INT16 numLeft = atoi(inNumLeft);
	INT16 numRight = atoi(inNumRight);	
	INT16 result = numLeft | numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, "%d", result);
	}
	printf("%d\n", result);
	return 0;
}

