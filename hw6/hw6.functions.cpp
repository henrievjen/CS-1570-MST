#include <iostream>
#include <cstdlib>
#include "hw6.h"
using namespace std;

/* Function Definitions */

void greeting()
{
  cout << "Welcome to the quiz-er! Please select your skill level to begin..."
   << endl << endl;

  return;
}

char displayMenu()
{
  // Declaration
  const char MIN_DIFFICULTY = '1', MID_DIFFICULTY = '2', MAX_DIFFICULTY = '3';
  char difficulty = 0;
  bool invalid_difficulty;

  do
  {
    cout << "DIFFICULTY LEVEL" << endl << endl;
    cout << "1.  Easy" << endl;
    cout << "2.  Moderate" << endl;
    cout << "3.  Advanced" << endl << endl;

    cout << "Choice: ";
    cin >> difficulty;
    cout << endl;

    invalid_difficulty = difficulty != MIN_DIFFICULTY &&
    difficulty != MID_DIFFICULTY && difficulty != MAX_DIFFICULTY;

    if(invalid_difficulty)
    {
      cout << "Please enter a valid difficulty level." << endl;
    }    
  } while(invalid_difficulty);

  return difficulty;
}

int rand_num(const short MIN, const short MAX)
{
  return MIN + (rand() % (MAX - MIN + 1));
}

float rand_num(const float MIN, const float MAX)
{
  return MIN+static_cast<float>(rand())/
  (static_cast<float>(RAND_MAX/(MAX-MIN)));
}

char rand_sign()
{
  // Declaration
  const short one_or_zero = rand() % 2;

  if(one_or_zero == 1)
  {
    return '+';
  }
  else
  {
    return '-';
  }
}

void displayMessage(const bool CORRECT)
{
  if(CORRECT)
  {
    cout << "Congrats! You answered correctly." << endl;
  }
  else
  {
    cout << "Sorry. Your answer is incorrect." << endl;
  }
}

void displayFinalResults(const short NUM_CORRECT, const short NUM_WRONG)
{
  cout << endl << "---Results---" << endl << endl;
  cout << "Correct : " << NUM_CORRECT << endl;
  cout << "Wrong: " << NUM_WRONG << endl;
}
