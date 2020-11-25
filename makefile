program: main.o encrypt.o
	g++ main.o encrypt.o -o program
	rm *.o

main.o: main.cpp
	g++ -c main.cpp

encrypt.o: encrypt.cpp
	g++ -c encrypt.cpp
	
