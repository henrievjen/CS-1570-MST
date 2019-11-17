// Henri Evjen
// 11/5/19
// HW9
// Purpose: this program tests classes created to represent a hospital room, an
// x-ray machine, and patients

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

#include <iostream>
#include "X_Rayer.h"
using namespace std;

class Hospital_Room
{
  private:
    X_Rayer the_machine;
    float ozs_of_gin;

  public:
    Hospital_Room():ozs_of_gin(10.0) {}

    // Description: calls the patient's charge_patient and apply functions
    // Pre-condition: none
    // Post-condition: charge_patient and apply for the patient are called
    void admit(Patient & pat);

    // Description: returns hospital room's x-ray machine object
    // Pre-condition: none
    // Post-condition: hospital room's x-ray machine object is returned
    X_Rayer getTheMachine()const;

    // Description: returns amount of ozs of gin in hospital room
    // Pre-condition: none
    // Post-condition: ozs of gin in hospital room is returned
    float getOzsOfGin()const;
    friend ostream & operator << (ostream & out, Hospital_Room & hr);
};

#endif
