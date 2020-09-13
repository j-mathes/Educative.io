#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
  void set_data (int a, string b)
  {
       age = a;
       name = b; 
  }
};

class Zebra:public Animal
{
public:

    string message_zebra(string str)
    {
    		
        return "The zebra named " + name + " is " + to_string(age) + "years old. The zebra comes from Africa.";
    }
};

class Dolphin: public Animal
{
public:

    string message_dolphin(string str)
    {
        
        return "The dolphin named " + name + " is " + to_string(age) + "years old. The dolphin comes from New Zeland.";
    }
};
