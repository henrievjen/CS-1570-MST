// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include <iostream>
#include "Doctor.h"
using namespace std;

void Doctor::consumeGin(const float amount)
{
  // Declarations
  const short MAX_GIN_LIMIT = 25;

  m_ozs_of_gin_consumed += amount;

  if(m_ozs_of_gin_consumed >= MAX_GIN_LIMIT)
  {
    puke();
  }

  return;
}

void Doctor::puke()
{
  m_vomitted += m_ozs_of_gin_consumed;
  m_ozs_of_gin_consumed = 0;
  cout << "****** THE GOOD DR. NICK HAS VOMITTED! ******" << endl;

  return;
}

void Doctor::pay(const float amount)
{
  m_money += amount;

  return;
}

short Doctor::getOzsGinConsumed()const
{
  return m_ozs_of_gin_consumed;
}

string Doctor::getName()const
{
  return m_name;
}

ostream & operator << (ostream & out, Doctor & doc) 
{ 
  out << "Doctor " << doc.m_name << " earned $" << doc.m_money << " today."
  << " He drank " << (doc.m_ozs_of_gin_consumed+doc.m_vomitted) <<"oz. of gin";

  if(doc.m_vomitted)
  {
    out << " and puked " << doc.m_vomitted << "oz";
  }
  out << "." << endl;
    
  return out; 
}