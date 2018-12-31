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
  site->setPos(Y,X,false);
}

Critter::Critter(Playground *s, char b, int y, int x)
{
  site = s;
  body = b;
  days = 0;
  Y = y;
  X = x;
  site->setChar(Y,X,body);
  site->setPos(Y,X,false);
}

Critter::~Critter()
{
  delete[] site;
}

int Critter::getDays(){return days;}

void Critter::setBody(char b){body = b;}

int Critter::getX(){return X;}

int Critter::getY(){return Y;}

void Critter::move(int y, int x)
{
  days++;

//  int y = (rand()%3) - 1;
//  int x = (rand()%3) - 1;
  if((x == 0)&&(y == 0))
    return;
  x+=X;
  y+=Y;
  if(y < 0 || x < 0)
    return;
  if(!site->pos_available(y,x))
    return;
  else {
    site->setChar(y,x,body);
    site->setChar(Y,X,'.');
    site->setPos(y,x,false);
    site->setPos(Y,X,true);
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
  if(y < 0 || x < 0)
    return nullptr;
  if(!site->pos_available(y,x))
    return nullptr;
  else
    return new Critter(site,b,y,x);
}

void Critter::removeCritter()
{
  site->setChar(Y,X,'.');
  site->setPos(Y,X,true);
}
