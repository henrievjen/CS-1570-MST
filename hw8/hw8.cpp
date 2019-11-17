// Henri Evjen
// 10/28/19
// HW8
// Purpose: the program will take in a complaint from the user, then it will
// diagnose the user, give a prescription with dosage, and recommend surgery 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "hw8.h"
using namespace std;

int main()
{
  // Declarations
  char complaint[2000];
  char temp, repeat;
  short count = 0, words;
  bool repeatVisit;

  // Random Number Seed
  srand(time(NULL));

  do
  {
    // Reset Variables
    for(int i = 0; static_cast<unsigned int>(i) < strlen(complaint); i++)
    {
      complaint[i] = '\n';
    }    
    count = 0;

    cout << endl <<"------------ Dr. Nick's Health-o-Mattock ------------"
    << endl << endl;
    cout<< "What's wrong (must be problem with head, torso, hand, nose, or "
    << " leg): "; 

    // Input complaint
    do
    {
      cin.get(temp);
      complaint[count] = temp;
      count++;
    } while(temp != '\n' && count < 2000);

    words = printPrognosis(complaint);
    printPrescription(words);
    printSurgery();

    do
    {
      cout << "Nextttt!!?? (y/n): ";
      cin >> repeat;
      cin.ignore();

      if(repeat == 'y')
      {
        repeatVisit = true;
      }
      else if(repeat == 'n')
      {
        repeatVisit = false;
      }
    } while(repeat != 'y' && repeat != 'n');
  } while(repeatVisit);

  return 0;
}
