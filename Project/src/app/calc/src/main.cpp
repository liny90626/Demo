
#include <stdio.h>
#include <string.h>

#include "revision.h"
#include "CalcIntImpl.h"
#include "CalcFloatImpl.h"
#include "CalcHexImpl.h"

enum operate_e
{
	OPERATE_INVALID = -1,
	OPERATE_OFFSET_LEFT = 0,
	OPERATE_OFFSET_RIGHT,
	OPERATE_ADD,
	OPERATE_MINUS,
	OPERATE_MUTIPLY,
	OPERATE_DIVIDE,
	OPERATE_MOD,
	OPERATE_AND,
	OPERATE_OR,
};

static int showRevision() {
	printf("ModName: %s, Version: %s\n", MOD_NAME, MOD_VERSION);
	return 0;
}

static int echoHelp()
{
	showRevision();
	printf("usage: calc num1 operator num2 [-f/-n/-x]\n");
	printf("-f: calculate in float\n");
	printf("-n(default): calculate in integer\n");
	printf("-x: calculate in hex\n");
	printf("operator: support <<, >>, +, -, *, /, %%, &, |, \n");
	printf("example:\n");
	printf("calc 1 + 1\n");
	printf("calc 5 \"*\" 6\n");
	printf("calc 2 \"<<\" 3\n");
	return 0;
}

static ICalc *createCalcInterface(const char *opt)
{
	if (NULL == opt)
	{
		// default
		return new CCalcIntImpl();
	}
	
	if (0 == strcasecmp(opt, "-f"))
	{
		return new CCalcFloatImpl();
	} else if(0 == strcasecmp(opt, "-x"))
	{
		return new CCalcHexImpl();
	} 

	return new CCalcIntImpl();
}

static int destoryCalcInterface(ICalc *calcInterface)
{
	if (NULL != calcInterface)
	{
		delete calcInterface;
		calcInterface = NULL;
	}

	return 0;
}

static int getOperate(const char *operate)
{
	if (NULL == operate)
	{
		return OPERATE_INVALID;
	}

	if (0 == strcasecmp(operate, "<<"))
	{
		return OPERATE_OFFSET_LEFT;
	} else if (0 == strcasecmp(operate, ">>"))
	{
		return OPERATE_OFFSET_RIGHT;
	} else if (0 == strcasecmp(operate, "+"))
	{
		return OPERATE_ADD;
	} else if (0 == strcasecmp(operate, "-"))
	{
		return OPERATE_MINUS;
	} else if (0 == strcasecmp(operate, "*"))
	{
		return OPERATE_MUTIPLY;
	} else if (0 == strcasecmp(operate, "/"))
	{
		return OPERATE_DIVIDE;
	} else if (0 == strcasecmp(operate, "%"))
	{
		return OPERATE_MOD;
	} else if (0 == strcasecmp(operate, "&"))
	{
		return OPERATE_AND;
	} else if (0 == strcasecmp(operate, "|"))
	{
		return OPERATE_OR;
	}

	return OPERATE_INVALID;
}

static int calculate(ICalc *calcInterface, 
		const char *num1, const char *operate, const char *num2)
{
	if (NULL == calcInterface 
			|| NULL == num1 
			|| NULL == num2 
			|| NULL == operate)
	{
		return -1;
	}

	switch (getOperate(operate))
	{
	case OPERATE_OFFSET_LEFT:
		calcInterface->offsetLeft(num1, num2, NULL, 0);
		break;

	case OPERATE_OFFSET_RIGHT:
		calcInterface->offsetRight(num1, num2, NULL, 0);
		break;
		
	case OPERATE_ADD:
		calcInterface->add(num1, num2, NULL, 0);
		break;
		
	case OPERATE_MINUS:
		calcInterface->minus(num1, num2, NULL, 0);
		break;
		
	case OPERATE_MUTIPLY:
		calcInterface->multiply(num1, num2, NULL, 0);
		break;
		
	case OPERATE_DIVIDE:
		calcInterface->divide(num1, num2, NULL, 0);
		break;
		
	case OPERATE_MOD:
		calcInterface->mod(num1, num2, NULL, 0);
		break;

	case OPERATE_AND:
		calcInterface->bitAnd(num1, num2, NULL, 0);
		break;

	case OPERATE_OR:
		calcInterface->bitOr(num1, num2, NULL, 0);
		break;
	
	case OPERATE_INVALID:
	default:
		return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc > 5 || argc < 4)
	{
		return echoHelp(); 
	}

	int index = 0;
	const char *num1 = argv[++index];
	const char *operate = argv[++index];
	const char *num2 = argv[++index];
	const char *opt = (argc == 5) ? argv[++index] : NULL;
	
	ICalc *calcInterface = createCalcInterface(opt);
	if (0 != calculate(calcInterface, num1, operate, num2))
	{
		goto exit_safely;
	}

	destoryCalcInterface(calcInterface);
	return 0;

exit_safely:
	destoryCalcInterface(calcInterface);
	return echoHelp();

}

