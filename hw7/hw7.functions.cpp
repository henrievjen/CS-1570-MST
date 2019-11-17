// Henri Evjen
// 10/16/19
// HW7
// Purpose: the program should use bubble sort and Nick's sort to sort arrays
// and time them to find the minimum, maximum, and average speed of each

#include <iostream>
#include <cstdlib>
#include "hw7.h"
#include "bubble_sort.h"
#include "nicks_sort.h"
using namespace std;

void setArr(int arr[], const int SIZE, const int MIN, const int MAX)
{
  for(int i = 0; i < SIZE; i++)
  {
    arr[i] = MIN + (rand() % (MAX - MIN + 1));
  }

  return;
}


void printArr(const int ARR[], const int SIZE)
{
  for(int i = 0; i < SIZE; i++)
  {
    cout << ARR[i] << " ";
  }
  cout << endl;

  return;
}

void sortResults(int arr[], const int SIZE, const int SORT_TYPE)
{
  // Declarations
  const int SORTS = 10, ARR_MIN = 105, ARR_MAX = 15000;
  bool firstTime = true;
  float start, finish, run_time, max = 0, min = 0, sum = 0, average;
  float sortingTimes[SORTS];

  for(int i = 0; i < SORTS; i++)
  {
    start = clock();
    if(SORT_TYPE == 0)
    {
      bubbleSort(arr, SIZE);
    }
    else
    {
      nicksSort(arr, SIZE);
    }
    finish = clock();
    run_time = (static_cast<float>(finish) - start)/CLOCKS_PER_SEC;
   
    if(firstTime)
    {
      max = run_time;
      min = run_time;
      firstTime = false;
    }
    else
    {
      if(run_time > max)
      {
        max = run_time;
      }
      if(run_time < min)
      {
        min = run_time;
      }
    }
    sortingTimes[i] = run_time;

    setArr(arr, SIZE, ARR_MIN, ARR_MAX);    
  }

  for(int i = 0; i < SORTS; i++)
  {
    sum += sortingTimes[i];
  }
  average = sum / SORTS;

  cout << "Minimum Sorting Time: " << min << " seconds" << endl;
  cout << "Maximum Sorting Time: " << max << " seconds" << endl;
  cout << "Average Sorting Time: " << average << " seconds" << endl << endl;

  return;
}
