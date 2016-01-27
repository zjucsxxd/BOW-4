STD = -std=c++11
INCLUDE = -I.
CXXFLAGS = $(STD) -g -O2 -Wall $(INCLUDE)
#CXXFLAGS = $(STD) -g -O2 -DDEBUG -Wall $(INCLUDE)
LD = $(CXX)
LIBS = -lstdc++ -L../../lib -lfilestream -llog -lpthread
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

