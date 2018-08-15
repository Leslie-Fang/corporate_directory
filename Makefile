BUILD_DIR := ./build
CXX = g++
vpath %.cpp ./src
vpath %.hpp ./include

INCLUDE_PATH := -I./include
LD_LIBRARY := -lgflags

MAIN := $(BUILD_DIR)/main
.PHONY: all
all: $(BUILD_DIR)/.dummy $(MAIN)

OBJ := $(BUILD_DIR)/main.o $(BUILD_DIR)/employee_node.o $(BUILD_DIR)/employee_list.o $(BUILD_DIR)/insert_node.o
$(MAIN): $(OBJ)
	$(CXX) -o $@ $^ $(LD_LIBRARY)
$(BUILD_DIR)/main.o: main.cpp employee_node.hpp main.hpp
	$(CXX) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/employee_node.o: employee_node.cpp employee_node.hpp main.hpp
	$(CXX) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/employee_list.o: employee_list.cpp employee_list.hpp employee_node.hpp main.hpp
	$(CXX) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/insert_node.o: insert_node.cpp insert_node.hpp
	$(CXX) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/.dummy:
	@ mkdir -p $(BUILD_DIR)
	@ touch $@
# 使用隐性规则去build
# #main.o: main.cpp main.hpp
# #       $(cc) -c $< $(CFLAG)
.PHONY: clean
clean:
	rm -rf main *.o
	rm -rf $(BUILD_DIR)/main $(BUILD_DIR)/*.o
