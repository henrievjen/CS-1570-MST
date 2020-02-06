// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

#include <iostream>
#include "X_Rayer.h"
#include "Doctor.h"
using namespace std;

template <class T_machine>
class Hospital_Room
{
private:
  T_machine m_the_machine;
  float m_ozs_of_gin;

public:
  Hospital_Room() : m_ozs_of_gin(10.0) {}

  // Description: applies the functionality of the machine to the patient. 
  // Applies the machine a number of times based on if he has consumed gin.
  // Pre-condition: none
  // Post-condition: the functionality of the machine is applied to the patient
  void admit(Patient &pat, Doctor &doc);

  // Description: returns hospital room's machine object
  // Pre-condition: none
  // Post-condition: hospital room's machine object is returned
  T_machine getTheMachine() const;

  // Description: returns amount of ozs of gin in hospital room
  // Pre-condition: none
  // Post-condition: ozs of gin in hospital room is returned
  float getOzsOfGin() const;

  friend ostream &operator<<(ostream &out, Hospital_Room<T_machine> &hr)
  {
    out << hr.m_the_machine;

    return out;
  }
};

#include "Hospital_Room.hpp"
#endif
