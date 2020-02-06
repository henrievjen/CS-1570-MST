// Henri Evjen
// 11/19/19
// HW10
// Purpose: this program simulates Dr. Nick administering medical expertise to
// a group of patients. The program has 10 patients, a doctor, and 6 hospital
// rooms. It admits each patient to each room and outputs the results.

#include <iostream>
#include "Hospital_Room.h"
#include "Doctor.h"
#include "X_Rayer.h"
using namespace std;

template <class T_machine>
void Hospital_Room<T_machine>::admit(Patient &pat, Doctor &doc)
{
  // Declarations
  const short MIN_GIN = 1, MAX_GIN = 3, SUB_GIN = 5;
  short rand_num = MIN_GIN + rand() % MAX_GIN;

  if(rand_num > m_ozs_of_gin)
  {
    doc.consumeGin(m_ozs_of_gin);
  }
  else
  {
    doc.consumeGin(rand_num);
  }

  if(m_ozs_of_gin > 0 && doc.getOzsGinConsumed() >= SUB_GIN)
  {
    for(short i = 0; i < (SUB_GIN - doc.getOzsGinConsumed()); i++)
    {
      m_the_machine.apply(pat);
    }
  }
  else if(m_ozs_of_gin == 0)
  {
    for(short i = 0; i < 2 * (SUB_GIN - doc.getOzsGinConsumed()); i++)
    {
      m_the_machine.apply(pat);
    }
  }
  else if(pat.getAlive())
  {
    m_the_machine.apply(pat);
  }
  

  cout <<pat.getName()<<" enters "<<m_the_machine.getMachineName()<<" ...";

  if(m_the_machine.getMachineName() == "X Rayer")
  {
    if(m_the_machine.getNumUses() != 1)
    {
      cout << " recieves " << m_the_machine.getNumUses() << " x-rays,";
    }
    else
    {
      cout << " recieves " << m_the_machine.getNumUses() << " x-ray,";
    } 
  }
  else if(m_the_machine.getMachineName() == "Placaeboizer")
  {
    if(m_the_machine.getNumUses() != 1)
    {
      cout << " recieves " << m_the_machine.getNumUses() << 
      " placaeboizer treatments,";
    }
    else
    {
      cout << " recieves " << m_the_machine.getNumUses() << 
      " placaeboizer treatment,";
    } 
  }
  else if(m_the_machine.getMachineName() == "Pharmacy")
  {
    if(m_the_machine.getNumUses() != 1)
    {
      cout << " gets " << m_the_machine.getNumUses() << " pills,";
    }
    else
    {
      cout << " gets " << m_the_machine.getNumUses() << " pill,";
    } 
  }
  else if(m_the_machine.getMachineName() == "Organ Donor")
  {
    if(m_the_machine.getNumUses() != 1)
    {
      cout << " loses " << m_the_machine.getNumUses() << " organs,";
    }
    else
    {
      cout << " loses " << m_the_machine.getNumUses() << " organ,";
    } 
  }
  else if(m_the_machine.getMachineName() == "Lobotomizer")
  {
    if(m_the_machine.getNumUses() != 1)
    {
      cout << " recieves " << m_the_machine.getNumUses() << " lobotomies,";
    }
    else
    {
      cout << " recieves " << m_the_machine.getNumUses() << " lobotomy,";
    } 
  }
  else if(m_the_machine.getMachineName() == "Liposuctionizer")
  {
    if(m_the_machine.getNumUses() != 1)
    {
      cout << " recieves " << m_the_machine.getNumUses() <<
    " liposuction treatments,";
    }
    else
    {
      cout << " recieves " << m_the_machine.getNumUses() <<
    " liposuction treatment,";
    } 
  }

  cout <<" now has MH = "<<pat.getMentalHealth()<<"; PH = "<<pat.getCondition()
  << "; has $" << pat.getMoney();
  
  if(pat.getCondition() && pat.getMoney() > m_the_machine.getCostPerUse())
  {
    m_the_machine.charge_patient(pat, doc);
    m_the_machine.apply(pat);
  }
  else if(!pat.getCondition())
  {
    cout << " and is DEAD";
  }
  else
  {
    cout << " and does not have ENOUGH MONEY";
  }
  cout << endl;

  return;
}

template <class T_machine>
T_machine Hospital_Room<T_machine>::getTheMachine() const
{
  return m_the_machine;
}

template <class T_machine>
float Hospital_Room<T_machine>::getOzsOfGin() const
{
  return m_ozs_of_gin;
}
