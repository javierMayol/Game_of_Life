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
#include"ant.h"
#include"doodlebug.h"
#include "creature.h"

#define DOODLEBUG_H
#define ANT_H

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

int main(int argc, char** argv)
{  
  srand(time(NULL));
  int row = 25, col = 25;
  int day = 0, i, val, j, elapse = 200;
  int daysAlive = 0;
  int bugCount = 20;
  int beetleCount = 15;
  int max = 25 * 25;

  if(argc > 1){
    row = atoi(argv[1]);
    while((!checkValidInput(row) || row < 3) || (!checkValidInput(row) || row > 150)){
        cout<<"It got to be a number between 3 and 150.\n";
        cout<<"Set the length of the grid.\n";
        std::cin>>row;
        checkValidInput(row);
    }
    col = row;
    max = row * row;
    cout<<"Give the number of ants."<<endl;
    std::cin>>bugCount;
    while(checkValidInput(bugCount)==false){ 
       cout<<"Give the number of ants."<<endl;
       std::cin>>bugCount;
    }
    cout<<"How many doodlebugs?"<<endl;
    std::cin>>beetleCount;
    while(checkValidInput(bugCount)==false){ 
       cout<<"Give the number of doodlebug."<<endl;
       std::cin>>beetleCount;
    }
    cout<<"How many days will elapse?"<<endl;
    std::cin>>elapse;
    while(checkValidInput(elapse)==false){ 
       cout<<"Enter the number of days again."<<endl;
       std::cin>>elapse;
    }
    if(bugCount <= 2 && beetleCount <= 2){
       bugCount = 1;
       beetleCount = 2;
    }
    if(bugCount >= max/2 || beetleCount >= max/2)
    {
      cout<<"Oops!! too many bugs!\nYou need a bigger grid.\n";
      exit(1);
    }
  }  

  GridDisplay gd(row, col);
  island island(&gd, row, col);
  ant **bug = new ant*[max];
  doodlebug **beetle = new doodlebug*[max];

  for(int i = 0; i < bugCount; i++)
    bug[i] = new ant(&island, '!');
  
  for(int i = 0; i < beetleCount; i++)
    beetle[i] = new doodlebug(&island, '@');  

  gd.showGrid();
  int count, e, starve = 0;

  //Game starts
  while(day < elapse){
    day++;

    //set count with the lower bug or beetle value to prevent segmentation fault 11.
    if(bugCount < beetleCount)
      count = bugCount;
    else if(bugCount > beetleCount)
      count = beetleCount;
    else if(bugCount == beetleCount)
      count = bugCount - 2;

    //Hunt
    i = 0;
    while(bug[i] != nullptr){
     j = 0; 
     while(beetle[j] != nullptr){
       if(!beetle[j]->starved_yet())
         beetle[j]->hunting(bug[i]);
       else
         beetle[j]->starve();
       beetle[j]->starve_doodle(50);
       j++;
      }
      if(!bug[i]->eaten_yet())
        bug[i]->wander();
      i++;
    }
       
    //Doodlebug wander
    i = 0;
    while(beetle[i] != nullptr)
    {
      doodlebug *spawny = nullptr;
      if(!beetle[i]->starved_yet())
        beetle[i]->wander();
      i++;
    }
/*
    i = 0;
    while(i < count)
    {
      if((!beetle[i]->starved_yet()) && (day%8 == 0))
        beetle[beetleCount] = (doodlebug *)beetle[i]->spawn('@');
      if(beetle[i]->hasSpawned()) beetleCount++;
      i++;
    }
    //reproduce
    if(beetleCount < max/2 && bugCount < max/2){
      for(int k = 0; k < rand()%count; k++){
        val = rand() % count;
        if(bug[val]->eaten_yet()==false){
          if(day % 3 == 0 && bug[val]->next_position() == true){
            bug[bugCount] = new ant(&island, bug[val]->get_moveX(), bug[val]->get_moveY(), '!');
            bugCount++;
          }
        }
        val = rand() % count;
        if(!beetle[val]->starved_yet()){
          if(day % 3 == 0 && beetle[val]->next_position() == true){
            beetle[beetleCount] = new doodlebug(&island, beetle[val]->get_moveX(), beetle[val]->get_moveY(),'@');
            beetleCount++;
          }
        }
        else if(beetleCount <= 2 && bugCount <= 2){
          val = rand() % 2;
	  if(!bug[val]->eaten_yet()){
            if(day % 3 == 0 && bug[val]->next_position() == true){
              bug[bugCount] = new ant(&island, bug[val]->get_moveX(), bug[val]->get_moveY(), '!');
	      bugCount++;
            }
       	  }
          val = rand() % 2;
          if(!beetle[val]->starved_yet()){
            if(day % 3 == 0 && beetle[val]->next_position() == true){
              beetle[beetleCount] = new doodlebug(&island, beetle[val]->get_moveX(), beetle[val]->get_moveY(),'@');
	    beetleCount++;
            }
          }  
        }
      }
    }
*/
  //animation;
  gd.mySleep(200);
  gd.showGrid();

  cout<<"days "<<day<<endl;
  cout<<"doodlebugs "<<beetleCount<<endl;
} 
  j = 0;
  int hunt = 0;

  while(beetle[j] != nullptr){  
    hunt = beetle[j]->huntCount();
    cout<<"doodlebug["<<j<<"]"<<"hunts = "<<hunt<<endl;
    j++;
  }
  for(i = 0; i < j ; i++)
    free(beetle[i]);

  free(beetle);
}

