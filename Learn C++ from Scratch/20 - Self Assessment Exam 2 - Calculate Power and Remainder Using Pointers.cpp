#include <iostream>
using namespace std;
void passReference(int * a, int * b) 
{
    cout << "inputs: " << *a << " " << *b << endl;
    int p=1;
    for(int i=0; i<*b; i++)
    {
        p=(p * *a);
    }
    *a = p;

    *b = *a % *b;
} 
