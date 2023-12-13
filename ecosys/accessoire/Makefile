main : main.cpp Aquarium.o Bestiole.o Milieu.o Config.o Oreilles.o Yeux.o Nageoire.o Carapace.o Camouflage.o Accessoires.o ComportementGregaire.o ComportementPeureuse.o ComportementKamikaze.o ComportementPrevoyante.o Statistics.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Config.o Oreilles.o Yeux.o Nageoire.o Carapace.o Camouflage.o Accessoires.o ComportementGregaire.o ComportementPeureuse.o ComportementKamikaze.o ComportementPrevoyante.o Statistics.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Config.o : Config.h Config.cpp
	g++ -Wall -std=c++11  -c Config.cpp -I .
	
Oreilles.o : capteur/ICapteur.h capteur/Oreilles.h capteur/Oreilles.cpp
	g++ -Wall -std=c++11  -c capteur/Oreilles.cpp -I .
	
Yeux.o : capteur/ICapteur.h capteur/Yeux.h capteur/Yeux.cpp
	g++ -Wall -std=c++11  -c capteur/Yeux.cpp -I .

Nageoire.o : accessoire/IAccessoire.h accessoire/Nageoire.h accessoire/Nageoire.cpp
	g++ -Wall -std=c++11  -c accessoire/Nageoire.cpp -I .
	
Carapace.o : accessoire/IAccessoire.h accessoire/Carapace.h accessoire/Carapace.cpp
	g++ -Wall -std=c++11  -c accessoire/Carapace.cpp -I .

Camouflage.o : accessoire/IAccessoire.h accessoire/Camouflage.h accessoire/Camouflage.cpp
	g++ -Wall -std=c++11  -c accessoire/Camouflage.cpp -I .
	
Accessoires.o : accessoire/Accessoires.h accessoire/Accessoires.cpp
	g++ -Wall -std=c++11  -c accessoire/Accessoires.cpp -I .
	
ComportementGregaire.o : comportement/IComportement.h comportement/ComportementGregaire.h comportement/ComportementGregaire.cpp
	g++ -Wall -std=c++11  -c comportement/IComportement.h comportement/ComportementGregaire.cpp -I .	
	
ComportementPeureuse.o : comportement/IComportement.h comportement/ComportementPeureuse.h comportement/ComportementPeureuse.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementPeureuse.cpp -I .
	
ComportementKamikaze.o : comportement/IComportement.h comportement/ComportementKamikaze.h comportement/ComportementKamikaze.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementKamikaze.cpp -I .

ComportementPrevoyante.o : comportement/IComportement.h comportement/ComportementPrevoyante.h comportement/ComportementPrevoyante.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementPrevoyante.cpp -I .
	
Statistics.o : Statistics.h Statistics.cpp
	g++ -Wall -std=c++11  -c Statistics.cpp -I .
	
clean:
	rm -rf *.o main

