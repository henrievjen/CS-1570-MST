// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Patient.h"
using namespace std;

Patient::Patient()
{
  // Declarations
  const short RAND_MONEY = (rand() % 4000) + 1, 
  RAND_CONDITION = (rand() % 100) + 1, MAX_WEIGHT = 220, MIN_WEIGHT = 120,
  RAND_WEIGHT = MAX_WEIGHT + (rand() % (MAX_WEIGHT - MIN_WEIGHT + 1)), 
  RAND_MENTAL_HEALTH = (rand() % 100) + 1;
  short total_names = 0, rand_name;
  ifstream fin;
  string next;
  string names[1000];

  m_weight_of_patient = RAND_WEIGHT;
  m_money = RAND_MONEY;
  m_condition = RAND_CONDITION;
  m_mental_health = RAND_MENTAL_HEALTH;

  if(m_condition)
  {
    m_is_alive = true;
  }
  else
  {
    m_is_alive = false;
  }

  fin.open("names.dat");
  while(fin >> next)
  {
    names[total_names++] = next;
  }

  rand_name = rand() % total_names;

  m_name = names[rand_name];
}

void Patient::pay_out(const float amount)
{
  // Declarations
  const short MIN_MONEY = 0;

  if(m_money - amount < MIN_MONEY)
  {
    m_money = MIN_MONEY;
  }
  else
  {
    m_money -= amount;
  }
    
  return;
}

void Patient::modify_mental_health(const float amount)
{
  // Declarations
  const short MAX_MENTAL_HEALTH = 100, MIN_MENTAL_HEALTH = 0;

  if(m_mental_health + amount > MAX_MENTAL_HEALTH)
  {
    m_mental_health = MAX_MENTAL_HEALTH;
  }
  else if(m_mental_health + amount < MIN_MENTAL_HEALTH)
  {
    m_mental_health = MIN_MENTAL_HEALTH;
  }
  else
  {
    m_mental_health += amount;
  }
  

  return;
}

void Patient::modify_health(const float amount)
{
  // Declarations
  const short MAX_HEALTH = 100, MIN_HEALTH = 0;

  if(m_condition + amount > MAX_HEALTH)
  {
    m_condition = MAX_HEALTH;
  }
  else if(m_condition + amount < MIN_HEALTH)
  {
    m_condition = MIN_HEALTH;
  }
  else
  {
    m_condition += amount;
  }
  
  kill();
    
  return;
}

void Patient::kill()
{
  // Declarations
  const short MIN_CONDITION = 0;

  if(m_condition == MIN_CONDITION)
  {
    m_is_alive = false;
  }
  
  return;
}

void Patient::modify_weight(const float amount)
{
  // Declarations
  const short MIN_WEIGHT = 0;

  if(m_weight_of_patient + amount < MIN_WEIGHT)
  {
    m_weight_of_patient = MIN_WEIGHT;
  }
  else
  {
    m_weight_of_patient += amount;
  }
  
  return;
}

void Patient::append_name(const string str)
{
  m_name += str;

  return;
}

float Patient::getMoney()const
{
  return m_money;
}

bool Patient::getAlive()const
{
  return m_is_alive;
}

int Patient::getCondition()const
{
  return m_condition;
}

int Patient::getMentalHealth()const
{
  return m_mental_health;
}

int Patient::getWeight()const
{
  return m_weight_of_patient;
}

string Patient::getName()const
{
  return m_name;
}

ostream & operator << (ostream & out, Patient & pat) 
{ 
  out << pat.m_name << " weighs " << pat.m_weight_of_patient << " lbs w/ MH = "
  << pat.m_mental_health << " and PH = " << pat.m_condition << " and has $" <<
  pat.m_money;

  if(!pat.m_is_alive)
  {
    out << " and is DEAD";
  }
  out << endl;
  
  return out; 
}
