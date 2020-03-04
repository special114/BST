CXX = g++ -std=c++11 -g -O2

all: myBST

myBST: main.o
	$(CXX) main.o -o myBST

main.o: main.cpp
	$(CXX) -c main.cpp

.PHONY: clean

clean:
	rm -rf *o myBST
