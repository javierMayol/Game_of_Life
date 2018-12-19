/*
 * Javier Mayol
 * doodlebug class : Game of Life 
*/

#include"doodlebug.h"

doodlebug::doodlebug(island *isla, char a): creature(isla, a){starved = false; days_starving = 0; hunt = 0;}

//Polymorphism to accept coordinates.
doodlebug::doodlebug(island *isla, int x, int y, char a): creature(isla, x, y, a){starved = false; days_starving = 0; hunt = 0;}

void doodlebug::set_starved(bool a){starved = a;}

void doodlebug::gobble(){days_starving = 0;}

int doodlebug::starve(){
   days_starving++; 
    return days_starving;
}

void doodlebug::starve_doodle(int n){
  if(this->days_starving > n){
    this->discard(posX, posY);
    this->set_starved(true);
  }
}

//starved_yet function is used to verify if doodlebus is dead.
bool doodlebug::starved_yet(){return starved;}

//abs func returns absolute value of passed by value parameter.   
int abs(int x){
  return (x < 0)? -x: x;
}

//distance func calculates distance between two points in the grid.
int distance(int x1, int y1, int x2, int y2){
  return abs(x1 - x2) + abs(y1 - y2);      
}

//hunting function Takes an ants array and verify distance beetween a single doodlebug 
//and all ants. If distance is less than 2, the ant is in the perimeter and the
//doodlebug can feast.
int doodlebug::hunting(ant **a, int j){
  int attack = 0;
  if(a[j] != nullptr && this->starved==false){
    attack = distance(a[j]->get_x(), a[j]->get_y(), posX, posY);
    if(attack <= 2){
      a[j]->dead_ant();
      this->gobble();
      this->hunt++;
      return hunting(a, j + 1);
    }
  }
  return attack;
}

int doodlebug::huntCount(){return hunt;}

