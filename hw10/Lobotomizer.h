// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef LOBOTOMIZER_H
#define LOBOTOMIZER_H

#include <iostream>
#include "Patient.h"
#include "Doctor.h"
using namespace std;

class Lobotomizer
{
  private:
    float m_cost_per_use;
    short m_num_uses;

  public:
    Lobotomizer(): m_cost_per_use(200), m_num_uses(0) {}

    // Description: charges the patient the cost of the lobotomizer and
    // gives half the charge to the doctor
    // Pre-condition: none
    // Post-condition: patient's money is decreased by cost of lobotomizer
    // and doctor's money is increased by half the cost
    void charge_patient(Patient & pat, Doctor & doc);

    // Description: increases patient's mental health by 10 and physical health
    // by 3. Has a 3% chance of turning the patient into a vegetable and a 10%
    // chance that the patient can no longer remember their name
    // Pre-condition: none
    // Post-condition: patient's mental and physical health are increased. 
    // Small chance that the patient becomes vegetable or forgets name
    void apply(Patient & pat);

    // Description: returns lobotomizer's cost per use
    // Pre-condition: none
    // Post-condition: lobotomizer's cost per use is returned
    float getCostPerUse()const;

    // Description: returns the number of times the lobotomizer has been used
    // Pre-condition: none
    // Post-condition: number of times lobotomizer has been used is returned
    short getNumUses()const;

    // Description: returns the name of the machine
    // Pre-condition: none
    // Post-condition: name of the machine is returned
    string getMachineName()const;
    friend ostream & operator << (ostream & out, Lobotomizer & lob);
};

#endif
