STD = -std=c++11
INCLUDE = -I../../include
#CXXFLAGS = $(STD) -g -O2 -Wall $(INCLUDE) -DRELEASE #在发布版本状态下，不输出DEBUG日志消息
CXXFLAGS = $(STD) -g -O2 -Wall $(INCLUDE)
LD = $(CXX)
LIBS = -lstdc++ -L../../lib -llog
LDFLAGS = $(STD) $(LIBS)

TARGET = test
SRC_DIR = .
OBJ_DIR = ./build

MAKE_OBJECT_DIR := $(shell mkdir -p $(OBJ_DIR))
OBJS = $(addsuffix .o, $(subst $(SRC_DIR),$(OBJ_DIR),$(basename $(wildcard $(SRC_DIR)/*.cpp))))

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

ar : $(OBJS)
	mkdir -p ../include/log
	rm -f ../include/log/*
	cp *.h ../include/log
	rm -f $(LIB_DIR)/$(LIB)
	ar -r $(LIB_DIR)/$(LIB) $(subst $(OBJ_DIR)/test.o,,$(OBJS))

.PHONY : clean rm
clean:
	rm -f $(OBJ_DIR)/*
	rmdir $(OBJ_DIR)
	rm -f $(TARGET)
rm : clean

