// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
using namespace std;

class Patient
{
  private:
    float m_money;
    bool m_is_alive;
    int m_condition;
    int m_mental_health;
    float m_weight_of_patient;
    string m_name;

    // Description: updates the is_alive if a patient is dead (condition == 0)
    // Pre-condition: none
    // Post-condition: patient's is_alive variable is updated if condition == 0
    void kill();

  public:
    Patient();

    // Description: reduces patient's money by the amount passed
    // Pre-condition: none
    // Post-condition: patients's money is reduced by the amount passed
    void pay_out(const float amount);

    // Description: adds the amount passed to the patient's mental health
    // Pre-condition: none
    // Post-condition: amount passed is added to the patient's mental health
    void modify_mental_health(const float amount);

    // Description: adds the amount passed to the patient's condition member
    // variable. Calls the kill function to update the is_alive member variable
    // Pre-condition: none
    // Post-condition: the amount passed is added to the patient's condition
    void modify_health(const float amount);

    // Description: adds the amount passed to the patient's weight member
    // Pre-condition: none
    // Post-condition: the amount passed is added to the patient's weight
    void modify_weight(const float amount);

    // Description: appends the string passed to patient name
    // Pre-condition: none
    // Post-condition: the passed string is appended to patient's name
    void append_name(const string str);
    
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

    // Description: returns patient's mental health
    // Pre-condition: none
    // Post-condition: patient's mental health is returned
    int getMentalHealth()const;

    // Description: returns patient's weight
    // Pre-condition: none
    // Post-condition: patient's weight is returned
    int getWeight()const;

    // Description: returns patient's name
    // Pre-condition: none
    // Post-condition: patient's name is returned
    string getName()const;
    friend ostream & operator << (ostream & out, Patient & pat);
};

#endif
