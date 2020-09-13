#include <iostream>
using namespace std;

template <class T>
void swap_values(T& v1, T& v2)
{
  T temp = v1;
  v1 = v2;
  v2 = temp;
}

//Code to test your code. You don't have to touch this part 
string test(int v1, int v2, double v3, double v4){
  string str="";
  swap_values(v1,v2);
  swap_values(v3,v4);
  str = to_string(v1) + " " + to_string(v2) + " " + to_string(v3) + " " + to_string(v4);
  return str;
}
