// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef PHARMACY_H
#define PHARMACY_H

#include "Patient.h"
#include "Doctor.h"

class Pharmacy
{
  private:
    float m_cost_per_use;
    short m_num_uses;
    short m_num_pills;

  public:
    Pharmacy();

    // Description: charges the patient the cost of the pharmacy visit and
    // gives half the charge to the doctor
    // Pre-condition: none
    // Post-condition: patient's money is decreased by cost of pharmacy visit
    // and doctor's money is increased by half the cost
    void charge_patient(Patient & pat, Doctor & doc);

    // Description: adds the amount passed to the number of pills
    // Pre-condition: none
    // Post-condition: the amount passed is added to the pharmacy's num pills
    void modify_num_pills(const short amount);

    // Description: gives pill to patient and either increases condition by 10
    // and decreases mental health by 10, increases condition by 20 and sets 
    // mental health to 0, sets phyisical health to 50, or sets mental health
    // to 100 and increases weight by 100
    // Pre-condition: none
    // Post-condition: patient is administered pill with random side effects
    void apply(Patient & pat);

    // Description: returns pharmacy's cost per use
    // Pre-condition: none
    // Post-condition: pharmacy's cost per use is returned
    float getCostPerUse()const;

    // Description: returns the number of times the pharmacy has been visited
    // Pre-condition: none
    // Post-condition: number of times pharmacy has been visited is returned
    short getNumUses()const;

    // Description: returns the name of the machine
    // Pre-condition: none
    // Post-condition: name of the machine is returned
    string getMachineName()const;
    friend ostream & operator << (ostream & out, Pharmacy & pharm);
};

#endif
