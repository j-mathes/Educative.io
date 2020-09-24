// What will happen if we instantiate MyDouble with a non-constant expression?
#include <iostream>

struct MyDouble{
  double myVal;
  constexpr MyDouble(double v): myVal(v){} 
  constexpr double getVal(){ return myVal; }
};

int main() {
  MyDouble d(5.1);
}
