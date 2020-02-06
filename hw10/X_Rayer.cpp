// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include <iostream>
#include <cstdlib>
#include "X_Rayer.h"
#include "Patient.h"
#include "Doctor.h"
using namespace std;

void X_Rayer::charge_patient(Patient &pat, Doctor &doc) const
{
  pat.pay_out(m_cost_per_use);
  doc.pay(static_cast<float>(m_cost_per_use) / 2);

  return;
}

void X_Rayer::apply(Patient &pat)
{
  // Declaration
  const short DEC_HEALTH_CHANCE = 10, RAND_NUM = rand() % DEC_HEALTH_CHANCE;
  if (RAND_NUM == 0)
  {
    pat.modify_health(-(pat.getCondition() / 2));
  }
  m_num_uses++;

  return;
}

float X_Rayer::getCostPerUse() const
{
  return m_cost_per_use;
}

short X_Rayer::getNumUses() const
{
  return m_num_uses;
}

string X_Rayer::getMachineName()const
{
  return "X Rayer";
}

ostream &operator<<(ostream &out, X_Rayer &x)
{
  out << "The X-Rayer has been used " << x.m_num_uses << " times "
  << endl;
  return out;
}
