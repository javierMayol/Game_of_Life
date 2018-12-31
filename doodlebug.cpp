/*
 * Javier Mayol
 * doodlebug class : Game of Life 
*/

#include"Doodlebug.h"

Doodlebug::Doodlebug(Playground *s, char b): Critter(s,b){spawned = false; 
days_starving = 0;}
 
bool Doodlebug::starved(int starve)
{
  days_starving++;
  if(days_starving >= starve)
    return true;
  return false;
}

bool Doodlebug::spawnedDoodle(){return spawned;}

void Doodlebug::setSpawned(bool status){spawned = status;}

Doodlebug *Doodlebug::spawn()
{
  Doodlebug *a = nullptr;
  a = (Doodlebug *)this->addCritter('@');
  if(a != nullptr)
  {
    spawned = true;
    return a;
  }
  else
    spawned = false;
  return nullptr;
}

//abs func returns absolute value of passed by value parameter.   
int abs(int x){
  return (x < 0)? -x: x;
}

//distance func calculates distance between two points in the grid.
int distance(int x1, int y1, int x2, int y2){
  return abs(x1 - x2) + abs(y1 - y2);      
}

bool Doodlebug::hunt(Ant **ants, int *index)
{
  int i = 0;
  while(ants[i] != nullptr)
  {
    if(distance(this->X, this->Y, ants[i]->getX(), ants[i]->getY()) <= 1)
    {
       body = 'O';
       days_starving = 0;
       *index = i;
       return true;
    }
    i++;
  }
  body = '@';
  return false;
}
