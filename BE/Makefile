main : main.cpp Aquarium.o Bestiole.o Milieu.o Nageoire.o Carapace.o  Camouflage.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o  Nageoire.o  Carapace.o Camouflage.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .
Nageoire.o : Accessories/Nageoire.h Accessories/Nageoire.cpp
	g++ -Wall -std=c++11  -c Accessories/Nageoire.cpp -I .
Carapace.o : Accessories/Carapace.h Accessories/Carapace.cpp
	g++ -Wall -std=c++11  -c Accessories/Carapace.cpp -I .
Camouflage.o : Accessories/Camouflage.h Accessories/Camouflage.cpp
	g++ -Wall -std=c++11  -c Accessories/Camouflage.cpp -I .
# Milieu.o : Milieu.h Milieu.cpp
# 	g++ -Wall -std=c++11  -c Milieu.cpp -I .
# Milieu.o : Milieu.h Milieu.cpp
# 	g++ -Wall -std=c++11  -c Milieu.cpp -I .			
clean:
	rm -rf *.o main

