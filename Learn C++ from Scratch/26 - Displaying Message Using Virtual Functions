#include <iostream>
using namespace std;

class Mammal
{
public:
  Mammal(int a){age = a;}
  virtual void Eat() {cout << "Mammal eats food." << endl;}
  virtual void Speak() {cout << "Mammal speaks mammalian!!" << endl;}
  int get_Age() {return age;}

protected:
  int age;    
};

class Dog:public Mammal
{
  public:
    Dog(int age) : Mammal(age) {}
    void Eat()
    {
      cout << "Dog eats meat." << endl;
    }

    void Speak()
    {
      cout << "Dog barks: ruff! ruff!" << endl;
    }
};

class Cat:public Mammal
{
  public:
    Cat(int age) : Mammal(age) {}
    void Eat()
    {
      cout << "Cat eats meat." << endl;
    }

    void Speak()
    {
      cout << "Cat meows: Meow! Meow!" << endl;
    }
};

int main() {
  Mammal m(10);
  Dog d(4);
  Cat c(7);
  
  cout << "Calling Dog class functions" << endl;
  d.Eat();
  d.Speak();
  cout << "Dog's age is: "  << to_string(d.get_Age()) << endl;
 
  cout << "Calling Cat class functions" << endl;
  c.Eat();
  c.Speak();
  cout << "Cat's age is: " << to_string(c.get_Age()) << endl;
  
  return 0;
}
