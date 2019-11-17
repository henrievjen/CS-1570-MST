// Henri Evjen
// 11/5/19
// HW9
// Purpose: this program tests classes created to represent a hospital room, an
// x-ray machine, and patients

#include <iostream>
#include "Hospital_Room.h"
#include "X_Rayer.h"
using namespace std;

void Hospital_Room::admit(Patient & pat)
{
  the_machine.charge_patient(pat);
  the_machine.apply(pat);

  return;
}

X_Rayer Hospital_Room::getTheMachine()const
{
  return the_machine;
}

float Hospital_Room::getOzsOfGin()const
{
  return ozs_of_gin;
}

ostream & operator << (ostream & out, Hospital_Room & hr) 
{ 
  X_Rayer machine = hr.getTheMachine();
  out << machine;
  out << "There are " << hr.getOzsOfGin() << " ounces of gin." << endl;
    
  return out; 
}
