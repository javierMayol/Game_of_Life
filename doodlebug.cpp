/*
 * Javier Mayol
 * doodlebug class : Game of Life 
*/

#include"Doodlebug.h"

Doodlebug::Doodlebug(Playground *s, char b): Critter(s,b){spawned = false;}
 
bool Doodlebug::spawnedDoodle(){return spawned;}

void Doodlebug::setSpawned(bool status){spawned = status;}

Doodlebug *Doodlebug::spawn()
{
  Doodlebug *a = nullptr;
  a = (Doodlebug *)this->addCritter(',');
  if(a != nullptr)
  {
    spawned = true;
    return a;
  }
  else
    spawned = false;
  return nullptr;
}

