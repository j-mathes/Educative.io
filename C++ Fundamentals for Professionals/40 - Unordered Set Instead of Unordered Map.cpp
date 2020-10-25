// Use std::unordered_set instead of std::unordered_map and std::unordered_multiset instead of std::unordered_multimap in the program.
// Original
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main(){

  std::cout << std::endl;

  long long home = 497074123456;
  long long mobile = 4916046123356;

  // constructor
  std::unordered_multimap<std::string, long long> multiMap{{"grimm", home}, {"grimm", mobile}, {"jaud-grimm", home}};
  std::unordered_map<std::string, int> uniqMap{{"bin", 1}, {"root", 0}, {"nobody", 65834}, {"rainer", 1000}};

  // show the unordered maps
  std::cout << "multiMap: ";
  for(auto m : multiMap) std::cout << '{' << m.first << ", " << m.second << '}';

  std::cout << std::endl;

  std::cout << "uniqMap: ";
  for(auto u : uniqMap) std::cout << '{' << u.first << ", " << u.second << '}';
  std::cout << std::endl;

  std::cout << std::endl;

  // insert elements
  long long work = 4970719754513;

  multiMap.insert({"grimm", work});
  // will not work
  // multiMap["grimm-jaud"]=4916012323356;

  uniqMap["lp"] = 4;
  uniqMap.insert({"sshd", 71});

  std::map<std::string, int> myMap{{"ftp", 40}, {"rainer", 999}};
  uniqMap.insert(myMap.begin(), myMap.end());

  // show the unordered maps
  std::cout << "multiMap: ";
  for(auto m : multiMap) std::cout << '{' << m.first << ", " << m.second << '}';

  std::cout << std::endl;

  std::cout << "uniqMap: ";
  for(auto u : uniqMap) std::cout << '{' << u.first << ", " << u.second << '}';
  std::cout << std::endl;


  std::cout << std::endl;
  // search for elements

  // only grimm
  auto iter = multiMap.equal_range("grimm");
  std::cout << "grimm: ";
  for(auto itVal = iter.first; itVal != iter.second;++itVal){
    std::cout << itVal->second << " ";
  }

  std::cout << std::endl;

  std::cout << "multiMap.count(grimm): " << multiMap.count("grimm") << std::endl;

  auto it= uniqMap.find("root");
  if (it != uniqMap.end()){
    std::cout << "uniqMap.find(root): " << it->second << std::endl;
    std::cout << "uniqMap[root]: " << uniqMap["root"] << std::endl;
  }

  // will create a new entry
  std::cout << "uniqMap[notAvailable]: " << uniqMap["notAvailable"] << std::endl;

  std::cout << std::endl;

  // remove
  int numMulti= multiMap.erase("grimm");
  int numUniq= uniqMap.erase("rainer");

  std::cout << "Erased " << numMulti << " times grimm from multiMap." << std::endl;
  std::cout << "Erased " << numUniq << " times rainer from uniqMap." << std::endl;

  // all
  multiMap.clear();
  uniqMap.clear();

  std::cout << std::endl;

  std::cout << "multiMap.size(): " << multiMap.size() << std::endl;
  std::cout << "uniqMap.size(): " << uniqMap.size() << std::endl;

  std::cout << std::endl;
}

// Solution
#include <iostream>
#include <set>
#include <unordered_set>

int main(){

  std::cout << std::endl;

  // constructor
  std::unordered_multiset<int> multiSet{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::unordered_set<int> uniqSet(multiSet.begin(), multiSet.end());

  // show the difference
  std::cout << "multiSet: ";
  for(auto m : multiSet) std::cout << m << " ";

  std::cout << std::endl;

  std::cout << "uniqSet: ";
  for(auto s : uniqSet) std::cout << s << " ";

  std::cout << std::endl << std::endl;

  // insert elements
  multiSet.insert(-1000);
  uniqSet.insert(-1000);

  std::set<int> mySet{-5, -4, -3, -2, -1};
  multiSet.insert(mySet.begin(), mySet.end());
  uniqSet.insert(mySet.begin(), mySet.end());

  // show the difference
  std::cout << "multiSet: ";
  for(auto m : multiSet) std::cout << m << " ";

  std::cout << std::endl;

  std::cout << "uniqSet: ";
  for(auto s : uniqSet) std::cout << s << " ";

  std::cout << std::endl << std::endl;

  // search for elements
  auto it = uniqSet.find(5);
  if (it != uniqSet.end()){
    std::cout << "uniqSet.find(5): " << *it << std::endl;
  }

  std::cout << "multiSet.count(5): " << multiSet.count(5) << std::endl;

  std::cout << std::endl;

  // remove
  int numMulti = multiSet.erase(5);
  int numUniq = uniqSet.erase(5);

  std::cout << "Erased " << numMulti << " times 5 from multiSet." << std::endl;
  std::cout << "Erased " << numUniq << " times 5 from uniqSet." << std::endl;

  // all
  multiSet.clear();
  uniqSet.clear();

  std::cout << std::endl;

  std::cout << "multiSet.size(): " << multiSet.size() << std::endl;
  std::cout << "uniqSet.size(): " << uniqSet.size() << std::endl;

  std::cout << std::endl;

}

// Explanation
//  In lines 10 and 11, we have initialized an std::unordered_multiset with some integer values and also an std::unordered_set, which contains unique values which are repeated in std::unordered_multiset.
//  In lines 25 and 26, we inserted the value -1000 in both sets.
//  In lines 54 and 55, we have erased the value 5 from both sets.
//  In lines 61 and 62, we have used the clear function which deletes all elements from both of the sets.
