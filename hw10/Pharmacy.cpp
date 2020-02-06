// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include "Pharmacy.h"
#include "Patient.h"
#include "Doctor.h"

Pharmacy::Pharmacy()
{
  // Declarations
  const short MAX_PILLS = 50, MIN_PILLS = 100,
  RANDOM_PILLS = MIN_PILLS + (rand() % (MAX_PILLS - MIN_PILLS + 1));
  m_cost_per_use = 150;
  m_num_uses = 0;
  m_num_pills = RANDOM_PILLS;
}

void Pharmacy::charge_patient(Patient &pat, Doctor & doc)
{
  pat.pay_out(m_cost_per_use);
  doc.pay(static_cast<float>(m_cost_per_use) / 2);

  return;
}

void Pharmacy::modify_num_pills(const short amount)
{
  m_num_pills += amount;

  return;
}

void Pharmacy::apply(Patient &pat)
{
  // Declarations
  const short RAND_CHANCE = rand() % 4, MENTAL_HEALTH = pat.getMentalHealth(),
  PHYSICAL_HEALTH = pat.getCondition(), MAX_MENTAL_HEALTH = 100,
  INC_WEIGHT = 100, MENTAL_DISTRESS = -23, WEIGHT_GAIN = 44;

  m_num_pills--;

  if (RAND_CHANCE == 0)
  {
    pat.modify_health(10);
    pat.modify_mental_health(-10);
  }
  else if (RAND_CHANCE == 1)
  {
    pat.modify_health(20);
    pat.modify_mental_health(-MENTAL_HEALTH);
  }
  else if (RAND_CHANCE == 3)
  {
    pat.modify_health(-PHYSICAL_HEALTH);
  }
  else
  {
    pat.modify_mental_health(MAX_MENTAL_HEALTH - MENTAL_HEALTH);
    pat.modify_weight(INC_WEIGHT);
  }

  if (m_num_pills == 0)
  {
    pat.modify_mental_health(MENTAL_DISTRESS);
    pat.modify_weight(WEIGHT_GAIN);
  }
  m_num_uses++;

  return;
}

float Pharmacy::getCostPerUse() const
{
  return m_cost_per_use;
}

short Pharmacy::getNumUses() const
{
  return m_num_uses;
}

string Pharmacy::getMachineName()const
{
  return "Pharmacy";
}

ostream &operator<<(ostream &out, Pharmacy &pharm)
{
  out << "The Pharmacy has been used " << pharm.m_num_uses << " times "
  << endl;

  return out;
}