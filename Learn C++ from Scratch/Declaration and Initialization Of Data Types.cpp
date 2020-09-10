#include <iostream>
using namespace std;

int main() 
{
    int intNumber {30};
    float floatNumber {30.78};
    double doubleNumber {45.1234};
    bool boolean {true};
    char charName {'u'};

    cout << "Value of Integer is: ";
    cout << intNumber;
    cout << endl;
    cout << "Value of Float is: ";
    cout << floatNumber;
    cout << endl;
    cout << "Value of Double is: " ;
    cout << doubleNumber;
    cout << endl;
    cout << "Value of Char is: ";
    cout << charName;
    cout << endl;
    cout << "Value of Bool is: ";
    cout << boolalpha << boolean;
    cout << endl;
    return 0;
}
