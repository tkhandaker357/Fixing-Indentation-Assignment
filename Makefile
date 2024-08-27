main: main.o unindent.o
	g++ -Wall -o main main.o unindent.o

main.o: main.cpp unindent.hpp

unindent.o: unindent.cpp unindent.hpp

clean:
	rm -f main.o unindent.o