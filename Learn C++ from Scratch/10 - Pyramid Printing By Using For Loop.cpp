#include <iostream>
using namespace std;

void test(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "a ";
        }
        cout << endl;
    }
}
