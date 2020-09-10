#include <iostream>
using namespace std;

string test(int num) {
  string ans = ""; //return the correct value in this string
  int i {1};
  while (i <= 10)
  {
    int product = num * i;
    cout << num << " x " << i << " = " << product;
    ans += to_string(product) + " ";
    i++;
  }
  return ans;
}
