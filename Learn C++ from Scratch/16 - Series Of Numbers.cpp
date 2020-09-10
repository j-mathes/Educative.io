#include <iostream>
using namespace std;

void test(int n) //you dont have to use "int n" anywhere in the code, it's passed for testing purposes
{
  int tableOfNumbers[5][5];
  int i, j;
  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
    {
      if(i==0)
      {
        tableOfNumbers[i][j] = j+1;
      }
      if (i>0 && j==0)
      {
        tableOfNumbers[i][j] = tableOfNumbers[i-1][4]+1;
      }
      else
      {
        tableOfNumbers[i][j] = tableOfNumbers[i][j-1] + 1;
      }
    }
  }

  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
    {
      cout << tableOfNumbers[i][j] << '\t';
    }
    cout << endl;
  }
}
