//Create an std::vector and determine its size and capacity before and after a call to shrink_to_fit

#include <iostream>
#include <vector>
using namespace std;

int main() {
  
  vector<int> v{1,2,3,4,5,7};
  cout << v.size() << endl;
  cout << v.capacity() << endl;
  v.shrink_to_fit();
  cout << v.capacity() << endl;

}

// Provided solution
#include <iostream>
#include <vector>

int main(){

  std::cout << std::endl;

  std::vector<int> intVec1(5, 2011);
  intVec1.reserve(10);
  std::cout << "intVec1.size(): " << intVec1.size() << std::endl;
  std::cout << "intVec1.capacity(): " << intVec1.capacity() << std::endl;
  intVec1.shrink_to_fit();
  std::cout << "intVec1.capacity(): " << intVec1.capacity() << std::endl;
  
  std::cout << std::endl;
  
  std::vector<int> intVec2(10);
  std::cout << "intVec2.size() : " << intVec2.size() << std::endl;
  std::vector<int> intVec3{10};
  std::cout << "intVec3.size() : " << intVec3.size() << std::endl;
  std::vector<int> intVec4{5, 2011};
  std::cout << "intVec4.size() : " << intVec4.size() << std::endl;

  std::cout << std::endl;
  
}

// The explanation is pretty straight-forward, as we have initialized an intVec1 with a size of 5 values. The capacity of the vector is 10. After calling the shrink_to_fit function on this vector in line 12, the capacity of the vector reduces to 5.
// By using () parenthesis, we declared the size of a vector and by using {} curly braces, we inserted a value in the vector.
