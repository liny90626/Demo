
OBJS:=$(patsubst %.cpp,$(MOD_OBJ_DIR)/%.o,$(wildcard *.cpp))

.PHONY: all clean

all: check $(OBJS)

check:
	mkdir -p $(MOD_OBJ_DIR)
	chmod 777 -R $(MOD_DIR)

$(MOD_OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(GFLAG) $(OFLAG) -o $@  -c $<

clean: check
	-rm -rf $(MOD_OBJ_DIR)/*
