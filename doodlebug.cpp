/*
 * Javier Mayol
 * doodlebug class : Game of Life 
*/

#include"Doodlebug.h"

Doodlebug::Doodlebug(Playground *s, char b): Critter(s,b){spawned = false; 
days_starving = 0;}
 
bool Doodlebug::starvingBug(int starve)
{
  return (days_starving > starve);
}

bool Doodlebug::spawnedDoodle(){return spawned;}

void Doodlebug::setSpawned(bool status){spawned = status;}

void Doodlebug::move(int y, int x)
{
  days++;
  days_starving++;
//  int y = (rand()%3) - 1;
//  int x = (rand()%3) - 1;
  if((x == 0)&&(y == 0))
    return;
  x+=X;
  y+=Y;
  if(y < 0 || x < 0)
    return;
  if(!site->pos_available(y,x))
    return;
  else {
    site->setChar(y,x,body);
    site->setChar(Y,X,'.');
    site->setPos(y,x,false);
    site->setPos(Y,X,true);
  }
  X = x;
  Y = y;
  //cout<<"else"<<endl;
}

Doodlebug *Doodlebug::spawn()
{
  Doodlebug *d = nullptr;
  d = (Doodlebug *)this->addCritter('@');
  if(d != nullptr)
  {
    spawned = true;
    return d;
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

bool Doodlebug::hunt(Ant **ants, int& index)
{
  int i = 0;
  while(ants[i] != nullptr)
  {
    if(distance(this->X, this->Y, ants[i]->getX(), ants[i]->getY()) <= 1)
    {
       body = 'O';
       days_starving = 0;
       index = i;
       return true;
    }
    i++;
  }
  body = '@';
  return false;
}
