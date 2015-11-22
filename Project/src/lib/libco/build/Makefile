# coroutine lib

# 模块名称定义
MOD_LIB_NAME = libco.so
MOD_NAME = coroutine
MOD_BUILD_NAME = libcolib

# 模块路径定义
PWD := $(shell pwd)
export MOD_DIR := $(PWD)/..

# 通用配置加载
PJ_BUILD_CONFIG_DIR ?=

include $(PJ_BUILD_CONFIG_DIR)/TOOL.mak
include $(PJ_BUILD_CONFIG_DIR)/MOD.mak

# 编译工具定义
export CPP := $(MY_CXX)
export CC := $(MY_CC)
export AR := $(MY_AR) -rc
export RANLIB := $(MY_RANLIB)

# 编译标识定义
export GFLAGS := $(MY_GFLAGS)
export OFLAGS := $(MY_OFLAGS)

export CPPFLAGS := $(MY_INCFLAGS)
export CPPFLAGS += $(MY_OFLAGS) $(MY_COMPILE_FLAGS)

export LIBFLAGS := $(MY_LIBFLAGS)

MOD_SRC_DIRS := $(MOD_SRC_DIR)

.PHONY: all $(MOD_SRC_DIRS) clean

all: check $(MOD_SRC_DIRS) main

check:
ifeq ($(PJ_BUILD_CONFIG_DIR),)
	@echo "Build failed: PJ_BUILD_CONFIG_DIR is NULL"
	@exit 1
endif

main: 
	@echo "\n"
	@echo "Generate libs ..."
	mkdir -p $(MOD_LIB_DIR)
	cp -rf $(MOD_SRC_DIR)/lib/$(MOD_BUILD_NAME).a $(MOD_LIB_DIR)/$(MOD_BUILD_NAME).a
	cp -rf $(MOD_SRC_DIR)/solib/$(MOD_BUILD_NAME).so $(MOD_LIB_DIR)/$(MOD_BUILD_NAME).so
	
	@echo "Generate headers ..."
	mkdir -p $(MOD_INC_DIR)
	cp -rf $(MOD_SRC_DIR)/co_routine.h $(MOD_INC_DIR)/co_routine.h 
	
	@echo "Deploy libs and headers ..."
	mkdir -p $(INC_PATH_LIBCO)
	cp -rf $(MOD_INC_DIR)/co_routine.h $(INC_PATH_LIBCO)/co_routine.h
	
	cp -rf $(MOD_LIB_DIR)/$(MOD_BUILD_NAME).so $(PJ_LIB_DIR)/$(MOD_LIB_NAME)

$(MOD_SRC_DIRS):
	@echo "\n"
	@$(MAKE) --directory=$(MOD_SRC_DIRS)

clean: check 
	for d in $(MOD_SRC_DIRS); \
	do \
		cd $${d}; \
		$(MAKE) clean; \
		cd ..;	\
	done \

	-rm $(PJ_LIB_DIR)/$(MOD_LIB_NAME)
	-rm $(INC_PATH_LIBCO)/*
	-rm $(MOD_LIB_DIR)/*
	-rm $(MOD_INC_DIR)/*
