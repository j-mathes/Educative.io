// The functionality of the program in example 2 of the previous lesson can be implemented in various ways. Implement each variant.

// Case 1 - Object-oriented with dynamic polymorphism.
// dispatchPolymorphism.cpp

#include <iostream>

struct Base{
    virtual void interface(){
        std::cout << "Implementation Base" << std::endl;
    }
};

struct Derived1: Base{
    virtual void interface(){
        std::cout << "Implementation Derived1" << std::endl;
    }
};

struct Derived2: Base{
    virtual void interface(){
        std::cout << "Implementation Derived2" << std::endl;
    }
};

struct Derived3: Base{};

void execute(Base& base){
    base.interface();
}

int main(){

    std::cout << std::endl;

    Derived1 d1;
    Base& b1 = d1;
    execute(b1);

    Derived2 d2;
    Base& b2 = d2;
    execute(b2);

    Derived3 d3;
    Base& b3 = d3;
    execute(b3);
    
    std::cout << std::endl;

}
// Explanation - We have used dynamic polymorphism in the function template execute (lines 25 – 27). This function only accepts a reference to the class object passed. Now, we make objects of the derived classes and store references to them (lines 34, 38 and 42). The static type of b1, b2, and b3 in lines 34, 38, 42 is Base and the dynamic type is Derived1, Derived2, or Derived3 respectively.

// Case 2 - Just a function template.
// dispatchGeneric.cpp

#include <iostream>

struct Base{
    virtual void interface(){
        std::cout << "Implementation Base" << std::endl;
    }
};

struct Derived1: Base{
    virtual void interface(){
        std::cout << "Implementation Derived1" << std::endl;
    }
};

struct Derived2: Base{
    virtual void interface(){
        std::cout << "Implementation Derived2" << std::endl;
    }
};

struct Derived3: Base{};

template <typename T>
void execute(T& t){
    t.interface();
}

int main(){
    
    std::cout << std::endl;
    
    Derived1 d1;
    execute(d1);
    
    Derived2 d2;
    execute(d2);
    
    Derived3 d3;
    execute(d3);
    
    std::cout << std::endl;
    
}
// Explanation - We have implemented a template function on lines 25 - 28, which delegates execution to the appropriate interface() function on line 27. Base, Derived1, and Derived2 all provide an implementation for the interface() function. Derived3 inherits the implementation from Base.

// Case 3 - To solve this exercise with Concepts, peek into the last chapter of this course. Concepts are a valid and elegant method. Concepts with C++20:
// dispatchConcepts.cpp

#include <iostream>

template <typename T>
concept bool Interface(){
    return requires(T a){
        { a.interface } -> void;
    };
}

struct Base{
    virtual void interface(){
        std::cout << "Implementation Base" << std::endl;
    }
};

struct Derived1: Base{
    virtual void interface(){
        std::cout << "Implementation Derived1" << std::endl;
    }
};

struct Derived2: Base{
    virtual void interface(){
        std::cout << "Implementation Derived2" << std::endl;
    }
};

struct Derived3: Base{};

template <typename Interface>
void execute(Interface& inter){
    inter.interface();
}

int main(){
    
    std::cout << std::endl;
    
    Derived1 d1;
    execute(d1);
    
    Derived2 d2;
    execute(d2);
    
    Derived3 d3;
    execute(d3);
    
    std::cout << std::endl;
    
}

// Explanation - This implementation is based on concepts which will be part of C++20. In the base case, concepts mean that execute can only be invoked with types, which supports a function with the name interface returning void.
