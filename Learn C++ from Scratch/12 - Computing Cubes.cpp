#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void computeCubes (int& num1, int& num2, int& num3)
{
  num1 = pow(num1, 3);
  num2 = pow(num2, 3);
  num3 = pow(num3, 3);
}

string test(int num1, int num2, int num3)
{  
  string ans="";
  
  computeCubes(num1, num2, num3);
  
  cout<< "Value of num1 is: "<< num1 <<endl;
  cout <<"Value of num2 is: " << num2 <<endl;
  cout<<"Value of num3 is: "<< num3<<endl;
  
  //the line of code below is for testing purposes. You don't need to change this
  ans = to_string(num1) + " " +to_string(num2) + " " + to_string(num3); //converting all three values to strings
 
  return ans;
}
