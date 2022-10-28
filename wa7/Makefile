SOURCE = application.cpp \
         main.cpp \
         graph.cpp 

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O3 -I. 
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lX11 -lGL -lpng -lpthread -lstdc++fs

.PHONY: clean

# Targets include all, clean, debug, tar

all : graph

graph: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core graph

debug: CXXFLAGS = -DDEBUG -g -lX11 -lGL -lpng -lpthread -lstdc++fs
debug: graph

tar: clean
	tar zcvf graph.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make graph - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

