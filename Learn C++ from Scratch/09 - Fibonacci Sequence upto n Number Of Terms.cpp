#include <iostream>
#include <string>
using namespace std;

string test(int range)
{ 
    string ans = ""; //return the correct string 
    cout << "Fibonacci Series upto " << range << " Terms "<< endl;
  
    int last = 0;
    int sum = 0;
    for(int i = 0; i < range; i++)
    {
        if (i <= 1)
        {
            ans += to_string(i) + " ";
            sum = i;
        }
        else
        {
            int temp = sum;
            sum = last + sum;
            ans += to_string(sum) + " ";
            last = temp;
        }
    }  
    return ans;
}
