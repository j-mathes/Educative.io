#include <iostream>
using namespace std;

class Triangle
{
  public:
  Triangle(float, float);
  void set_length(float l){length = l;}
  void set_height(float h){height = h;}
  float get_length(){return length;}
  float get_height(){return height;}
  float area();

  private:
  float length;
  float height; 
};

Triangle::Triangle (float l, float h)
{
  length = l;
  height = h;
}

float Triangle::area()
{
  return (length * height) / 2;
}

float test(float length, float height)
{
  Triangle t(length, height);
  
  float answer = t.area();
  
  cout << "Area: " << answer << endl; 

  return answer;
}
