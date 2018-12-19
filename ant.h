#ifndef ANT_H
#define ANT_H

#include"creature.h"
class ant: public creature
{
  public:
    ant(island *isla, char a);
    ant(island *isla, int x, int y, char a);
    bool set_eaten(bool s);
    void dead_ant();
    bool eaten_yet();
  private:
    bool eaten;
};

#endif
