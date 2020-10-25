//Use std::shuffle instead of std::random_shuffle. std::random_shuffle has been deprecated since C++14 and removed in C++17, because it uses the C function rand internally.
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
 
 
int main(){
   
  std::cout << std::endl;
 
  std::vector<int> vec1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec2(vec1);
 
  for (auto v:  vec1) std::cout << v << " ";
 
  std::cout << std::endl;
 
  // seed initialises the random number generator.
  unsigned seed= std::chrono::system_clock::now().time_since_epoch().count();
   
  std::cout << std::endl;
   
  std::random_shuffle(vec1.begin(), vec1.end());
  for (auto v:  vec1) std::cout << v << " ";
   
  std::cout << std::endl;
   
  std::shuffle(vec2.begin(), vec2.end(), std::default_random_engine(seed));
  for (auto v: vec2) std::cout <<  v << " ";
   
  std::cout << "\n\n";
   
}
