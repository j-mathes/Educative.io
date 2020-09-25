#include <iostream>
#include <string>
#include <utility>
#include <initializer_list>
#include <vector>

template <typename T, typename ... T1>
T createT(T1&& ... t1){
  return T(std::forward<T1>(t1)...);
}

int main(){

  std::cout << std::endl;

  // Lvalues
  int five=5;
  int myFive= createT<int>(five);
  std::cout << "myFive: "  << myFive << std::endl;

  std::string str{"Lvalue"};
  std::string str2= createT<std::string>(str);
  std::cout << "str2: " << str2 << std::endl;

  // Rvalues
  int myFive2= createT<int>(5);
  std::cout << "myFive2: " << myFive2 << std::endl;

  std::string str3= createT<std::string>(std::string("Rvalue"));
  std::cout << "str3: " << str3 << std::endl;

  std::string str4= createT<std::string>(std::move(str3));
  std::cout << "str4: " << str4 << std::endl;

  //variable number of parameters
  int lValue= createT<int>(1);
  int i= createT<int>(lValue);
  std::cout << "lvalue = " << lValue;
  std::cout<< " " <<std::endl;

  std::cout << "i = " << i;
  std::cout<< " " <<std::endl;

  std::string s= createT<std::string>("Only for testing purpose.");
  std::cout << s;
  std::cout<< " " <<std::endl;

  typedef std::vector<int> IntVec;
  IntVec intVec= createT<IntVec>(std::initializer_list<int>({1, 2, 3, 4, 5}));
    for (auto i = intVec.begin(); i != intVec.end(); ++i) 
    std::cout << *i << " ";

  std::cout << std::endl;

};
