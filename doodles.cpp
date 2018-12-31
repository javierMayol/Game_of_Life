#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Doodlebug.h"
#include"Critter.h"

int main(){
  srand(time(NULL));
  Playground p(20, 20);
  Doodlebug **d = new Doodlebug *[200];
  int count = 10;
  for(int i = 0; i < count; i++)
    d[i] = new Doodlebug(&p, '@');

  p.showGrid();
  int b, i = 0;
  while(i < 50)
  {
    b = 0;
    while(d[b] != nullptr)
    {
      d[b]->move((rand()%3)-1,(rand()%3)-1);
      if(d[b]->getDays()%3 == 0 && count < 150)
      {
         d[count] = d[b]->spawn();
         if(d[b]->spawnedDoodle())
         {
	   count++;
	   continue;
	 }
      }
      b++;
    }
    p.mySleep(200);
    p.showGrid();
    i++;
  }
}
