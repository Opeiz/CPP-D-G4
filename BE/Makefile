COpts = -Wall -std=c++11 -I .
CAPT_DIR = ./capteurs

main : main.cpp Aquarium.o Bestiole.o Milieu.o Oreilles.o
	g++ $(COpts) -o main $^  -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ $(COpts) -c Aquarium.cpp

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ $(COpts) -I . -c Bestiole.cpp

Milieu.o : Milieu.h Milieu.cpp
	g++ $(COpts) -I . -c Milieu.cpp

# Yeux.o: $(CAPT_DIR)/Yeux.h $(CAPT_DIR)/Yeux.cpp $(CAPT_DIR)/Capteur.h
# 	g++ $(COpts) -I ./capteurs -c $(CAPT_DIR)/Yeux.cpp

Oreilles.o: $(CAPT_DIR)/Oreilles.h $(CAPT_DIR)/Oreilles.cpp $(CAPT_DIR)/Capteur.h
	g++ $(COpts) -I ./capteurs -c $(CAPT_DIR)/Oreilles.cpp

clean:
	rm -rf *.o main

