#include <iostream>
using namespace std;

int main() 
{
    string name;
    string address;
    string phoneNumber;
    
    cout << "Enter name: "<<endl;
    cin >> name;
    
    cout << "Enter address: "<<endl;
    cin >> address;
    
    cout << "Enter phone number: "<<endl;
    cin>> phoneNumber;
    
    cout << "Name is: ";
    cout << name<<endl;
  
    cout << "Address is: ";
    cout << address << endl;
  
    cout << "Phone number is: ";
    cout << phoneNumber << endl;
    return 0;
}
