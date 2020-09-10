#include <iostream>
#include <cmath>
using namespace std;

double test(double a, double b) 
{
  double computeSquares;
  double computeProduct;
  double answer;

  computeSquares = pow(a, 2) + pow(b, 2);
  computeProduct = 2*a*b;
  answer = computeSquares + computeProduct;
  cout << "Answer is: " << answer << endl;
  return answer;
}
