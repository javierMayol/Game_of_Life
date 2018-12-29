/* Javier Mayol
* ant class. Just a simple class with methods for ants.
*/

#include"Ant.h"

Ant::Ant(Playground *s, char b): Critter(s,b){spawned = false;}
 
bool Ant::spawnedAnt(){return spawned;}

void Ant::setSpawned(bool status){spawned = status;}

Ant *Ant::spawn()
{
  Ant *a = nullptr;
  a = (Ant *)this->addCritter(';');
  if(a != nullptr)
  {
    spawned = true;
    return a;
  }
  else
    spawned = false;
  return nullptr;
}
