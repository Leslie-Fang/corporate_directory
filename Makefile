BUILD_DIR := ./build
LOG_DIR := ./log
CXX = g++
vpath %.cpp ./src
vpath %.hpp ./include

INCLUDE_PATH := -I./include
LD_LIBRARY := -lgflags -lglog

CFLAGs := -std=c++11
MAIN := $(BUILD_DIR)/main
.PHONY: all
all: $(BUILD_DIR)/.dummy $(LOG_DIR)/.dummy $(MAIN)

OBJ := $(BUILD_DIR)/main.o $(BUILD_DIR)/employee_node.o $(BUILD_DIR)/employee_list.o $(BUILD_DIR)/insert_node.o $(BUILD_DIR)/query_node.o \
$(BUILD_DIR)/modify_node.o $(BUILD_DIR)/delete_node.o $(BUILD_DIR)/global.o
$(MAIN): $(OBJ)
	$(CXX) -o $@ $^ $(LD_LIBRARY)
$(BUILD_DIR)/main.o: main.cpp employee_node.hpp employee_list.hpp main.hpp insert_node.hpp query_node.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/employee_node.o: employee_node.cpp employee_node.hpp main.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/employee_list.o: employee_list.cpp employee_list.hpp employee_node.hpp main.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/insert_node.o: insert_node.cpp insert_node.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/query_node.o: 	query_node.cpp query_node.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/modify_node.o: modify_node.cpp modify_node.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/delete_node.o: delete_node.cpp delete_node.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/global.o: global.cpp global.hpp
	$(CXX) $(CFLAGs) -c $< $(INCLUDE_PATH) -o $@
$(BUILD_DIR)/.dummy:
	@ mkdir -p $(BUILD_DIR)
	@ touch $@
$(LOG_DIR)/.dummy:
	@ mkdir -p $(LOG_DIR)
	@ touch $@
# 使用隐性规则去build
# #main.o: main.cpp main.hpp
# #       $(cc) -c $< $(CFLAG)
.PHONY: test
test:
	@cd test && $(MAKE) $@ && ./test

.PHONY: clean
clean:
	rm -rf main *.o
	rm -rf $(BUILD_DIR)/main $(BUILD_DIR)/*.o
	rm -rf $(LOG_DIR)/*
	cd test && $(MAKE) $@
