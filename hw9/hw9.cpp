// Henri Evjen
// 11/5/19
// HW9
// Purpose: this program tests classes created to represent a hospital room, an
// x-ray machine, and patients

#include <iostream>
#include <cstdlib>
#include "X_Rayer.h"
#include "Patient.h"
#include "Hospital_Room.h"
using namespace std;

int main()
{
  // Seeding random number with time
  srand(time(NULL));    

  // Delcarations
  Hospital_Room h_room;
  Patient pat1, pat2, pat3;
  const short INITIAL_CONDITION = pat1.getCondition();    

  cout << "Initial States: " << endl;
  cout << h_room << pat1 << pat2 << pat3;

  cout << endl << "Admitting..." << endl << endl;

  for(short i = 0; i < 5; i++)
  {
    h_room.admit(pat1);
  }

  cout << "After admitted:" << endl;

  cout << h_room;
  cout << pat1.getName() << " ";
  if(pat1.getAlive())
  {
    cout << "is alive and " << pat1.getName() << " ";
  }
  else
  {
    cout << "is not alive and " << pat1.getName() << " ";
  }

  if(INITIAL_CONDITION > pat1.getCondition())
  {
    cout << "got worse. ";
  }    
  else if(INITIAL_CONDITION < pat1.getCondition())
  {
    cout << "got better. " << endl;
  }
  else
  {
    cout << "had no change in health. " << endl;
  }

  if(pat1.getMoney())
  {
    cout <<pat1.getName()<<" ended up with $"<<pat1.getMoney()<<"."<<endl;
  }
  else
  {
    cout << pat1.getName() << " ended up with no money." << endl;
  }
  cout << pat2 << pat3;

  return 0;
}
