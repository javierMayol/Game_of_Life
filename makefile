game_of_life: playMain.o GridDisplay.o Critter.o Playground.o 
	g++ -g -o game_of_life playMain.o Playground.o Critter.o GridDisplay.o 

demo_game: main.o GridDisplay.o Critter.o Playground.o Ant.o Doodlebug.o
	g++ -g -o demo_game main.o Playground.o Critter.o GridDisplay.o Ant.o Doodlebug.o 

GridDisplay.o: GridDisplay.cpp GridDisplay.h
	g++ -c GridDisplay.cpp

Critter.o: Critter.cpp Critter.h GridDisplay.h
	g++ -c Critter.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h Critter.h
	g++ -c Doodlebug.cpp

Ant.o: Ant.cpp Ant.h Critter.h
	g++ -c Ant.cpp

Playground.o: Playground.cpp Playground.h GridDisplay.h
	g++ -c Playground.cpp

playMain.o: playMain.cpp Critter.o 
	g++ -c playMain.cpp

main.o: main.cpp Ant.o
	g++ -c main.cpp

clean:
	rm -f *.o  game_of_life demo_game
