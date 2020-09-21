#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;
int main() 
{
  array<int, 5> a {-10, 5, 1, 4, 5};
  vector<int> v {-10, 5, 1, 4, 5};
  set<int> s {-10, 5, 1, 4, 5};
  unordered_multiset<int> u {-10, 5, 1, 4, 5};
}
