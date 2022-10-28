SOURCE = application.cpp \
         disjoint.cpp \
         main.cpp \
         maze.cpp \
         graph.cpp \
         bfsPaths.cpp

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O3 -I. -ggdb
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lX11 -lGL -lpng -lpthread -lstdc++fs

.PHONY: clean

# Targets include all, clean, debug, tar

all : maze

maze: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core maze

debug: CXXFLAGS = -DDEBUG -g -lX11 -lGL -lpng -lpthread -lstdc++fs
debug: maze

tar: clean
	tar zcvf maze.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make maze  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

