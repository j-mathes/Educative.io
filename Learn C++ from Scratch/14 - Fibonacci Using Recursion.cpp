#include<iostream>
using namespace std;

int fibonacci(int n)
{
  if (n <= 1)
    return n;
  else
    return (fibonacci(n-1) + fibonacci(n-2));
} 

string test(int n)
{
    int i=0;
    string ans="";
    cout<<"\nFibonacci Series is as follows\n";
 
    while(i<n)
    {
        cout<<" "<<fibonacci(i);
        ans += std::to_string(fibonacci(i))+" ";
        i++;
    }
    return ans;
}
