// Use the structure, MyDouble, in our program. How can we check that instances of MyDouble will be created at compile-time?
#include <iostream>

struct MyDouble{
  double myVal;
  constexpr MyDouble(double v): myVal(v){} 
  // This is wrong: constexpr double getVal(){ return myVal; }
  constexpr double getVal() const { return myVal; }
};

int main() {
  constexpr MyDouble d{5.1};
  static_assert(d.getVal() == 5.1, "bad static assert");
}
