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
#include"Doodlebug.h"
#include"Critter.h"

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
    cout << "Invalid input. 0 < input > 100\n";
    std::cin.clear();
    std::cin.ignore(256,'\n');
    return false;
  }
  return command;
}

Ant **removeAnt(Ant **ants, int dead_ant, int count)
{
  ants[dead_ant]->removeCritter();
  for(int j = dead_ant; j < count; j++)
    ants[j] = ants[j + 1];
  free(ants[count]);
  return ants;
}

int main(int argc, char** argv)
{  
  srand(time(NULL));
  int row = 25, col = 25;
  int day = 0, i, val, j, elapse = 200;
  //int daysAlive = 0;
  int antCount = 100;  
  int doodleCount = 5;

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
    std::cin>>doodleCount;
    while(checkValidInput(doodleCount)==false){ 
       cout<<"Give the number of doodlebug."<<endl;
       std::cin>>doodleCount;
    }

    cout<<"How many days will elapse?"<<endl;
    std::cin>>elapse;
    while(checkValidInput(elapse)==false){ 
       cout<<"Enter the number of days again."<<endl;
       std::cin>>elapse;
    }
/*
    if(antCount <= 2 && beetleCount <= 2){
       antCount = 1;
       beetleCount = 2;
    }
    if(bugCount >= max/2 || beetleCount >= max/2)
    {
      cout<<"Oops!! too many bugs!\nYou need a bigger grid.\n";
      exit(1);
    }
*/
  }
  
  Playground p(row, col);
  
  Doodlebug **doodles = new Doodlebug*[CAP];
  for(int i = 0; i < doodleCount; i++)
     doodles[i] = new Doodlebug(&p, '@');
  Ant **ants = new Ant*[CAP];
  for(int i = 0; i < antCount; i++)
    ants[i] = new Ant(&p,'!'); //(char)((int)'1' + i));

  p.showGrid();

  while(day < elapse)
  {
    i = 0;
    while(ants[i] != nullptr)
    {
      ants[i]->move((rand()%3)-1,(rand()%3)-1);
      if(ants[i]->getDays() > 6)
        ants[i]->setBody('!');
    
      if(ants[i]->getDays() > 10)
      {
        ants = removeAnt(ants, i, antCount);
        antCount--;
        continue;
      }
      i++;
    }
    i = 0; 
    while(doodles[i] != nullptr)
    {
      doodles[i]->move((rand()%3)-1,(rand()%3)-1);
      cout<<doodles[i]->getX()<<" "<<doodles[i]->getY()<<endl;
      i++;
    }

    i=0;
    //Reproduce
    while(ants[i] != nullptr && antCount < CAP/2)
    {
      if((ants[i]->getDays() > 1) && (ants[i]->getDays()%3 == 0))
        ants[antCount] = ants[i]->spawn();
      if(ants[i]->spawnedAnt())
        antCount++;
      ants[i]->setSpawned(false);
      i++;
    }
    p.mySleep(253);
    p.showGrid();
    day++;
    cout<<"Day "<<day<<endl;
    cout<<"antCount "<<antCount<<endl;
  }
  i = 0;
  while(ants[i] != nullptr)
    i++;
  cout<<"Ants array "<<i<<endl;
  cout<<"positions taken "<<p.get_posNum()<<endl;
return 0;
}
