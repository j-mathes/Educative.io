// Use the structure, MyDouble, in our program. How can we check that instances of MyDouble will be created at compile-time?
// Is this right?
#include <iostream>

struct MyDouble{
  double myVal;
  constexpr MyDouble(double v): myVal(v){} 
  constexpr double getVal(){ return myVal; }
};

int main() {
  constexpr MyDouble d(5.1);
}
