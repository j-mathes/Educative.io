#include <iostream>
#include <ostream>

namespace Distance{
  class MyDistance{
    public:
      MyDistance(double i):m(i){}

      friend MyDistance operator +(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.m + b.m);
      }
      friend MyDistance operator -(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.m - b.m);
      }
      friend MyDistance operator *(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.m * b.m);
      }

      friend std::ostream& operator<< (std::ostream &out, const MyDistance& myDist){
        out << myDist.m << " m";
         return out;
      }
    private:
      double m;

  };

  namespace Unit{
    MyDistance operator "" _km(long double d){
      return MyDistance(1000*d);
    }
    MyDistance operator "" _m(long double m){
      return MyDistance(m);
    }
    MyDistance operator "" _dm(long double d){
      return MyDistance(d/10);
    }
    MyDistance operator "" _cm(long double c){
      return MyDistance(c/100);
    }
    MyDistance operator "" _ft(long double m){
      return MyDistance(m*0.3048);
    }
    MyDistance operator "" _mi(long double m){
      return MyDistance(m*1609.344);
    }
  }
}

using namespace Distance::Unit;

int main(){

  std:: cout << std::endl;

  std::cout << "1.0_km: " << 1.0_km << std::endl;
  std::cout << "1.0_m: " << 1.0_m << std::endl;
  std::cout << "1.0_dm: " << 1.0_dm << std::endl;
  std::cout << "1.0_cm: " << 1.0_cm << std::endl;
  std::cout << "1.0_mi: " << 1.0_mi << std::endl;
  std::cout << "1.0_ft: " << 1.0_ft << std::endl;

  std::cout << std::endl;
  std::cout << "5.0_mi + 1.0_km + 2.0_dm +  3.0_dm - 4.0_cm + 6.0_ft: ";
  std::cout << 5.0_mi + 6.0_ft + 1.0_km + 2.0_dm +  3.0_dm - 4.0_cm << std::endl;
  std::cout << std::endl;

  Distance::MyDistance work = 63.0_km;
  Distance::MyDistance abbreviationToWork = 5400.0_m;
  Distance::MyDistance workout = 3200.0_m;
  Distance::MyDistance shopping = 2400.0_m;

  Distance::MyDistance myDistPerWeek = 4 * (work * 2) - 3 * abbreviationToWork + workout + shopping;

  std::cout << "4 * work * 2 - 3 * abbreviationToWork + workout + shopping: ";
  std::cout << myDistPerWeek << "\n\n";
}
