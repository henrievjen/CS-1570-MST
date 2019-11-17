// Henri Evjen
// 11/5/19
// HW9
// Purpose: this program tests classes created to represent a hospital room, an
// x-ray machine, and patients

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
using namespace std;

class Patient
{
  private:
    float money;
    bool is_alive;
    int condition;
    string name;

    // Description: updates the is_alive if a patient is dead (condition == 0)
    // Pre-condition: none
    // Post-condition: patient's is_alive variable is updated if condition == 0
    void kill();

  public:
    Patient();

    // Description: reduces patient's money by the amount passed
    // Pre-condition: none
    // Post-condition: patients's money is reduced by the amount passed
    void pay_out(float amount);

    // Description: adds the amount passed to the patient's condition member
    // variable. Calls the kill function to update the is_alive member variable
    // Pre-condition: none
    // Post-condition: the amount passed is added to the patient's condition
    void modify_health(short amount);
    
    // Description: returns patient's current money value
    // Pre-condition: none
    // Post-condition: patient's money value is returned
    float getMoney()const;
    
    // Description: returns whether a patient is alive or not
    // Pre-condition: none
    // Post-condition: patient's is_alive state is returned
    bool getAlive()const;
    
    // Description: returns patient's condition (health)
    // Pre-condition: none
    // Post-condition: patient's condition number is returned
    int getCondition()const;

    // Description: returns patients name
    // Pre-condition: none
    // Post-condition: patient's name is returned
    string getName()const;
    friend ostream & operator << (ostream & out, Patient & pat);
};

#endif
