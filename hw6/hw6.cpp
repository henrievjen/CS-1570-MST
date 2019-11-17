// Henri Evjen
// 10/3/19
// HW6
// Purpose: 

#include <iostream>
#include <cstdlib>
#include "hw6.h"
using namespace std;

int main()
{
  // Declaration
  const short NUM_QUESTIONS = 3, EASY_MIN_RANGE = 1, EASY_MAX_RANGE = 9, 
  MOD_MIN_RANGE = 1, MOD_MAX_RANGE = 99;
  const float ADV_MIN_RANGE = 1.00, ADV_MAX_RANGE = 99.99;
  const char EASY = '1', MODERATE = '2';
  char menu_choice, repeat_response;
  float answer;
  short correct, wrong;

  // Sets floats to have two decimal places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  // Seed random function with time
  srand(time(NULL));

  greeting();

  do
  {
    correct = 0, wrong = 0;

    menu_choice = displayMenu();

    for(short i = 0; i < NUM_QUESTIONS; i++)
    {
      if(menu_choice == EASY)
      {
        answer = the_problem(EASY_MIN_RANGE, EASY_MAX_RANGE);
      }
      else if(menu_choice == MODERATE)
      {
        answer = the_problem(MOD_MIN_RANGE, MOD_MAX_RANGE);
      }
      else
      {
        answer = the_problem(ADV_MIN_RANGE, ADV_MAX_RANGE);
      }

      displayMessage(isCorrect(answer, correct, wrong));
    }

    displayFinalResults(correct, wrong);

    do
    {
      cout << "Would you like to try the quiz again? (y or n)" << endl;
      cin >> repeat_response;
    } while(!(repeat_response == 'y' || repeat_response == 'n'));    

  } while(repeat_response == 'y');

  return 0;
}
