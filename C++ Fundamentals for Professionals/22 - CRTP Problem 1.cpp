//Extend the given piece of code with a Person class. A Person should have a first and last name.
//We need to create two objects of the Person class and compare these objects using relational operators.
// templateCRTPRelational.cpp

#include <iostream>
#include <string>
#include <utility>

template<class Derived>
class Relational{};

// Relational Operators

template <class Derived>
bool operator > (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return d2 < d1;
}

template <class Derived>
bool operator == (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return !(d1 < d2) && !(d2 < d1);
}

template <class Derived>
bool operator != (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 < d2) || (d2 < d1);
}

template <class Derived>
bool operator <= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 < d2) || (d1 == d2);
}

template <class Derived>
bool operator >= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 > d2) || (d1 == d2);
}

// Apple

class Apple: public Relational<Apple>{
public:
    explicit Apple(int s): size{s}{};
    friend bool operator < (Apple const& a1, Apple const& a2){
        return a1.size < a2.size;
    }
private:
    int size;
};

// Man

class Man: public Relational<Man>{
public:
    explicit Man(const std::string& n): name{n}{}
    friend bool operator < (Man const& m1, Man const& m2){
        return m1.name < m2.name;
    }
private:
    std::string name;
};

// class Person
class Person: public Relational<Person>{
public:
    Person(std::string fst, std::string sec): first(fst), last(sec){}
    friend bool operator < (Person const& p1, Person const& p2){
        return std::make_pair(p1.first, p2.last) < std::make_pair(p2.first, p2.last);
    }
private:
    std::string first;
    std::string last;
};
        

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  Apple apple1{5};
  Apple apple2{10}; 
  std::cout << "apple1 < apple2: " << (apple1 < apple2) << std::endl;
  std::cout << "apple1 > apple2: " << (apple1 > apple2) << std::endl;
  std::cout << "apple1 == apple2: " << (apple1 == apple2) << std::endl;
  std::cout << "apple1 != apple2: " << (apple1 != apple2) << std::endl;
  std::cout << "apple1 <= apple2: " << (apple1 <= apple2) << std::endl;
  std::cout << "apple1 >= apple2: " << (apple1 >= apple2) << std::endl;
  
  std::cout << std::endl;
    
  Man man1{"grimm"};
  Man man2{"jaud"};
  std::cout << "man1 < man2: " << (man1 < man2) << std::endl; 
  std::cout << "man1 > man2: " << (man1 > man2) << std::endl; 
  std::cout << "man1 == man2: " << (man1 == man2) << std::endl; 
  std::cout << "man1 != man2: " << (man1 != man2) << std::endl;
  std::cout << "man1 <= man2: " << (man1 <= man2) << std::endl;
  std::cout << "man1 >= man2: " << (man1 >= man2) << std::endl;
  
  std::cout << std::endl;
  
  Person rainer{"Rainer", "Grimm"};
  Person marius{"Marius", "Grimm"};
  std::cout << "rainer < marius: " << (rainer < marius) << std::endl; 
  std::cout << "rainer > marius: " << (rainer > marius) << std::endl; 
  std::cout << "rainer == marius: " << (rainer == marius) << std::endl; 
  std::cout << "rainer != marius: " << (rainer != marius) << std::endl;
  std::cout << "rainer <= marius: " << (rainer <= marius) << std::endl;
  std::cout << "rainer >= marius: " << (rainer >= marius) << std::endl;
  
  std::cout << std::endl;  
}

// Explanation - In the code above, we have defined the Person class which contains the string variables, first and last and a < operator to compare two people’s lengths in lines 75 – 77. The class Person is publicly derived (line 72) from the class Relational<Person>. We have implemented (for classes of the kind Relational) the greater than operator > (lines 12 - 17), the equality operator == (lines 19 - 24), the not equal operator != (lines 26 - 31), the less than or equal operator <= (line 33 - 38) and the greater than or equal operator >= (lines 40 - 45). The less than or equal and greater than or equal operators use the equality operator (line 37 and 44). All these operators convert their operands to Derived const&: Derived const& d1 = static_cast<Derived const&>(op1).
// In the main program, we have compared the Apple, Man, and Person classes for all the operators mentioned above.
