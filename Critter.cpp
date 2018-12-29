#include"Critter.h"

Critter::Critter(Playground *s, char b)
{
  site = s;
  body = b;
  days = 0;
  do
  {
    X = rand()%site->getX();
    Y = rand()%site->getY();
  }
  while(!site->pos_available(Y, X));
  site->setChar(Y,X,body);
  site->setPos(Y,X,true);
}

Critter::Critter(Playground *s, char b, int y, int x)
{
  site = s;
  body = b;
  days = 0;
  Y = y;
  X = x;
  site->setChar(Y,X,body);
  site->setPos(Y,X,true);
}

int Critter::getDays(){return days;}

void Critter::setBody(char b){body = b;}

int Critter::getX(){return X;}

int Critter::getY(){return Y;}

//abs func returns absolute value of passed by value parameter.   
int abs(int x){
  return (x < 0)? -x: x;
}

//distance func calculates distance between two points in the grid.
int distance(int x1, int y1, int x2, int y2){
  return abs(x1 - x2) + abs(y1 - y2);      
}

void Critter::move(int y, int x)
{
  days++;

//  int y = (rand()%3) - 1;
//  int x = (rand()%3) - 1;
  if((x == 0)&&(y == 0))
    return;
  x+=X;
  y+=Y;
  if(x > site->getX()-1 || y > site->getY()-1)
    return;
  if(y < 0 || x < 0)
    return;
  if(!site->pos_available(y,x))
  return;
  else {
    site->setChar(y,x,body);
    site->setChar(Y,X,'.');
    site->setPos(y,x,true);
    site->setPos(Y,X,false);
  }
  X = x;
  Y = y;
  //cout<<"else"<<endl;
}

Critter* Critter::addCritter(char b)
{
  int y = (rand()%3) - 1;
  int x = (rand()%3) - 1;
  if((x == 0)&&(y ==0))
    return nullptr;
  x+=X;
  y+=Y;
  if(x > site->getX()-1 || y > site->getY()-1)
    return nullptr;
  if(y < 0 || x < 0)
    return nullptr;
  if(!site->pos_available(y,x))
    return nullptr;
  else
    return new Critter(site,b ,y, x);
}
void Critter::removeCritter()
{
  site->setChar(Y,X,'.');
  site->setPos(Y,X,false);
}
