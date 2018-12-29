#include <ctime>
#include"Playground.h"

Playground::Playground(int y, int x): GridDisplay(y, x)
{
  posX = x;
  posY = y;
  pos_num = 0;
  pos_ptr = new bool **[y];
  for(int i = 0; i < x; i++){
    pos_ptr[i] = new bool *[x];
    for(int j = 0; j < x; j++)
      pos_ptr[i][j] = (bool *)false;
  } 
}

int Playground::getX(){return colCount;}

int Playground::getY(){return rowCount;}

bool Playground::pos_available(int y, int x)
{ 
  return !pos_ptr[y][x];
}

void Playground::setPos(int y, int x, bool status)
{
  if(!pos_available(y,x))
    pos_ptr[y][x] = (bool *)status;
  if(status == true)
    pos_num++;
  if(status == false)
    pos_num--;
}
 
int Playground::get_posNum()
{
  return pos_num;
}
