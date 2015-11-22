#ifndef __LIB_LIBLOG_INC_H__
#define __LIB_LIBLOG_INC_H__

#include "mytype.h"
#include "mysize.h"

#ifdef __cplusplus
extern "C" {
#endif

enum LogLevel
{	
	LOG_LEVEL_FATAL = 0x00,
	LOG_LEVEL_ERR,
	LOG_LEVEL_WARN,
	LOG_LEVEL_INFO,
	LOG_LEVEL_DEBUG,
};

enum LogType
{
	LOG_TYPE_ONLY_SCREEN = 0x00,
	LOG_TYPE_FILE = 0x01,
	LOG_TYPE_REMOTE = 0x02,
	LOG_TYPE_FIFO = 0x04,
};

typedef struct LogConfig_T 
{
	CHAR8 modName[MOD_NAME_SIZE];
	INT16 level;
	INT16 type;
}LogConfig;


/* 主要函数 */
int logInit(const LogConfig *config);
int logReInit(const LogConfig *config);
int logDeInit();
int showRevision();

/* 根据编译条件区分 */
void logDebug(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...);
void logInfo(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...);
void logWarn(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...);
void logErr(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...);
void logFatal(const CHAR8 *fileName, const UINT64 fileLine, const char* format, ...);


#ifdef __cplusplus
} // extern "C"
#endif

#endif /*__LIB_LIBLOG_INC_H__*/


