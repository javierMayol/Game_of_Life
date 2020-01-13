Javier Mayol
cs211 UIC

## Game of Life
  This program idea is described in the textbook Absolute Java by Walter Savitch 
  and has many items related to the GridWorld projects from the AP CS Exam and 
  to John Conway’s Game of Life.

  Written in c++

## Running the program:

  Required files in the same directory:

	Ant.cpp		Doodlebug.cpp	Playground.cpp
	Ant.h		Doodlebug.h	Playground.h	
	Critter.cpp	GridDisplay.cpp	makefile
	Critter.h	GridDisplay.h	main.cpp

  The comman line 'make' will compile and link all files.

  to load: ./game_of_life

  The program can take a command line argument integer n to make a n x n grid. 
  Example: ./game_of_life 20 
  The line above will create a grid 20 x 20.
  The progam will ask the user to specify the number of ants, doodlebugs, and days
  to elapse in the simulation if the argument is entered.

  Otherwise, the program will run with a default 25 X 25 grid with 100 ants, 5 doodlebugs, and
  200 days span.
