#ifndef HW6_H
#define HW6_H

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/* Function Declarations */

// Description: outputs greeting message to screen 
// Pre-condition: none
// Post-condition: greeting is output to screen
void greeting();

// Description: outputs menu to screen and prompts user for valid input 
// Pre-condition: none
// Post-condition: menu is output to screen and user is prompted to enter input
char displayMenu();

// Description: returns a random int in the range MIN to MAX inclusive
// Pre-condition: none
// Post-condition: random int in range MIN to MAX inclusive is returned
int rand_num(const short MIN, const short MAX);

// Description: returns a random float in the range MIN to MAX inclusive
// Pre-condition: none
// Post-condition: random float in range MIN to MAX inclusive is returned
float rand_num(const float MIN, const float MAX);

// Description: returns either '+' or '-', with an equal chance of each
// Pre-condition: none
// Post-condition: either a '+' char or a '-' char is returned
char rand_sign();

// Description: outputs a message based on if the user answered correctly
// Pre-condition: isCorrect() must have been called
// Post-condition: message is output based on the value of 'correct'
void displayMessage(const bool correct);

// Description: outputs the total correct and incorrect amount of responses
// Pre-condition: none
// Post-condition: total correct and incorrect responses are output to screen
void displayFinalResults(const short NUM_CORRECT, const short NUM_WRONG);

// Description: generates and outputs a math problem and returns the answer
// Pre-condition: none
// Post-condition: math problem is output to screen and answer is returned
template <typename T>
T the_problem(const T MIN_VAL, const T MAX_VAL)
{
  // Declarations
  T lhs = rand_num(MIN_VAL, MAX_VAL);
  T rhs = rand_num(MIN_VAL, MAX_VAL);
  char sign = rand_sign();

  cout << "Question: " << lhs << " " << sign << " " << rhs << endl;

  if(sign == '+')
  {
    return lhs + rhs;
  }
  else
  {
    return lhs - rhs;
  }
}

// Description: prompts the user for response and returns true if correct
// false otherwise
// Pre-condition: the_problem() must have been called
// Post-condition: true of false is returned based on if the answer is correct
template <typename T>
bool isCorrect(const T ANSWER, short& correct, short& wrong)
{
  // Declarations
  const short MAX_TRIES = 2;
  const float EPSILON = 0.005f;
  short tries = 0;
  T response;

  do
  {
    cout << "Answer: ";
    cin >> response;
    tries++;

    if((fabs(ANSWER - response) > EPSILON) && tries == 1)
    {
      cout << "Try again!" << endl;
    }
  } while((fabs(response - ANSWER) > EPSILON) && tries < MAX_TRIES);

  if(fabs(response - ANSWER) < EPSILON)
  {
    correct++;
  }
  else
  {
    wrong++;
  }

  return (fabs(response - ANSWER) < EPSILON);
}

#endif
