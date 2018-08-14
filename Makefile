BUILD_DIR := ./build
CXX = g++
vpath %.cpp ./src
vpath %.hpp ./include

CFLAG=-I ./include 

MAIN := $(BUILD_DIR)/main
.PHONY: all
all: $(BUILD_DIR)/.dummy $(MAIN)

OBJ := $(BUILD_DIR)/main.o
$(MAIN): $(OBJ)
	$(CXX) -o $@ $^
$(BUILD_DIR)/main.o : main.cpp main.hpp
	$(CXX) -c $<  -o $(BUILD_DIR)/main.o $(CFLAG)
$(BUILD_DIR)/.dummy :
	@ mkdir -p $(BUILD_DIR)
	@ touch $@
# 使用隐性规则去build
# #main.o: main.cpp main.hpp
# #       $(cc) -c $< $(CFLAG)
.PHONY: clean
clean:
	rm -rf main *.o
	rm -rf $(BUILD_DIR)/main $(BUILD_DIR)/*.o
