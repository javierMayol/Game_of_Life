Javier Mayol
cs 211 UIC

## Game of Life
This program idea is described in the textbook Absolute Java by Walter Savage 
and has many items related to the GridWorld projects from the AP CS Exam and 
to John Conway’s Game of Life.

Written in c++

# Running the program:

  Required files in the same directory:

     GridDisplay.cpp	README.txt	ant.h		creature.h	doodlebug.h	makefile
     GridDisplay.h	ant.cpp		creature.cpp	doodlebug.cpp	gameMain.cpp

  run comman 'make' in the command line.

  to load run ./game_of_life

  The program can take an argument n to make a n rows x n columns grid if the user species it. 
  Example: ./game_of_life 20 will create a grid 20 x 20.
  The progam will ask the user to specify the number of ants, doodlebugs, and days
  to elapse in the simulation if the argument is entered.

  Otherwise, the program will run with a default 25 X 25 grid with 20 ants, 52 doodlebugs, and
  200 days span.
