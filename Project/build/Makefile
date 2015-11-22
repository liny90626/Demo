# 该文件为总的Makefile文件

PWD := $(shell pwd)
export PJ_DIR := $(PWD)/..

include ./config/OS.mak
include ./config/TOOL.mak
include ./config/PATH.mak
include ./config/BUILD.mak

#######################################################################
#enviroment
#######################################################################
.PHONY: all $(BUILD_DIRS) clean

env:
	mkdir -p $(PJ_INC_DIR)
	mkdir -p $(PJ_BIN_DIR)
	mkdir -p $(PJ_LIB_DIR)
	
#######################################################################
#all modules build 
#######################################################################
all: env lib app 

all_clean: app_clean lib_clean

#######################################################################
#app modules build 
#######################################################################
app: coroutine calc

app_clean: calc_clean coroutine_clean

coroutine: 
	@$(MAKE) --directory=$(BUILD_BIN_COROUTINE_DIR)
coroutine_clean:
	@$(MAKE) --directory=$(BUILD_BIN_COROUTINE_DIR) clean

calc:
	@$(MAKE) --directory=$(BUILD_BIN_CACL_DIR)
calc_clean:
	@$(MAKE) --directory=$(BUILD_BIN_CACL_DIR) clean
	
#######################################################################
#lib modules build 
#######################################################################
lib: log libco

lib_clean: libco_clean log_clean

liblog: 
	@$(MAKE) --directory=$(BUILD_LIB_LOG_DIR)
liblog_clean: 
	@$(MAKE) --directory=$(BUILD_LIB_LOG_DIR) clean 

libco: 
	@$(MAKE) --directory=$(BUILD_LIB_CO_DIR)
libco_clean: 
	@$(MAKE) --directory=$(BUILD_LIB_CO_DIR) clean
