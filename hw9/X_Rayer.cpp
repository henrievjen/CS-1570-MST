// Henri Evjen
// 11/5/19
// HW9
// Purpose: this program tests classes created to represent a hospital room, an
// x-ray machine, and patients

#include <iostream>
#include <cstdlib>
#include "X_Rayer.h"
#include "Patient.h"
using namespace std;

void X_Rayer::charge_patient(Patient & pat)const
{
  pat.pay_out(cost_per_use);

  return;
}

void X_Rayer::apply(Patient & pat)
{
  // Declaration
  const short RAND_NUM = rand() % 10;
  if(RAND_NUM == 0) {
    pat.modify_health(-(pat.getCondition()/2));
  }
  num_uses++;

  return;
}

float X_Rayer::getCostPerUse()const
{
  return cost_per_use;
}

short X_Rayer::getNumUses()const
{
  return num_uses;
}

ostream & operator << (ostream & out, X_Rayer & x) 
{ 
  out << "The X-Rayer has been used " << x.getNumUses() << " times and each "
  << "cost per use is $" << x.getCostPerUse() << endl; 
  return out; 
} 
