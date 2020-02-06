// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include "Placaeboizer.h"
#include "Patient.h"
#include "Doctor.h"

void Placaeboizer::charge_patient(Patient &pat, Doctor & doc)
{
  pat.pay_out(m_cost_per_use);
  doc.pay(static_cast<float>(m_cost_per_use) / 2);

  return;
}

void Placaeboizer::apply(Patient &pat)
{
  // Declarations
  const short MENTAL_HEALTH = pat.getMentalHealth(), MAX_MENTAL_HEALTH = 100,
  WEIGHT_GAIN = 50;

  pat.modify_mental_health(static_cast<float>(MAX_MENTAL_HEALTH-MENTAL_HEALTH)
  / 2);
  pat.modify_weight(WEIGHT_GAIN);
  m_num_uses++;

  return;
}

float Placaeboizer::getCostPerUse() const
{
  return m_cost_per_use;
}

short Placaeboizer::getNumUses() const
{
  return m_num_uses;
}

string Placaeboizer::getMachineName()const
{
  return "Placaeboizer";
}

ostream &operator<<(ostream &out, Placaeboizer &plac)
{
  out << "The Placaeboizer has been used " << plac.m_num_uses << " times"
  << endl;
  return out;
}