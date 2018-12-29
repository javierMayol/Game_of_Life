#ifndef CREATURE_H
#define CREATURE_H

#include"GridDisplay.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class creature;

class island
{
  private:
    creature ***location; //Dynamic 2d array of pointers;
    int rows;
    int cols;
    GridDisplay *gd;
  public:
    island(GridDisplay *grid, int r, int c);
    void clear(int x, int y);
    int get_rows();
    int get_cols();
    bool is_valid(int r, int c);
    bool is_occupied(int r, int c);
    bool add_beetle(creature* b, int r, int c, char a);
    bool move_beetle(int currX, int currY, int nextX, int nextY, char a);
};

class creature
{ 
  public:
    island *isl;
    char bug; 
    int posX, posY, moveX, moveY;
    int days;
    bool spawned;
  public:
    void discard(int r, int c);
    creature(island *Island, char a);
    creature(island *Island, int x, int y, char a);
    void setX(int x);
    void setY(int y);
    int get_moveX();
    int get_moveY();
    virtual bool next_position();
    int days_alive() const;
    int get_x();
    int get_y();
    virtual void wander();
    bool hasSpawned();
    virtual creature* spawn(char a);

};
#endif
