#include<iostream>
#include<cstdlib>
#include"GridDisplay.h"
using namespace std;

class Playground: public GridDisplay
{
 public:
    Playground(int x, int y);
    ~Playground();
    int getX();
    int getY();
    bool pos_available(int x, int y);
    void setPos(int x, int y, bool status);
    int get_posNum();

  private:
    int posX;
    int posY;
    int pos_num;
    bool **pos_ptr;
};
