all: template

template: main.o
	g++ main.o -o template

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o template