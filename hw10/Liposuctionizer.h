// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef LIPOSUCTIONIZER_H
#define LIPOSUCTIONIZER_H

#include "Patient.h"
#include "Doctor.h"

class Liposuctionizer
{
  private:
    float m_cost_per_use;
    short m_num_uses;

  public:
    Liposuctionizer(): m_cost_per_use(750), m_num_uses(0) {};

    // Description: charges the patient the cost of the liposuctionizer and
    // gives half the charge to the doctor
    // Pre-condition: none
    // Post-condition: patient's money is decreased by cost of liposuctionizer
    // and doctor's money is increased by half the cost
    void charge_patient(Patient & pat, Doctor & doc)const;

    // Description: increases patient's mental health by 10 and decreases
    // physical health by random amount in range of 1 to 20. Has 2% chance of
    // killing patient
    // Pre-condition: none
    // Post-condition: patient's mental and physical health are modified. 
    // Small chance that the patient dies
    void apply(Patient & pat);

    // Description: returns liposuctionizer's cost per use
    // Pre-condition: none
    // Post-condition: liposuctionizer's cost per use is returned
    float getCostPerUse()const;

    // Description: returns number of times the liposuctionizer has been used
    // Pre-condition: none
    // Post-condition: number of times liposuctionizer is used is returned
    short getNumUses()const;

    // Description: returns the name of the machine
    // Pre-condition: none
    // Post-condition: name of the machine is returned
    string getMachineName()const;
    friend ostream & operator << (ostream & out, Liposuctionizer & lipo);
};

#endif
