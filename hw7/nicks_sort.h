// Henri Evjen
// 10/16/19
// HW7
// Purpose: the program should use bubble sort and Nick's sort to sort arrays
// and time them to find the minimum, maximum, and average speed of each

#ifndef NICKS_SORT_H
#define NICKS_SORT_H

#include "swap.h"

// Description: sort the array in ascending order using nicks sorting algorithm
// Pre-condition: array length must be same as SIZE constant
// Post-condition: array is sorted in ascending order
template <typename T>
void nicksSort(T arr[], const T SIZE)
{
  for(int i = 1; i < SIZE; i++)
  {
    for(int j = i; j > 0; j--)
    {
      if(arr[j - 1] > arr[j])
      {
        swapElem(arr[j - 1], arr[j]);
      }
    }    
  }

  return;
}

#endif
