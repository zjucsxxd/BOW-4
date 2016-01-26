# a tiny library of C++11 for flexible logging to files
## Usage

``` C++11
//see src/test/test.cpp

#include "../../inc/log/log.h"

int main(int argc, char* argv[]) {
    Logger::set_fp_stream(Logger::debug, "./debug.log");
    Logger::set_fp_stream(Logger::fatal, "./error.log");
    Logger::set_fp_stream(Logger::warning, "./error.log");
    Logger::set_fp_stream(Logger::notice, "./notice.log");
    DEBUG_LOG("debug log message");
    FATAL_LOG("fatal log message");
    WARNING_LOG("warning log message");
    NOTICE_LOG("notice log message");
    STDERR_LOG("stderr log message");
    return 0;
}
```

``` bash
#Makfile
STD = -std=c++11
INCLUDE = -I.
CXXFLAGS = $(STD) -g -O2 -Wall $(INCLUDE)
#CXXFLAGS = $(STD) -g -O2 -Wall $(INCLUDE) -DRELEASE #发布版本状态下不输出DEBUG日志消息
LD = $(CXX)
LIBS = -lstdc++ -L../../lib -llog
LDFLAGS = $(STD) $(LIBS)

TARGET = test
SRC_DIR = .
OBJ_DIR = ./object

MAKE_OBJECT_DIR := $(shell mkdir -p $(OBJ_DIR))
OBJS = $(addsuffix .o, $(subst $(SRC_DIR),$(OBJ_DIR),$(basename $(wildcard $(SRC_DIR)/*.cpp))))

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY : clean rm
clean:
	rm -f $(OBJ_DIR)/*
	rmdir $(OBJ_DIR)
	rm -f $(TARGET)
rm : clean


```
