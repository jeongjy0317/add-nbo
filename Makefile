all: add_nbo

add_nbo : add_nbo.o main.o
	g++ -o add_nbo add_nbo.o main.o

add_nbo.o : add_nbo.h add_nbo.cpp
	g++ -c -o add_nbo.o add_nbo.cpp

main.o : main.cpp add_nbo.h
	g++ -c -o main.o main.cpp

clean :
	rm -f add_nbo
	rm -f *.o