/* Javier Mayol
* ant class. Just a simple class with methods for ants.
*/

#include"ant.h"

//Constructors
ant::ant(island *isla, char a): creature(isla, a){eaten = false;}
    
ant::ant(island *isla, int x, int y, char a): creature(isla, x, y, a){eaten = false;};
    
//set_eaten funstion pass a boolean type value true if the ant is eaten by a doodlebug.
bool ant::set_eaten(bool s){eaten = s; return eaten;}
    
void ant::dead_ant(){       
  this->discard(this->get_x(), this->get_y());
  this->set_eaten(true);
}
    
bool ant::eaten_yet(){return eaten;}
