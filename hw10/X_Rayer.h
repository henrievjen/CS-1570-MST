// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef X_RAYER_H
#define X_RAYER_H

#include <iostream>
#include "Patient.h"
#include "Doctor.h"
using namespace std;

class X_Rayer
{
  private:
    short m_num_uses;
    float m_cost_per_use;

  public:
    X_Rayer(): m_num_uses(0), m_cost_per_use(550) {}

    // Description: charges the patient the cost of the x-ray machine and
    // gives half the charge to the doctor
    // Pre-condition: none
    // Post-condition: patient's money is decreased by cost of x-ray machine
    // and doctor's money is increased by half the cost
    void charge_patient(Patient & pat, Doctor & doc)const;

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

    // Description: returns the name of the machine
    // Pre-condition: none
    // Post-condition: name of the machine is returned
    string getMachineName()const;
    friend ostream & operator << (ostream & out, X_Rayer & x);
};

#endif
