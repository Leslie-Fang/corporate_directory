vpath %.cc ./src
test: main.o test1.o
	c++ -isystem ./include -g -Wall -Wextra -pthread -o $@ $^ -L./lib -lgtest -lpthread
main.o: main.cc
	c++ -isystem ./include -g -Wall -Wextra -pthread -c $<
test.o: test1.cc
	c++ -isystem ./include -g -Wall -Wextra -pthread -c $<
clean:
	rm *.o test
	