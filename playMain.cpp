#include<iostream>
#include"Critter.h"

using namespace std;

int main(){
  srand(time(NULL));
  Playground p(20, 20);
  Critter bugs(&p, '@');
  p.showGrid();
  int i = 0;
  Critter *offSpring = nullptr;
  while(i < 200)
  {
    bugs.move((rand()%3)-1, (rand()%3)-1);
    p.mySleep(250);
    p.showGrid();
    i++;
    if(i%10 == 0 && offSpring == nullptr)
      offSpring = bugs.addCritter('S');
    if(offSpring != nullptr)
      offSpring->move((rand()%3)-1, (rand()%3)-1);
    cout<<bugs.getX()<<" "<<bugs.getY()<<endl;
    if(offSpring != nullptr && offSpring->getDays() > 8)
      offSpring->setBody('@');
    if(offSpring != nullptr)
      cout<<offSpring->getX()<<" "<<offSpring->getY()<<endl;
    cout<<"Day "<<i<<endl;
  }
return 0;
}
