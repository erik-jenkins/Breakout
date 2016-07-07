CC=clang++
CFLAGS=-std=c++11 -Wall `pkg-config --cflags glfw3 glew`
LDFLAGS=`pkg-config --libs glfw3 glew`

ifneq ($(OS),Windows_NT)
	UNAME_S := $(shell uname -s)
	# if mac, add framework references
	ifeq ($(UNAME_S),Darwin)
		LDFLAGS += -lSOIL -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
	endif
endif

SOURCES=$(wildcard source/*.cpp)
OBJECTS=$(addprefix bin/, $(notdir $(SOURCES:.cpp=.o)))
EXE=bin/GLFW

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	@echo Compiling $@
	$(CC) $(CFLAGS) -c $(patsubst %.o, %.cpp, source/$(notdir $@)) -o $@

clean:
	rm -f $(EXE)
	rm -f $(OBJECTS)