TARGET := main
OBJ := main.o

cc = g++
vpath %.cpp ./src
vpath %.hpp ./include

CFLAG=-I ./include 

.PHONY: all
all: $(TARGET)
main: $(OBJ)
	$(cc) -o $@ $^
# 使用隐性规则去build
main.o: main.cpp main.hpp
	$(cc) -c $< $(CFLAG)

.PHONY: clean
clean:
	rm -rf main *.o
