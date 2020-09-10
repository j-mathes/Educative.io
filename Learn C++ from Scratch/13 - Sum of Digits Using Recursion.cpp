#include <iostream>
using namespace std;

int DigitSum(int n1)
{
    if (n1 == 0)
        return 0;
    else
        return (n1 % 10) + DigitSum(n1 / 10);
}
