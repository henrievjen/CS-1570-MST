// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include "Organ_Donor.h"

void Organ_Donor::charge_patient(Patient &pat, Doctor & doc)
{
  pat.pay_out(m_cost_per_use);
  doc.pay(static_cast<float>(m_cost_per_use) / 2);

  return;
}

void Organ_Donor::apply(Patient &pat)
{
  // Declarations
  const short DEC_PHYSICAL_HEALTH = -(rand() % 21), KILL_CHANCE = rand() % 50,
  PHYSICAL_HEALTH = pat.getCondition(), INC_MENTAL_HEALTH = 10, 
  DEC_WEIGHT = -10;

  pat.modify_mental_health(INC_MENTAL_HEALTH);
  pat.modify_health(DEC_PHYSICAL_HEALTH);

  if(KILL_CHANCE == 0)
  {
    pat.modify_health(-PHYSICAL_HEALTH);
  }
  pat.modify_weight(DEC_WEIGHT);
  m_num_uses++;

  return;
}

float Organ_Donor::getCostPerUse()const
{
  return m_cost_per_use;
}

short Organ_Donor::getNumUses()const
{
  return m_num_uses;
}

string Organ_Donor::getMachineName()const
{
  return "Organ Donor";
}

ostream &operator<<(ostream &out, Organ_Donor &org)
{
  out << "Organ Donor has been used " << org.m_num_uses << " times" << endl;
  return out;
}