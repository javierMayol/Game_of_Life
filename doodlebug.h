#ifndef DOODLEBUG_h
#define DOODLEBUG_h

#include"Critter.h"
#include"Ant.h"

class Doodlebug: public Critter
{
  public:
    Doodlebug(Playground *s, char b);
    bool starved(int starve);
    void setSpawned(bool status);
    bool spawnedDoodle();
    Doodlebug *spawn();
    bool hunt(Ant **ants, int *index);
  private:
   bool spawned;
   int days_starving;
};
#endif
