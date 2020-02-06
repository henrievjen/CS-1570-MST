// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef PLACAEBOIZER_H
#define PLACAEBOIZER_H

#include "Patient.h"
#include "Doctor.h"

class Placaeboizer
{
  private:
    float m_cost_per_use;
    short m_num_uses;

  public:
    Placaeboizer(): m_cost_per_use(500.00), m_num_uses(0) {}

    // Description: charges the patient the cost of the placaeboizer and
    // gives half the charge to the doctor
    // Pre-condition: none
    // Post-condition: patient's money is decreased by cost of placaeboizer
    // and doctor's money is increased by half the cost
    void charge_patient(Patient & pat, Doctor & doc);

    // Description: patient's mental health increases by half the difference
    // between thier current mental health and the maximum mental health
    // Pre-condition: none
    // Post-condition: patients mental health is increased
    void apply(Patient & pat);

    // Description: returns placaeboizer's cost per use
    // Pre-condition: none
    // Post-condition: placaeboizer's cost per use is returned
    float getCostPerUse()const;

    // Description: returns the number of times the placaeboizer has been used
    // Pre-condition: none
    // Post-condition: number of times placaeboizer has been used is returned
    short getNumUses()const;

    // Description: returns the name of the machine
    // Pre-condition: none
    // Post-condition: name of the machine is returned
    string getMachineName()const;
    friend ostream & operator << (ostream & out, Placaeboizer & plac);
};

#endif
