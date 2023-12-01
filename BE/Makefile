INC_DIRS = -I . -I ./capteurs -I ./comportements
COpts = -Wall -std=c++11 $(INC_DIRS)
CAPT_DIR = ./capteurs

main : main.cpp Aquarium.o Bestiole.o Milieu.o Oreilles.o Yeux.o
	g++ $(COpts) -o main $^  -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ $(COpts) -c Aquarium.cpp

Bestiole.o : Bestiole.h Bestiole.cpp $(CAPT_DIR)/Capteur.h
	g++ $(COpts) -c Bestiole.cpp

Milieu.o : Milieu.h Milieu.cpp
	g++ $(COpts) -c Milieu.cpp

Yeux.o: $(CAPT_DIR)/Yeux.h $(CAPT_DIR)/Yeux.cpp $(CAPT_DIR)/Capteur.h
	g++ $(COpts) -c $(CAPT_DIR)/Yeux.cpp

Oreilles.o: $(CAPT_DIR)/Oreilles.h $(CAPT_DIR)/Oreilles.cpp $(CAPT_DIR)/Capteur.h
	g++ $(COpts) -c $(CAPT_DIR)/Oreilles.cpp

clean:
	rm -rf *.o main

