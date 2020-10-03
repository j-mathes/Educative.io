#include <iostream>
using namespace std;

class Base{
public:
 Base() = default;
  Base(int i){cout << "Base int: " << i << endl;};
};

// Make a class which derived Base class publiclly
class DerivedPub: public Base
{
public:
  using Base::Base;
  DerivedPub(double d){cout << "DerivedPub double: " << d << endl;};
};

// Make a class which derived Base class protectedly
class DerivedPro: protected Base
{
public:
  using Base::Base;
  DerivedPro(string s){cout << "DerivedPro string: " << s << endl;};
};

// Make a class which derived Base class privately
class DerivedPrv: private Base
{
public:
  using Base::Base;
  DerivedPrv(long l){cout << "DerivedPrv long:" << l << endl;};
};

int main()
{
  // Call the objects of the above classes here
  Base b(4);
  DerivedPub pub(3.2);
  DerivedPro pro("happy");
  DerivedPrv prv(12345657891234);
}

// Provided solution
class Base{
public:
  Base(int){};
};

class DerivePublic: public Base{
 using Base::Base;
};

class DeriveProtected: protected Base{
  using Base::Base;
};

class DerivePrivate: private Base{
  using Base::Base;
};

int main(){

  Base(1);
  DerivePublic(1);
  DeriveProtected(1);
  DerivePrivate(1);

}
