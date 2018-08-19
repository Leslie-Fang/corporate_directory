vpath %.cc ./src
BUILD_DIR := ../build
OBJ := $(BUILD_DIR)/global.o $(BUILD_DIR)/employee_node.o $(BUILD_DIR)/employee_list.o $(BUILD_DIR)/insert_node.o $(BUILD_DIR)/query_node.o \
$(BUILD_DIR)/modify_node.o $(BUILD_DIR)/delete_node.o

test: main_test.o test1.o $(OBJ)
	c++ -isystem ./include -I../include -g -Wall -Wextra -pthread -o $@ $^ -L./lib -lgtest -lpthread -lgflags -v
main_test.o: main.cc
	c++ -isystem ./include -g -Wall -Wextra -pthread -c $< -o $@
test1.o: test1.cc
	c++ -isystem ./include -I../include -g -Wall -Wextra -pthread -c $< -o $@
clean:
	rm *.o test
	