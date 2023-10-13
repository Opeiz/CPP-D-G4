all: pine.o utils.o main.o
	g++ -o main main.o pine.o utils.o
main.o : tree.h pine.h main.cpp
	g++ -c -Wall --std=c++17 main.cpp
pine.o: tree.h pixel.h pine.h pine.cpp
	g++ -c -Wall --std=c++17 pine.cpp
utils.o: pixel.h utils.cpp
	g++ -c -Wall --std=c++17 utils.cpp	
clean:
	rm -rf *.o main