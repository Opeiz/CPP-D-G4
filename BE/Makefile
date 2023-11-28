main : main.cpp Aquarium.o Bestiole.o Milieu.o Kamikaze.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Kamikaze.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Kamikaze.o : comportement/ComportementKamikaze.h comportement/ComportementKamikaze.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementKamikaze.cpp -I .

clean:
	rm -rf *.o main

