CC=g++
CFLAGS+=-g -std=c++0x 
CPPFLAGS+=-g -std=c++0x
dirs := .
files := $(foreach dir,$(dirs),$(wildcard $(dir)/*.cc))
obj=$(patsubst %.cc,%,$(files))
all: $(obj)
clean:
	rm -f $(obj)
