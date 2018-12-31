#ifndef CRITTER_H
#define CRITTER_H

#include"Playground.h"
#include<ctime>

class Critter
{
  protected:
    Playground *site;
    int X, Y, days;
    char body;
  public:
    Critter(Playground *s, char b);
    Critter(Playground *s, char b, int y, int x);
    ~Critter();
    int getDays();
    void setBody(char b);
    int getX();
    int getY();
    virtual void move(int y, int x);
    Critter* addCritter(char b);
    void removeCritter();
};
#endif
