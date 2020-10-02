#include <iostream>

class InvokeWithInt
{
public:
  InvokeWithInt(int){}
  
  template<typename T>
  InvokeWithInt(T) = delete;
};

int main() {
  InvokeWithInt iwi(5);
  InvokeWithInt iwi(5L);
}
