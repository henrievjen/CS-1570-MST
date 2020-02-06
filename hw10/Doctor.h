// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
using namespace std;

class Doctor
{
  private:
    string m_name;
    short m_ozs_of_gin_consumed;
    float m_money;
    short m_vomitted;

  public:
    Doctor(string name): m_name(name), m_ozs_of_gin_consumed(0), m_money(0) {}

    // Description: increases ozs of gin consumed by amount, pukes if gin
    // gin exceeds 25 ozs
    // Pre-condition: none
    // Post-condition: ozs of gin consumed is increased by amount
    void consumeGin(const float amount);

    // Description: decreases doctor's gin content to nothing (0)
    // Pre-condition: only called if ozs of gin consumed is 25 or greater
    // Post-condition: doctors ozs of gin consumed is set to nothing (0)
    void puke();

    // Description: increases doctor's money by amount passed
    // Pre-condition: none
    // Post-condition: money member variable is increased by amount passed
    void pay(const float amount);

    // Description: returns how many ozs of gin the doctor has consumed
    // Pre-condition: none
    // Post-condition: ozs of gin consumed by doctor is returned
    short getOzsGinConsumed()const;

    // Description: returns the name of the doctor
    // Pre-condition: none
    // Post-condition: the name of the doctor is returned
    string getName()const;
    friend ostream & operator << (ostream & out, Doctor & doc);
};

#endif
