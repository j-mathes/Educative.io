#include <iostream>
using namespace std;

template<class T>
int index_of_smallest(T a[], int start_index, int size)
{
  int solutionIndex = start_index;
  for(int i = start_index + 1; i < size; i++)
    if (a[i] < a[solutionIndex])
      solutionIndex = i;
  return solutionIndex;
}
