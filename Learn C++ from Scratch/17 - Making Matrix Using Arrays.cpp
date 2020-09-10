#include <iostream>
using namespace std;

void test(int n)
{
  int tableOfNumbers[5][5];
  int i, j;
  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
    {
      if(i==j)
      {
        tableOfNumbers[i][j] = 0;
      }
      else if (i<j)
      {
        tableOfNumbers[i][j] = 1;
      }
      else
      {
        tableOfNumbers[i][j] = -1;
      }
    }
  }

  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
    {
      cout << tableOfNumbers[i][j] << " ";
    }
    cout << endl;
  }
}
