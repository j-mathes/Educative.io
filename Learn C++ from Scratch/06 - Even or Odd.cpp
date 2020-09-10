#include <iostream>
using namespace std;

int test(int number)
{
    int temp; //set temp to 0 if number is even
              //set temp to 1 if number is odd
    
    cout << "Computing whether " << number << " is an even or odd integer"<<endl;
    (number % 2 == 0) ? temp = 0 : temp = 1;
    return temp;
}
