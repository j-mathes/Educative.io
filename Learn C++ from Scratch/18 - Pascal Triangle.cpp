#include <iostream>
using namespace std;

void printPascalTr(int size)
{
  int tableOfNumbers[size][size];
  int i, j;
  for(i=0; i<size; i++)
  {
    for(j=0; j<size; j++)
    {
      if(i==0 && j==0)
      {
        tableOfNumbers[i][j] = 1;
      }
      else if (i==1 && j<2)
      {
        tableOfNumbers[i][j] = 1;
      }
      else if (i>1 && j==0)
      {
        tableOfNumbers[i][j] = tableOfNumbers[i-1][j];
      }
      else if (i>1 && j>0)
      {
        tableOfNumbers[i][j] = tableOfNumbers[i-1][j] + tableOfNumbers[i-1][j-1];
      }
      else
      {
        tableOfNumbers[i][j] = 0;
      }
    }
  }

  for(i=0; i<size; i++)
  {
    for(j=0; j<size; j++)
    {
      if(j<=i)
      {
        cout << tableOfNumbers[i][j] << " ";
      }
    }
    cout << endl;
  }
}
