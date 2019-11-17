// Henri Evjen
// 10/16/19
// HW7
// Purpose: the program should use bubble sort and Nick's sort to sort arrays
// and time them to find the minimum, maximum, and average speed of each

#ifndef SWAP_H
#define SWAP_H

// Description: the first variable is assigned to the value of the second
// variable, and the second variable is assigned to the value of the first
// Pre-condition: none
// Post-condition: the values of the variables are swapped
template <typename T>
void swapElem(T& elem1, T& elem2)
{
  T temp = elem1;
  elem1 = elem2;
  elem2 = temp;

  return;
}

#endif
