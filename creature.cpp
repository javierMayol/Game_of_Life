/* Javier Mayol
* creature class
* Inherited by ant and doodlebus classes.
* contains basic methods for a bugs life and dead.
* also contains methods to create a grid.
*/
#include"creature.h"

island::island(GridDisplay *grid, int r, int c){
  gd = grid;   
  rows = r;
  cols = c;
  location = new creature**[rows];
  for(int i = 0; i < cols; i++){
     location[i] = new creature*[cols];
     for(int j = 0; j < cols; j++)
         location[i][j] = nullptr;
  }
}
void island::clear(int x, int y){
  location[x][y] = nullptr;
  gd->setChar(x,y,'.');
}
int island:: get_rows(){
  return rows;
}
int island::get_cols(){
  return cols;
}
bool island::is_valid(int r, int c){
  if((r >=0 && r < rows) && ( c >= 0 && c < cols))
    return true;
  else
    return false;
}

bool island::is_occupied(int r, int c){
  if(location[r][c]==nullptr)
    return false;
  else
    return true;
}
bool island::add_beetle(creature* b, int r, int c, char a){
  if(is_valid(r,c) == false)
    return false;
  if(is_occupied(r,c) == true)
    return false;
  location[r][c] = b;
  gd->setChar(r,c,a);
  return true;
}
bool island::move_beetle(int currX, int currY, int nextX, int nextY, char a){
  if(is_valid(currX, currY) == false)
    return false;
  if(is_valid(nextX, nextY) == false)
    return false;
  if(is_occupied(currX, currY) == false)
    return false;
  if(is_occupied(nextX, nextY) == true)
    return false;
  location[nextX][nextY] = location[currX][currY];
  location[currX][currY] = nullptr;
  gd->setChar(currX,currY,'.');
  gd->setChar(nextX,nextY, a);
  return true;
}
creature::creature(island *Island, char a){
  isl = Island;
  bug = a;
  spawned = false;
  do{
    posX = rand()%Island->get_rows();    
    posY = rand()%Island->get_cols();
  }
 
  while(Island->add_beetle(this, posX, posY, bug)== false);
  days = 0;
}

creature::creature(island *Island, int x, int y, char a){
  isl = Island;
  bug = a;
  posX = x;    
  posY = y;
  spawned = false;
  if(Island->add_beetle(this, posX, posY, bug)== false)
  days = 0;
}
void creature::discard(int r, int c){
   this->isl->clear(r,c);
}
void creature::setX(int x){
   posX = x;
}
void creature::setY(int y){
   posY = y;
}
int creature::get_moveX(){
  return moveX;
}
int creature::get_moveY(){
  return moveY;
}
int creature::days_alive() const{
  return days;
}
int creature::get_x(){
  return posX;
}
int creature::get_y(){
  return posY;
}
bool creature:: next_position(){
  int nextX = -999;
  int nextY = -999;
  int direction = rand()%4;
  if(direction == 0){
    nextX = posX;
    nextY = posY - 1;
  }
  else if(direction == 1){
    nextX = posX;
    nextY = posY + 1;
  }
  else if(direction == 2){
    nextX = posX - 1;
    nextY = posY;
  }
  else if(direction == 3){
    nextX = posX + 1;
    nextY = posY;
  }
  if(isl->is_valid(nextX,nextY) == true && isl->is_occupied(nextX,nextY) == false)
  {
    moveX = nextX;
    moveY = nextY;
    spawned = true;
    return true;
  }
  else
    spawned = false;
  return false;
}
 
void creature::wander() {
  int nextX = -999;
  int nextY = -999;
  int direction = rand()%4;
  if(direction == 0){
    nextX = posX;
    nextY = posY - 1;
  }
  else if(direction == 1){
    nextX = posX;
    nextY = posY + 1;
  }
  else if(direction == 2){
    nextX = posX - 1;
    nextY = posY;
  }
  else if(direction == 3){
    nextX = posX + 1;
    nextY = posY;
  }
  if(isl->move_beetle(posX, posY, nextX, nextY, this->bug) == true){
    posX = nextX;
    posY = nextY; 
    days++;
  }
}

creature* creature::spawn(char a){
  if(next_position()==true)
    return new creature(isl, moveX, moveY, a);
  else 
    return nullptr;
}

bool creature::hasSpawned(){return spawned;}  

