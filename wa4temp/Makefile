SOURCE = main.cpp \
         application.cpp \
         event.cpp \
         callbacks.cpp \
         graphics.cpp \
         wa4.cpp

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O3 -std=c++11 -I. 
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lglut -lGL -lGLU -lpthread

.PHONY: clean

# Targets include all, clean, debug, tar

all : application

application: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core application

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: application

tar: clean
	tar zcvf application.tgz $(SOURCE) *.h Makefile README *.png

help:
	@echo "	make application  - same as make all"
	@echo "	make all    - builds the main target"
	@echo "	make        - same as make all"
	@echo "	make clean  - remove .o .d core main"
	@echo "	make debug  - make all with -g and -DDEBUG"
	@echo "	make tar    - make a tarball of .cpp and .h files"
	@echo "	make help   - this message"

# This will include the .d files which keep include file dependencies straight
-include $(SOURCE:.cpp=.d)

# This creates and updates the .d files for include dependency tracking
%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

