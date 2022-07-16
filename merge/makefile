all: test.cpp *.hpp ../sort/*.hpp ../util/*.hpp
	g++ -Wall -Werror -fsanitize=address -g -I../ -I../sort/ -I. -o test.bin test.cpp

clean:
	rm -rf *.o *.bin
