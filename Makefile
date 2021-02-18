CXX = g++

BUILD_TYPE ?= DEBUG

OUTPUT_FILE ?= bin/glir

GLFW ?= ./include/vendor/glfw
GLAD ?= ./include/vendor/glad

INCLUDE_FILES = -I./include -I./include/vendor -I$(GLFW)/include -I$(GLAD)/include
CFLAGS = -std=c++14 -Wall
LDFLAGS = -L$(GLFW)/lib -L$(GLAD)/lib -lglfw3 -lglad -lopengl32 -lgdi32

ifeq ($(BUILD_TYPE), RELEASE)
	CFLAGS += -O3
else
	CFLAGS += -g
endif

.PHONY: all clean

INPUT_FILES = src/*.cpp include/vendor/stb_image/*.cpp include/vendor/imgui/*.cpp
OBJS = $(patsubst %.cpp, %.o, $(wildcard $(INPUT_FILES)))

all:
	mingw32-make $(OUTPUT_FILE)

$(OUTPUT_FILE): $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT_FILE).exe $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS) $(INCLUDE_FILES)

clean:
ifneq (,$(OBJS))
	del $(subst /,\,$(OBJS))
endif
ifneq (,$(wildcard $(OUTPUT_FILE)))
	del $(subst /,\,$(OUTPUT_FILE))
endif
	@echo Done Cleaning