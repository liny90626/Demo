
OBJS:=$(patsubst %.c,$(MOD_OBJ_DIR)/%.o,$(wildcard *.c))

.PHONY: all clean

all: check $(OBJS)

check:
	mkdir -p $(MOD_OBJ_DIR)
	chmod 777 -R $(MOD_DIR)

$(MOD_OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(GFLAG) $(OFLAG) -o $@ -c $<

clean: check
	-rm -rf $(MOD_OBJ_DIR)/*
