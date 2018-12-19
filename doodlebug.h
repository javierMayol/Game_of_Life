#ifndef DOODLEBUG_h
#define DOODLEBUG_h

#include"creature.h"
#include"ant.h"

class doodlebug: public creature
{
  public:
    doodlebug(island *isla, char a);
    doodlebug(island *isla, int x, int y, char a);
    void set_starved(bool a);
    void gobble();
    int starve();
    void starve_doodle(int n);
    bool starved_yet();
    int hunting(ant **a, int j);
    int huntCount();
  private:
   bool starved;
   int days_starving;
   int hunt;
};
#endif
