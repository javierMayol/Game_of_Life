/* Javier Mayol 
 * Simulation of population growth of algorithm between two groups of insects: doodlebugs and ants.
 * Based in Conway's Game of Life https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 * checkValidInput(int) verifies if the argument entered by the user is a valid integer.
 * and populates the row variable with that integer value.
 * main() consist in conditionals to evaluate the dimensions of grid and specific number 
 * of ants and doodlebugs for the simulation.
 * Also in main() the array of ants and doodlebugs objects are initialized as well 
 * as the grid. 
 * After initialization the code contains a busy while loop that verifies that the 
 * number of "days" in the day variable is less than the number in variable elapse. 
 * each "day" last 200/1000 milliseconds.
 * The loop executes spawing and hunting of the insects in the simulation. 
 */
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Ant.h"
#include"Critter.h"
#include"Doodlebug.h"

using namespace std;

int CAP = 25 * 25;

bool checkValidInput(int command)
{
  if(std::cin.fail()){ 
    cout << "Invalid input.\n";
    std::cin.clear();
    std::cin.ignore(256,'\n');
    return false;
  }
  else if(command < 0 || command > 1000){
    cout << "Invalid input. 0 < input > 1000\n";
    std::cin.clear();
    std::cin.ignore(256,'\n');
    return false;
  }
  return command;
}

Ant **removeAnt(Ant **ants, int dead_ant, int count)
{
  ants[dead_ant]->removeCritter();
  for(int j = dead_ant; j < count; j++){
    ants[j] = ants[j + 1];
  }
  free(ants[count]);
  return ants;
}

Doodlebug **removeBug(Doodlebug **bugs, int dead_bug, int count)
{
  bugs[dead_bug]->removeCritter();
  for(int i = dead_bug; i < count; i++){
    bugs[i] = bugs[i + 1];
  }
  free(bugs[count]);
  return bugs;
}

int main(int argc, char** argv)
{  
  srand(time(NULL));
  int row = 25, col = 25;
  int day = 0, i, j,elapse = 200;
  int antCount = 100;  
  int bugCount = 5;

  if(argc > 1){
    row = atoi(argv[1]);
    while((!checkValidInput(row) || row < 3) || (!checkValidInput(row) || row > 150)){
        cout<<"It have to be a number between 3 and 150.\n";
        cout<<"Set the length of the grid.\n";
        std::cin>>row;
        checkValidInput(row);
    }
    col = row;
    CAP = row * row;
    cout<<"Give the number of ants."<<endl;
    std::cin>>antCount;
    while(checkValidInput(antCount)==false){ 
       cout<<"Give the number of ants."<<endl;
       std::cin>>antCount;
    }
    
    cout<<"How many doodlebugs?"<<endl;
    std::cin>>bugCount;
    while(!checkValidInput(bugCount)){
      cout<<"Give the number of doodlebugs."<<endl;
      std::cin>>bugCount;
    }

    cout<<"How many days will elapse?"<<endl;
    std::cin>>elapse;
    while(checkValidInput(elapse)==false){ 
       cout<<"Enter the number of days again."<<endl;
       std::cin>>elapse;
    }
    
    if(antCount >= CAP/2 || bugCount >= CAP/2)
    {
      cout<<"Oops!! Too many bugs!\nYou need a bigger grid."<<endl;
      exit(-1);
    }
  }
  Playground p(row, col);
  
  Ant **ants = new Ant*[CAP];
  for(int i = 0; i < antCount; i++)
    ants[i] = new Ant(&p,'!'); //(char)((int)'1' + i));
  Doodlebug **bugs = new Doodlebug *[CAP];
  for(int j = 0; j < bugCount ; j++)
    bugs[j] = new Doodlebug(&p, '@');

  p.showGrid();

  while(day < elapse)
  {
    //Ants loop.
    i = 0;
    while(ants[i])
    {
      ants[i]->move((rand()%3)-1,(rand()%3)-1);
      if(ants[i]->getDays() > 2)
        ants[i]->setBody('!');
      if(((ants[i]->getDays() > 1) && (ants[i]->getDays()%3 == 0)) && antCount < CAP/2)
      {
        ants[antCount] = ants[i]->spawn();
        if(ants[i]->spawnedAnt())
        {
	  antCount++;
	  continue;
 	}
      }
      ants[i]->setSpawned(false);
      i++;
    }

    //Doodlebugs loop
    j = 0;
    while(bugs[j])
    { 
      bugs[j]->move((rand()%3)-1, (rand()%3)-1);
      if(bugs[j]->getDays()%8 == 0 && bugCount < CAP/2)
      {
	bugs[bugCount] = bugs[j]->spawn();
	if(bugs[j]->spawnedDoodle())
    	{
	  bugCount++;
	  continue;
	}
      }
      bugs[j]->setSpawned(false);
      if(bugs[j]->starvingBug(3))
      {
        bugs=removeBug(bugs,j,bugCount);
        bugCount--;
   	continue;
      }
      if(bugs[j]->hunt(ants, i))
      {
        ants=removeAnt(ants, i, antCount);
  	antCount--;
      }
      j++;
    }

    //Animation starts
    p.mySleep(200);
    p.showGrid();
    day++;
    cout<<"Day "<<day<<endl;
    cout<<"antCount "<<antCount<<endl;
    cout<<"bugCount "<<bugCount<<endl;
    cout<<"positions taken "<<p.get_posNum()<<endl;
    //Animation ends
  }
  i = 0;
  while(ants[i])
    i++;
  cout<<"Ants array "<<i<<endl;

  for(j = 0; j < i; j++)
    free(ants[j]);
  delete[] ants;

  i = 0;
  while(bugs[i])
    i++;
  cout<<"Bugs array "<<i<<endl;
  
  for(j = 0; j < i; j++)
    free(bugs[j]);
  delete[] bugs;

  return 0;
}
