
#include "CalcHexImpl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mytype.h"

CCalcHexImpl::CCalcHexImpl()
{
}

CCalcHexImpl::~CCalcHexImpl()
{
}

INT16 CCalcHexImpl::offsetLeft(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumber || NULL == inOffset)
	{
		return echoInValidParams();
	}

	const CHAR8 *format = getOutputFormat(hasHexPrefix(inNumber) || hasHexPrefix(inOffset));
	if (NULL == format) 
	{
		return echoInValidParams();
	}
	
	UINT32 number = 0;
	UINT32 offset = 0;
	sscanf(inNumber, "%x", &number);
	sscanf(inOffset, "%x", &offset);
	
	UINT32 result = offset > 0 ? (number << offset) : (number >> -offset);
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, format, result);
	}

	printf(format, result);
	printf("\n");
	return 0;
}

INT16 CCalcHexImpl::offsetRight(const CHAR8 *inNumber, const CHAR8 *inOffset, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumber || NULL == inOffset)
	{
		return echoInValidParams();
	}

	const CHAR8 *format = getOutputFormat(hasHexPrefix(inNumber) || hasHexPrefix(inOffset));
	if (NULL == format) 
	{
		return echoInValidParams();
	}
	
	UINT32 number = 0;
	UINT32 offset = 0;
	sscanf(inNumber, "%x", &number);
	sscanf(inOffset, "%x", &offset);
	
	UINT32 result = offset > 0 ? (number >> offset) : (number << -offset);
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, format, result);
	}

	printf(format, result);
	printf("\n");
	return 0;
}

INT16 CCalcHexImpl::bitAnd(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	const CHAR8 *format = getOutputFormat(hasHexPrefix(inNumLeft) || hasHexPrefix(inNumRight));
	if (NULL == format) 
	{
		return echoInValidParams();
	}
	
	UINT32 numLeft = 0;
	UINT32 numRight = 0;
	sscanf(inNumLeft, "%x", &numLeft);
	sscanf(inNumRight, "%x", &numRight);
	
	UINT32 result = numLeft & numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, format, result);
	}

	printf(format, result);
	printf("\n");
	return 0;
}

INT16 CCalcHexImpl::bitOr(const CHAR8 *inNumLeft, const CHAR8 *inNumRight, CHAR8 *outRes, INT16 outResSize)
{
	if (NULL == inNumLeft || NULL == inNumRight)
	{
		return echoInValidParams();
	}

	const CHAR8 *format = getOutputFormat(hasHexPrefix(inNumLeft) || hasHexPrefix(inNumRight));
	if (NULL == format) 
	{
		return echoInValidParams();
	}
	
	UINT32 numLeft = 0;
	UINT32 numRight = 0;
	sscanf(inNumLeft, "%x", &numLeft);
	sscanf(inNumRight, "%x", &numRight);
	
	UINT32 result = numLeft | numRight;
	if (NULL != outRes && 0 < outResSize)
	{
		snprintf(outRes, outResSize, format, result);
	}

	printf(format, result);
	printf("\n");
	return 0;
}

BOOL CCalcHexImpl::hasHexPrefix(const CHAR8 * number)
{
	if (NULL == number)
	{
		return FALSE;
	}

	if (NULL != strstr(number, "0x")
			|| NULL != strstr(number, "0X"))
	{
		return TRUE;
	}

	return FALSE;
}

const CHAR8 *CCalcHexImpl::getOutputFormat(BOOL hasPrefix)
{
	return hasPrefix ? "0x%x" : "%x";
}

