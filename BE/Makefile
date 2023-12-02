CAPT_DIR = ./capteurs
COMP_DIR = ./comportements
INC_DIRS = -I . -I $(CAPT_DIR) -I $(COMP_DIR)
COpts = -Wall -std=c++11 $(INC_DIRS)


main : main.cpp Aquarium.o Bestiole.o Milieu.o Oreilles.o Yeux.o ComportementGregaire.o
	g++ $(COpts) -o main $^  -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp Milieu.o
	g++ $(COpts) -c Aquarium.cpp

Bestiole.o : Bestiole.h Bestiole.cpp $(CAPT_DIR)/Capteur.h ComportementGregaire.o
	g++ $(COpts) -c Bestiole.cpp

Milieu.o : Milieu.h Milieu.cpp ComportementGregaire.o
	g++ $(COpts) -c Milieu.cpp

Yeux.o: $(CAPT_DIR)/Yeux.h $(CAPT_DIR)/Yeux.cpp $(CAPT_DIR)/Capteur.h
	g++ $(COpts) -c $(CAPT_DIR)/Yeux.cpp

Oreilles.o: $(CAPT_DIR)/Oreilles.h $(CAPT_DIR)/Oreilles.cpp $(CAPT_DIR)/Capteur.h
	g++ $(COpts) -c $(CAPT_DIR)/Oreilles.cpp

ComportementKamikaze.o : $(COMP_DIR)/ComportementKamikaze.h $(COMP_DIR)/ComportementKamikaze.cpp $(COMP_DIR)/Comportement.h
	g++ $(COpts) -c $(COMP_DIR)/ComportementKamikaze.cpp

ComportementGregaire.o : $(COMP_DIR)/ComportementGregaire.h $(COMP_DIR)/ComportementGregaire.cpp $(COMP_DIR)/Comportement.h
	g++ $(COpts) -c $(COMP_DIR)/ComportementGregaire.cpp

ComportementPeureuse.o : $(COMP_DIR)/ComportementPeureuse.h $(COMP_DIR)/ComportementPeureuse.cpp $(COMP_DIR)/Comportement.h
	g++ $(COpts) -c $(COMP_DIR)/ComportementPeureuse.cpp

ComportementPrevoyante.o : $(COMP_DIR)/ComportementPrevoyante.h $(COMP_DIR)/ComportementPrevoyante.cpp $(COMP_DIR)/Comportement.h
	g++ $(COpts) -c $(COMP_DIR)/ComportementPrevoyante.cpp

clean:
	rm -rf *.o main