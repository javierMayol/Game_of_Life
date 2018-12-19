game_of_life: gameMain.o GridDisplay.o creature.o doodlebug.o ant.o
	g++ -g -o game_of_life gameMain.o GridDisplay.o creature.o doodlebug.o ant.o

GridDisplay.o: GridDisplay.cpp GridDisplay.h
	g++ -c GridDisplay.cpp

creature.o: creature.cpp creature.h GridDisplay.h
	g++ -c creature.cpp

ant.o: ant.cpp ant.h creature.h
	g++ -c ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.h creature.h
	g++ -c doodlebug.cpp

gameMain.o: gameMain.cpp doodlebug.o ant.o
	g++ -c gameMain.cpp

clean:
	rm -f *.o  game_of_life game
