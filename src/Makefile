STD = -std=c++11
INCLUDE = -I../inc
CXXFLAGS = $(STD) -g -O2 -Wall $(INCLUDE)
#CXXFLAGS = $(STD) -g -O2 -DDEBUG -Wall $(INCLUDE)
LD = $(CXX)
LIBS = -lstdc++
LDFLAGS = $(STD) $(LIBS)

SRC_DIR = .
OBJ_DIR = ./object
LIB_DIR = ../lib
INC_DIR = ../inc/bow
LIB = libbow.a 

MAKE_OBJ_DIR := $(shell mkdir -p $(OBJ_DIR))
MAKE_LIB_DIR := $(shell mkdir -p $(LIB_DIR))
MAKE_INC_DIR := $(shell mkdir -p $(INC_DIR))
OBJS = $(addsuffix .o, $(subst $(SRC_DIR),$(OBJ_DIR),$(basename $(wildcard $(SRC_DIR)/*.cpp))))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

ar : $(OBJS)
	cp *.h $(INC_DIR)
	ar -r $(LIB_DIR)/$(LIB) $(subst $(OBJ_DIR)/test.o,,$(OBJS))

.PHONY : clean rm
clean:
	rm -f $(OBJ_DIR)/*
	rmdir $(OBJ_DIR)
rm : clean

