// Henri Evjen
// 10/16/19
// HW7
// Purpose: the program should use bubble sort and Nick's sort to sort arrays
// and time them to find the minimum, maximum, and average speed of each 

#include <iostream>
#include <cstdlib>
#include "bubble_sort.h"
#include "nicks_sort.h"
#include "hw7.h"
using namespace std;

int main()
{
  // Random number seed
  srand(42);

  // Declarations
  const int PT1_SIZE = 15, PT2_SIZE = 15000, PT1_MIN = 5, PT1_MAX = 100, 
  PT2_MIN = 105, PT2_MAX = 15000, BUBBLE_SORT = 0, NICKS_SORT = 1;
  int bubble_sort_arr_15[PT1_SIZE];
  int nicks_sort_arr_15[PT1_SIZE];
  int bubble_sort_arr_15000[PT2_SIZE];
  int nicks_sort_arr_15000[PT2_SIZE];

  setArr(bubble_sort_arr_15, PT1_SIZE, PT1_MIN, PT1_MAX);
  setArr(nicks_sort_arr_15, PT1_SIZE, PT1_MIN, PT1_MAX);
  setArr(bubble_sort_arr_15000, PT2_SIZE, PT2_MIN, PT2_MAX);
  setArr(nicks_sort_arr_15000, PT2_SIZE, PT2_MIN, PT2_MAX);

  // Part 1
  cout << "--- PART 1 ---" << endl << endl;
  cout << "Array of 15: " << endl;
  printArr(bubble_sort_arr_15, PT1_SIZE);

  cout << endl << "Bubble Sort..." << endl << endl;
  bubbleSort(bubble_sort_arr_15, PT1_SIZE);

  cout << "Array of 15 (after bubble sort): " << endl;
  printArr(bubble_sort_arr_15, PT1_SIZE);

  cout << endl << "Array of 15: " << endl;
  printArr(nicks_sort_arr_15, PT1_SIZE);

  cout << endl << "Nick's Sort..." << endl << endl;
  nicksSort(nicks_sort_arr_15, PT1_SIZE);

  cout << "Array of 15 (after Nick's sort): " << endl;
  printArr(nicks_sort_arr_15, PT1_SIZE);


  // Part 2
  cout << endl << "--- PART 2 ---" << endl << endl;
  cout << "Bubble Sort:" << endl;
  sortResults(bubble_sort_arr_15000, PT2_SIZE, BUBBLE_SORT);
  cout << "Nick's Sort:" << endl;
  sortResults(nicks_sort_arr_15000, PT2_SIZE, NICKS_SORT);  

  return 0;
}
