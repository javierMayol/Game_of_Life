#include<iostream>
#include "GridDisplay.h"

int main(){
  GridDisplay grid;

  int i = 0;
  grid.showGrid();
  while(i < 10){
    grid.mySleep(200);
    grid.showGrid();
    i++;
  }
}
