// Henri Evjen
// 10/16/19
// HW7
// Purpose: the program should use bubble sort and Nick's sort to sort arrays
// and time them to find the minimum, maximum, and average speed of each

#include "swap.h"

// Description: sorts a numerical array in ascending order
// Pre-condition: none
// Post-condition: array is sorted in ascending order
template <typename T>
void bubbleSort(T arr[], const T SIZE)
{
  // Declarations
  bool swapped;

  do
  {
    swapped = false;

    for(int i = 1; i < SIZE; i++)
    {
      if(arr[i - 1] > arr[i])
      {
        swapElem(arr[i - 1], arr[i]);
        swapped = true;
      }
    }
  } while(swapped);

  return;
}
