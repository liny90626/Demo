# coroutine demo

# 模块名称定义
MOD_BIN_NAME = coroutine

PWD := $(shell pwd)
export MOD_DIR := $(PWD)/../

# 通用配置加载
PJ_BUILD_CONFIG_DIR ?=

include $(PJ_BUILD_CONFIG_DIR)/TOOL.mak
include $(PJ_BUILD_CONFIG_DIR)/MOD.mak

# 编译工具定义
export CXX := $(MY_CXX)
export CC := $(MY_CC)
export AR := $(MY_AR) -rc
export STRIP := $(MY_STRIP)

# 编译标识定义
export GFLAGS := $(MY_GFLAGS)
export OFLAGS := $(MY_OFLAGS)

export CPPFLAGS := $(MY_INCFLAGS)
export CPPFLAGS += $(MY_COMPILE_FLAGS)
export CPPFLAGS += -I$(INC_PATH_LIBCO)
export CPPFLAGS += $(MY_OFLAGS) $(MY_COMPILE_FLAGS)
 
export LIBFLAGS := $(MY_LIBFLAGS)
export LIBFLAGS += $(LINK_LIBCO) 

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
	@echo "Generate bin ..."
	mkdir -p $(MOD_BIN_DIR)
	$(CXX) -o $(MOD_BIN_DIR)/$(MOD_BIN_NAME) $(MOD_OBJ_DIR)/*.o  $(LIBFLAGS)
ifneq ($(GFLAG), -g)
	$(STRIP) $(MOD_BIN_DIR)/$(MOD_BIN_NAME)
endif
	
	@echo "Deploy bin ..."
	cp -rf $(MOD_BIN_DIR)/$(MOD_BIN_NAME) $(PJ_BIN_DIR)/$(MOD_BIN_NAME)

$(MOD_SRC_DIRS):
	@echo "\n"
	@$(MAKE) --directory=$@

clean: check
	for d in $(MOD_SRC_DIRS); \
	do \
		cd $${d}; \
		$(MAKE) clean; \
		cd ..;	\
	done \

	-rm $(PJ_BIN_DIR)/$(MOD_BIN_NAME)
	-rm $(MOD_BIN_DIR)/*
