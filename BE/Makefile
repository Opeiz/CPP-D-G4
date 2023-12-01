main : main.cpp Aquarium.o Bestiole.o Milieu.o ComportementKamikaze.o ComportementPeureuse.o ComportementPrevoyante.o ComportementGregaire.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o ComportementKamikaze.o ComportementPeureuse.o ComportementGregaire.o ComportementPrevoyante.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

ComportementKamikaze.o : comportements/ComportementKamikaze.h comportements/ComportementKamikaze.cpp
	g++ -Wall -std=c++11  -c comportements/ComportementKamikaze.cpp -I .

ComportementGregaire.o : comportements/ComportementGregaire.h comportements/ComportementGregaire.cpp
	g++ -Wall -std=c++11  -c comportements/ComportementGregaire.cpp -I .

ComportementPeureuse.o : comportements/ComportementPeureuse.h comportements/ComportementPeureuse.cpp
	g++ -Wall -std=c++11  -c comportements/ComportementPeureuse.cpp -I .

ComportementPrevoyante.o : comportements/ComportementPrevoyante.h comportements/ComportementPrevoyante.cpp
	g++ -Wall -std=c++11  -c comportements/ComportementPrevoyante.cpp -I .	

clean:
	rm -rf *.o main