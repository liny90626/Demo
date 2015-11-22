/*
    Log库的层次低于system库, 因此不要在log库中调用system库的接口, 避免相互依赖
*/

#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* 跨平台头文件 */
#if ( defined __linux__ ) || ( defined __unix ) || ( defined _AIX )
// Linux
#include<unistd.h>
#include <pthread.h>
#elif ( defined _WIN32 )
// Windows
#include <windows.h>
#endif


/* 跨平台宏 */
#if ( defined __linux__ ) || ( defined __unix ) || ( defined _AIX )
// Linux
#define MEMSET      memset
#define MEMCPY      memcpy
#define VSNPRINTF   vsnprintf
#define SNPRINTF    snprintf
#define PRINTF      printf
#define PROCESSID   (UINT64)getpid()
#define THREADID    (UINT64)pthread_self()
#define NEWLINE     "\n"
#elif ( defined _WIN32 )
// Windows
#define MEMSET      memset
#define MEMCPY      memcpy
#define VSNPRINTF   _vsnprintf
#define SNPRINTF    _snprintf
#define PRINTF      printf
#define PROCESSID   (UINT64)GetCurrentProcessId()
#define THREADID    (UINT64)GetCurrentThreadId()
#define NEWLINE     "\r\n"
#endif

// default config
static LogConfig g_logConfig =
{
    "MyLog",
    LOG_LEVEL_INFO,
    LOG_TYPE_ONLY_SCREEN,
};

const CHAR8 g_logLevelItoA[][6] = {"D" , "I" , "W" , "E" , "F"};

int logInit(const LogConfig *config)
{
    if (NULL == config)
    {
        return -1;
    }

    MEMCPY(&g_logConfig, config, sizeof(g_logConfig));
    return 0;
}

int logReInit(const LogConfig *config)
{
    return logInit(config);
}

int logDeInit()
{
    MEMSET(&g_logConfig, 0, sizeof(g_logConfig));
    return 0;
}

int showRevision()
{
    return 0;
}

void logBase(const INT16 level,
                    const CHAR8*fileName, const UINT64 fileLine,
                    const CHAR8 *format, va_list valist)
{
    CHAR8 logBuf[BUF_SIZE];
    UINT16 bufSizeRemained = BUF_SIZE;
    UINT16 bufSizeUsed = 0;
    MEMSET(&logBuf, 0, sizeof(logBuf));

    bufSizeUsed = SNPRINTF(logBuf + bufSizeUsed, bufSizeRemained,
                           "%s/%s[pid-%lu|tid-%lu|%s|%lu]: ",
                           g_logLevelItoA[level], g_logConfig.modName, PROCESSID, THREADID, fileName, fileLine);
    bufSizeRemained -= bufSizeUsed;

    VSNPRINTF(logBuf + bufSizeUsed, bufSizeRemained , format , valist);

    PRINTF("%s"NEWLINE, logBuf);
}


void logDebug(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...)
{
    if(LOG_LEVEL_DEBUG <= g_logConfig.level)
    {
        va_list valist;
        va_start(valist, format);
        logBase(LOG_LEVEL_DEBUG, fileName, fileLine, format, valist);
        va_end(valist);
    }
}

void logInfo(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...)
{
	if(LOG_LEVEL_INFO <= g_logConfig.level)
	{
		va_list valist;
		va_start(valist, format);
		logBase(LOG_LEVEL_INFO, fileName, fileLine, format, valist);
		va_end(valist);
	}
}

	
void logWarn(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...)
{
	if(LOG_LEVEL_WARN <= g_logConfig.level)
	{
		va_list valist;
		va_start(valist, format);
		logBase(LOG_LEVEL_WARN, fileName, fileLine, format, valist);
		va_end(valist);
	}
}


void logErr(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...)
{
	if(LOG_LEVEL_ERR <= g_logConfig.level)
	{
		va_list valist;
		va_start(valist, format);
		logBase(LOG_LEVEL_ERR, fileName, fileLine, format, valist);
		va_end(valist);
	}
}

void logFatal(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...)
{
	if(LOG_LEVEL_FATAL<= g_logConfig.level)
	{
		va_list valist;
		va_start(valist, format);
		logBase(LOG_LEVEL_FATAL, fileName, fileLine, format, valist);
		va_end(valist);
	}
}



