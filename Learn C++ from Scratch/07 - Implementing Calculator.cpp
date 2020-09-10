#include <iostream>
using namespace std;

float test(float num1, float num2, char Operator)
{
    //temp will contain the final answer after the required operation is performed
    float temp; //return temp for each switch operation

    cout<<"Number 1 is: " << num1 << endl;
    cout<<"Number 2 is: " << num2 << endl;
    cout << "Operator is: "<<Operator<<endl;

    switch (Operator)
    {
        case '+': 
            temp = num1 + num2;
            break;
        case '-': 
            temp = num1 - num2;
            break;
        case '*': 
            temp = num1 * num2;
            break;
        case '/': 
            if (num2 == 0)
            {    
                cout << "Divide by zero error" << endl;
                temp = 0;
            }
            else
                temp = num1 / num2;
            break;
    }
    return temp;
}
