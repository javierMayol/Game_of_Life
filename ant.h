#ifndef ANT_H
#define ANT_H

#include"Critter.h"
class Ant: public Critter
{
  public:
    Ant(Playground *s, char b);
    void setSpawned(bool status);
    bool spawnedAnt();
    Ant *spawn();
  private:
    bool spawned;
};

#endif
