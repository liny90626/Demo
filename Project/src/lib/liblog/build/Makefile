# mylog lib

# 模块名称定义
MOD_LIB_NAME = liblog.so
MOD_NAME = mylog
MOD_BUILD_NAME = liblog

# 模块路径定义
PWD := $(shell pwd)
export MOD_DIR := $(PWD)/..

# 通用配置加载
PJ_BUILD_CONFIG_DIR ?=

include $(PJ_BUILD_CONFIG_DIR)/TOOL.mak
include $(PJ_BUILD_CONFIG_DIR)/MOD.mak

# 版本定义
export MAJOR_REVISION := 1
export MINOR_REVISION := 0

# 编译工具定义
export CPP := $(MY_CXX)
export CC := $(MY_CC)
export AR := $(MY_AR) -rc
export RANLIB := $(MY_RANLIB)

# 编译标识定义
export GFLAGS := $(MY_GFLAGS)
export OFLAGS := $(MY_OFLAGS)

export CFLAGS := $(MY_INCFLAGS)
export CFLAGS += $(MY_LDFLAGS) $(MY_OFLAGS) $(MY_COMPILE_FLAGS)

export LDFLAGS := $(MY_LDFLAGS)

MOD_SRC_DIRS := $(MOD_SRC_DIR)

.PHONY: all $(MOD_SRC_DIRS) clean

all: check $(MOD_SRC_DIRS) main

check:
ifeq ($(PJ_BUILD_CONFIG_DIR),)
	@echo "Build failed: PJ_BUILD_CONFIG_DIR is NULL"
	@exit 1
endif

ifeq ($(PJ_BUILD_SCRIPTS_DIR),)
	@echo "Build failed: PJ_BUILD_SCRIPTS_DIR is NULL"
	@exit 1
endif

	@$(PJ_BUILD_SCRIPTS_DIR)/genRevisionGit.sh $(MOD_NAME) "__LIB_LIBLOG_SRC_INC_REVISION_H__"

main: 
	@echo "\n"
	@echo "Generate lib ..."
	$(CC) $(LDFLAGS) -o $(MOD_LIB_DIR)/$(MOD_LIB_NAME) $(MOD_OBJ_DIR)/*.o
ifneq ($(GFLAGS), -g)
	$(STRIP) $(MOD_LIB_DIR)/$(MOD_LIB_NAME)
endif
	
	@echo "Deploy libs and headers ..."
	mkdir -p $(INC_PATH_LIBLOG)
	cp -rf $(MOD_INC_DIR)/*.h $(INC_PATH_LIBLOG)/
	
	cp -rf $(MOD_LIB_DIR)/$(MOD_LIB_NAME) $(PJ_LIB_DIR)/$(MOD_LIB_NAME)
	
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
	-rm $(INC_PATH_LIBLOG)/*
	-rm $(MOD_LIB_DIR)/*
