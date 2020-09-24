// What will happen if we instantiate MyDouble with a non-constant expression?
#include <iostream>

struct MyDouble{
  double myVal;
  constexpr MyDouble(double v): myVal(v){} 
  constexpr double getVal() const { return myVal; }
};

int main() {
  MyDouble d{5.1};
  static_assert(d.getVal() == 5.1, "bad static assert");
}

/* We get:
main.cpp: In function ‘int main()’:
main.cpp:11:3: error: non-constant condition for static assertion
   static_assert(d.getVal() == 5.1, "bad static assert");
   ^
main.cpp:11:25:   in constexpr expansion of ‘d.MyDouble::getVal()’
main.cpp:11:3: error: the value of ‘d’ is not usable in a constant expression
main.cpp:10:12: note: ‘d’ was not declared ‘constexpr’
   MyDouble d{5.1};
*/
