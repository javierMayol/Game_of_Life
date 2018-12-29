#ifndef DOODLEBUG_h
#define DOODLEBUG_h

#include"Critter.h"

#define ANT_H

class Doodlebug: public Critter
{
  public:
    Doodlebug(Playground *s, char b);
    void setSpawned(bool status);
    bool spawnedDoodle();
    Doodlebug *spawn();
  private:
   bool spawned;
   int days_starving;
};
#endif
