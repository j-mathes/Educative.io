//In example 2, how can we prevent a derived class, which has the wrong template parameter: Derived4: Base<Derived3>
// templateCRTPCheck.cpp

#include <iostream>

template <typename Derived>
struct Base{
  void interface(){
    static_cast<Derived*>(this)->implementation();
  }
  void implementation(){
    std::cout << "Implementation Base" << std::endl;
  }
private:
    Base(){};
    friend Derived;
};

struct Derived1: Base<Derived1>{
  void implementation(){
    std::cout << "Implementation Derived1" << std::endl;
  }
};

struct Derived2: Base<Derived2>{
  void implementation(){
    std::cout << "Implementation Derived2" << std::endl;
  }
};

struct Derived3: Base<Derived3>{};

// struct Derived4: Base<Derived3>{};

template <typename T>
void execute(T& base){
    base.interface();
}

int main(){
  
  std::cout << std::endl;
  
  Derived1 d1;
  execute(d1);
    
  Derived2 d2;
  execute(d2);
  
  Derived3 d3;
  execute(d3);
  
  // Derived4 d4;
  
  std::cout << std::endl;
  
}

// Explanation - We have used static polymorphism in the function template execute (lines 34 – 37). We invoked the method base.interface on each base argument. The method Base::interface, in lines (7 – 9), is the key point of the CRTP idiom. It dispatches to the implementation of the derived class: static_cast<Derived*>(this)->implementation(), which is possible because the method will be instantiated when called. At this point in time, the derived classes Derived1, Derived2, and Derived3 are fully defined. Therefore, the method Base::interface can use the details of its derived classes. The method Base::implementation (lines 10 – 12) is especially interesting. This method works as the default implementation of the static polymorphism for the class Derived3 (line 30).
// The constructor of the derived class has to call the constructor of the base class. The constructor in the base class is private. Only type T can invoke the constructor of the base class. So, if the derived class is different from the class T, the code doesn’t compile.
