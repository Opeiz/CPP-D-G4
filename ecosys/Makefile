INCLUDE_DIRS=-I .
COPTS=-Wall -std=c++11 $(INCLUDE_DIRS)
CC=g++

main : main.cpp Aquarium.o Bestiole.o Milieu.o Config.o Oreilles.o Yeux.o Nageoire.o Carapace.o Camouflage.o Accessoires.o ComportementGregaire.o ComportementPeureuse.o ComportementKamikaze.o ComportementPrevoyante.o
	$(CC) $(COPTS) -o main $^ -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) $(COPTS) -c Aquarium.cpp

Bestiole.o : Bestiole.h Bestiole.cpp
	$(CC) $(COPTS) -c Bestiole.cpp

Milieu.o : Milieu.h Milieu.cpp
	$(CC) $(COPTS) -c Milieu.cpp

Config.o : Config.h Config.cpp
	$(CC) $(COPTS) -c Config.cpp
	
Oreilles.o : capteur/ICapteur.h capteur/Oreilles.h capteur/Oreilles.cpp
	$(CC) $(COPTS) -c capteur/Oreilles.cpp
	
Yeux.o : capteur/ICapteur.h capteur/Yeux.h capteur/Yeux.cpp
	$(CC) $(COPTS) -c capteur/Yeux.cpp

Nageoire.o : accessoire/IAccessoire.h accessoire/Nageoire.h accessoire/Nageoire.cpp
	$(CC) $(COPTS) -c accessoire/Nageoire.cpp
	
Carapace.o : accessoire/IAccessoire.h accessoire/Carapace.h accessoire/Carapace.cpp
	$(CC) $(COPTS) -c accessoire/Carapace.cpp

Camouflage.o : accessoire/IAccessoire.h accessoire/Camouflage.h accessoire/Camouflage.cpp
	$(CC) $(COPTS) -c accessoire/Camouflage.cpp
	
Accessoires.o : accessoire/Accessoires.h accessoire/Accessoires.cpp
	$(CC) $(COPTS) -c accessoire/Accessoires.cpp

Comportement%.o: comportement/IComportement.h comportement/Comportement%.h comportement/Comportement%.cpp
	$(CC) $(COPTS) -c $^
	
Statistics.o : Statistics.h Statistics.cpp
	g++ -Wall -std=c++11  -c Statistics.cpp -I .
	
clean:
	rm -rf *.o main

