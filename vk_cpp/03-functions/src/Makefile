TARGET=main.out
CC=g++
FLAGS=-std=c++20 -Wall -Wextra

all: build

build: main.o lib1.o lib2.o
	$(CC) $(FLAGS) main.o lib1.o lib2.o -o $(TARGET)

run: build
	./$(TARGET)

main.o: main.cpp lib1.hpp lib2.hpp
	$(CC) $(FLAGS) -c main.cpp

lib1.o: lib1.cpp lib1.hpp
	$(CC) $(FLAGS) -c lib1.cpp

lib2.o: lib2.cpp lib2.hpp
	$(CC) $(FLAGS) -c lib2.cpp

clean: 
	rm -rf *.o main.out
