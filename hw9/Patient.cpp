// Henri Evjen
// 11/5/19
// HW9
// Purpose: this program tests classes created to represent a hospital room, an
// x-ray machine, and patients

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Patient.h"
using namespace std;

Patient::Patient()
{
  // Declarations
  const short RAND_MONEY = (rand() % 4000) + 1, 
  RAND_CONDITION = (rand() % 100) + 1;
  short total_names = 0, rand_name;
  ifstream fin;
  string next;
  string names[1000];

  money = RAND_MONEY;
  condition = RAND_CONDITION;

  if(condition)
  {
    is_alive = true;
  }
  else
  {
    is_alive = false;
  }

  fin.open("names.dat");
  while(fin >> next)
  {
    names[total_names++] = next;
  }

  rand_name = rand() % total_names;

  name = names[rand_name];
}

void Patient::pay_out(const float amount)
{
    money -= amount;
    
    return;
}

void Patient::modify_health(const short amount)
{
    condition += amount;
    kill();
    
    return;
}

void Patient::kill()
{
    if(condition == 0) {
        is_alive = false;
    }
    
    return;
}

float Patient::getMoney()const
{
    return money;
}

bool Patient::getAlive()const
{
    return is_alive;
}

int Patient::getCondition()const
{
    return condition;
}

string Patient::getName()const
{
    return name;
}

ostream & operator << (ostream & out, Patient & pat) 
{ 
    if(pat.getAlive()) {
        out << pat.getName() << " is alive with a health of " 
        << pat.getCondition() << " and $" << pat.getMoney() << "." << endl;
    }
    else {
        out << pat.getName() << " is not alive. " << pat.getName()
        << " had $" << pat.getMoney() << "." << endl;
    }
    return out; 
}
