
all: kmp.cpp main.cpp parser.cpp data.hpp
	g++ -Wall -I. -c *.cpp
	g++ -o test.bin *.o

clean:
	rm -rf *.o *.bin
