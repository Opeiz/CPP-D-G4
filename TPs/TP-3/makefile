tp3: tree.o main.o pine.o
	g++ -o tp3 main.o pine.o tree.o 
tree.o: tree.cpp
	g++ -c tree.cpp
main.o: main.cpp
	g++ -c main.cpp 
pine.o: pine.cpp
	g++ -c pine.cpp
clean:
	rm -rf *.o tree main pine tp3