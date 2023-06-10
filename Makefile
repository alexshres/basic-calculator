CXX=clang++

calc: main.o
	${CXX} -o calc main.o

main.o: stack.h main.cpp


.PHONY: clean

clean:
	rm -f *.o calc


