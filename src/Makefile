STD = -std=c++11
INCLUDE = -I.
CXXFLAGS = $(STD) -g -O2 -Wall $(INCLUDE)
#CXXFLAGS = $(STD) -g -O2 -DDEBUG -Wall $(INCLUDE)
LD = $(CXX)
LIBS = -lstdc++
LDFLAGS = $(STD) $(LIBS)

SRC_DIR = .
OBJ_DIR = ./build
LIB_DIR = ../lib
INC_DIR = ../include
LIB = liblog.a

MAKE_OBJECT_DIR := $(shell mkdir -p $(OBJ_DIR))
MAKE_LIB_DIR := $(shell mkdir -p $(LIB_DIR))
MAKE_INC_DIR := $(shell mkdir -p $(INC_DIR))
OBJS = $(addsuffix .o, $(subst $(SRC_DIR),$(OBJ_DIR),$(basename $(wildcard $(SRC_DIR)/*.cpp))))

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

