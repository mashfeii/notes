TARGET=main.out
CC=g++
FLAGS=-Wall -Wextra -std=c++20

all: build

build: main.o a.o lib1.o lib2.o
	$(CC) $(FLAGS) a.o lib1.o lib2.o main.o -o $(TARGET)

main.o: main.cpp lib1.hpp lib2.hpp
	$(CC) $(FLAGS) -c main.cpp

a.o: a.hpp 
	$(CC) $(FLAGS) -c a.hpp

lib1.o: lib1.cpp lib1.hpp a.hpp
	$(CC) $(FLAGS) -c lib1.cpp

lib2.o: lib2.cpp a.hpp lib2.hpp
	$(CC) $(FLAGS) -c lib2.cpp

run: build
	./$(TARGET)

clean:
	rm -rf *.o $(TARGET)
