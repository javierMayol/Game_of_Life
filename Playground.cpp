#include <ctime>
#include"Playground.h"

Playground::Playground(int y, int x): GridDisplay(y, x)
{
  posX = x;
  posY = y;
  pos_num = 0;
  //Allocate memory for pos_ptr.
  pos_ptr = new bool *[y];
  for(int i = 0; i < x; i++){
    pos_ptr[i] = new bool [x];
  }
  //Initialize to false all positions.
  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++)
      pos_ptr[i][j] = (bool *)true;
  } 
}

Playground::~Playground()
{
  pos_num = 0;
  for(int i = 0; i < posX; i++){
    free(pos_ptr[i]);
  }
  delete[] pos_ptr;
  posX = 0;
  posY = 0;
}

int Playground::getX(){return colCount;}

int Playground::getY(){return rowCount;}

bool Playground::pos_available(int y, int x)
{ 
  if((x >= posX)||(y >= posY)) return false;
  return pos_ptr[y][x];
}

void Playground::setPos(int y, int x, bool status)
{
  pos_ptr[y][x] = status;
  if(status == true)
    pos_num--;
  else
    pos_num++;
}
 
int Playground::get_posNum()
{
  return pos_num;
}
