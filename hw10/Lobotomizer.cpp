// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include <iostream>
#include <fstream>
#include "Lobotomizer.h"
#include "Patient.h"
#include "Doctor.h"
using namespace std;

void Lobotomizer::charge_patient(Patient &pat, Doctor & doc)
{
  pat.pay_out(m_cost_per_use);
  doc.pay(static_cast<float>(m_cost_per_use) / 2);

  return;
}

void Lobotomizer::apply(Patient &pat)
{
  // Declarations
  const short MENTAL_HEALTH = pat.getMentalHealth(), MAX_PERCENT = 100,
  MAX_NAMES = 100, MENTAL_HEALTH_INC = 10, HEALTH_INC = 3,
  VEGETABLE_CHANCE = 3, FORGET_NAME_CHANCE = 10;
  ifstream fin;
  string next;
  short vegetable_chance = rand() % MAX_PERCENT, 
  forget_name_chance = rand() % MAX_PERCENT,
  total_names = 0, rand_name;
  string names[MAX_NAMES];

  pat.modify_mental_health(MENTAL_HEALTH_INC);
  pat.modify_health(HEALTH_INC);

  if (vegetable_chance < VEGETABLE_CHANCE)
  {
    pat.modify_mental_health(-MENTAL_HEALTH);
  }
  if (forget_name_chance < FORGET_NAME_CHANCE)
  {
    fin.open("names.dat");
    while (fin >> next)
    {
      names[total_names++] = next;
    }

    rand_name = rand() % total_names;

    pat.append_name(names[rand_name]);
  }
  m_num_uses++;

  return;
}

float Lobotomizer::getCostPerUse() const
{
  return m_cost_per_use;
}

short Lobotomizer::getNumUses() const
{
  return m_num_uses;
}

string Lobotomizer::getMachineName()const
{
  return "Lobotomizer";
}

ostream &operator<<(ostream &out, Lobotomizer &lob)
{
  out << "The lobotomizer has been used " << lob.m_num_uses << " times "
  << endl;
  return out;
}