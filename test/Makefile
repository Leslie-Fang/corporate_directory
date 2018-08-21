vpath %.cc ./src
vpath %.a ./lib
BUILD_DIR := ../build
OBJ := $(BUILD_DIR)/global.o $(BUILD_DIR)/employee_node.o $(BUILD_DIR)/employee_list.o $(BUILD_DIR)/insert_node.o $(BUILD_DIR)/query_node.o \
$(BUILD_DIR)/modify_node.o $(BUILD_DIR)/delete_node.o

test: main_test.o test1.o $(OBJ) ./lib/libgtest.a
	c++ -isystem ./include -I../include -g -Wall -Wextra -pthread -o $@ $^ -L./lib -lgtest -lpthread -lgflags -lglog
main_test.o: main.cc
	c++ -isystem ./lib/include -g -Wall -Wextra -pthread -c $< -o $@
test1.o: test1.cc
	c++ -isystem ./lib/include -isystem ../include -g -Wall -Wextra -pthread -c $< -o $@
./lib/libgtest.a: ./lib/gtest-all.o
	$(AR) rv ./lib/libgtest.a $^
./lib/gtest-all.o: ./lib/src/gtest-all.cc
	c++ -isystem ./lib -isystem ./lib/include -g -Wall -Wextra -pthread -c ./lib/src/gtest-all.cc -o ./lib/gtest-all.o
clean:
	rm *.o test ./lib/*.a ./lib/*.o
	