#include <algorithm>
#include <iostream>
#include <vector>

class SumMe{
public:

  SumMe(): sum(0){};

  void operator()(int x){
    sum += x;
  }

  int getSum() const {
    return sum;
  }
private:
  int sum;
};

int main(){

  std::cout << std::endl;

  std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Use a lambda function here and class sumMe is no longer needed
  auto sumVec = [](std::vector<int> v) 
  {
    int sum{0};
    for(auto i : v)
      sum += i;
    return sum;
  };

  std::cout << "sumVec: " << sumVec(intVec) << std::endl;
  
  // given solution
  // int sum{0};
  // std::for_each(intVec.begin(), intVec.end(), [&sum](int x){ sum += x;});
  
  // SumMe sumMe = std::for_each(intVec.begin(), intVec.end(), SumMe());
  // std::cout << "sumMe.getSum(): " << sumMe.getSum() << std::endl;

  std::cout << std::endl;

}

// Explanation #
// - First of all, the variable sum represents the state of the lambda function.
// - With C++14, the so-called initialization capture of lambdas is supported. sum{0} declares and initializes a variable of type int which is only valid in the scope of the lambda function.
// - The lambda function is used in line 12. Note that they are constant by default.
// - &sum Stores the address of last updated value of sum.
