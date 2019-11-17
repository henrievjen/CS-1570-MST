// Henri Evjen
// 11/5/19
// HW9
// Purpose: this program tests classes created to represent a hospital room, an
// x-ray machine, and patients

#ifndef X_RAYER_H
#define X_RAYER_H

#include <iostream>
#include "Patient.h"
using namespace std;

class X_Rayer
{
  private:
    short num_uses;
    float cost_per_use;

  public:
    X_Rayer():num_uses(0), cost_per_use(550) {}

    // Description: charges a patient by the cost per use of x-ray machine
    // Pre-condition: none
    // Post-condition: patient passed by reference is charged cost per use
    void charge_patient(Patient & pat)const;

    // Description: 10% of the time halves the patient's condition value
    // Pre-condition: none
    // Post-condition: 10% of the time, condition of patient is halved
    void apply(Patient & pat);

    // Description: returns x-ray machine's cost per use
    // Pre-condition: none
    // Post-condition: x-ray machine's cost per use is returned
    float getCostPerUse()const;

    // Description: returns the number of times the x-ray machine has been used
    // Pre-condition: none
    // Post-condition: number of times x-ray machine has been used is returned
    short getNumUses()const;
    friend ostream & operator << (ostream & out, X_Rayer & x);
};

#endif
