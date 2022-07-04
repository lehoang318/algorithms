all: test.cpp *.hpp ../util/*.hpp
	g++ -Wall -Werror -fsanitize=address -g -I../ -I. -o test.bin test.cpp

clean:
	rm -rf *.o *.bin
