#include <iostream>
using namespace std;

int checkSum(int num1, int num2) 
{
    int check = -1; //set check to 0 if sum is less than 100
                   //set check to 1 if sum is greater than 100
                   //set check to 2 if sum is equal to 100
    cout << "Comparing the value to 100"<<endl;
    
    int sum  = num1 + num2;

    if (sum < 100)
    {
        check = 0;
        cout << sum << " is less than 100" << endl;
    }
    else if (sum > 100)
    {
        check = 1;
        cout << sum << " is greater than 100" << endl;
    }
    else
    {
        cout << sum << " is equal to 100" << endl;
        check = 2;
    }
    
    return check;
}
