#include <iostream>
#include <cmath>
using namespace std;

float test(float a, float b) 
{ 
  float computeSqrt;
  float aSquare = pow(a, 2);
  float bSquare = pow(b, 2);
  float interm = aSquare + bSquare;
  computeSqrt = sqrt(interm);
  cout << "Answer is: " << computeSqrt<<endl;
  return computeSqrt;
}
