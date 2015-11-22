# 该文件用于模块编译时相关定义

# 头文件路径定义
INC_PATH_LIBCO := $(PJ_INC_DIR)/libco
INC_PATH_LIBLOG := $(PJ_INC_DIR)/liblog

# 库链接名称定义
LINK_LIBCO := -lco -lpthread -ldl
LINK_LIBLOG := -llog

# 编译模块路径定义
export MOD_LIB_DIR := $(MOD_DIR)/lib
export MOD_BIN_DIR := $(MOD_DIR)/bin
export MOD_SRC_DIR := $(MOD_DIR)/src
export MOD_BUILD_DIR := $(MOD_DIR)/build
export MOD_INC_DIR := $(MOD_DIR)/include
export MOD_OBJ_DIR := $(MOD_DIR)/obj
export MOD_SRC_INC_DIR := $(MOD_SRC_DIR)/include

# 编译通用flags定义
export MY_LIBFLAGS := -L$(PJ_LIB_DIR)
export MY_INCFLAGS := -I$(PJ_INC_DIR) -I$(MOD_INC_DIR) -I$(MOD_SRC_INC_DIR)
export MY_LDFLAGS := -fPIC -shared

export MY_GFLAGS := -g
export MY_OFLAGS := -O3
export MY_COMPILE_FLAGS := -Wall
