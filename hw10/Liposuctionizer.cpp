// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include "Liposuctionizer.h"
#include "Patient.h"
#include "Doctor.h"

void Liposuctionizer::charge_patient(Patient &pat, Doctor & doc)const
{
  pat.pay_out(m_cost_per_use);
  doc.pay(static_cast<float>(m_cost_per_use) / 2);

  return;
}

void Liposuctionizer::apply(Patient &pat)
{
  // Declarations
  const short WEIGHT = pat.getWeight(), HEALTH = pat.getCondition();

  pat.modify_weight(-(WEIGHT * .1));
  pat.modify_mental_health(20);

  if (m_num_uses >= 61)
  {
    pat.modify_health(-HEALTH);
  }
  m_num_uses++;

  return;
}

float Liposuctionizer::getCostPerUse() const
{
  return m_cost_per_use;
}

short Liposuctionizer::getNumUses() const
{
  return m_num_uses;
}

string Liposuctionizer::getMachineName()const
{
  return "Liposuctionizer";
}

ostream &operator<<(ostream &out, Liposuctionizer &lipo)
{
  out << "The Liposuctionizer has been used " << lipo.m_num_uses << " times "
  << endl;
  return out;
}