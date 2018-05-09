link : main.o link.o
	g++ -o link main.o link.o
link.o : link.cpp link.h
	g++ -c link.cpp
main.o : main.cpp link.h
	g++ -c main.cpp
