// With autos
//-----------
#include <chrono>
#include <future>
#include <map>
#include <string>
#include <tuple>

int main()
{
  auto myInts = {1, 2, 3};
  auto myIntBegin = myInts.begin();

  std::map<int, std::string> myMap = {{1, std::string("one")}, {2, std::string("two")}};
  auto myMapBegin = myMap.begin();

  auto func = [](const std::string& a){ return a;};

  auto futureLambda= std::async([](const std::string& s ) {return std::string("Hello ") + s;}, std::string("lambda function."));

  auto begin = std::chrono::system_clock::now();

  auto pa = std::make_pair(1, std::string("second"));

  auto tup = std::make_tuple(std::string("second"), 4, 1.1, true, 'a');
}

// Without autos
//--------------
#include <chrono>
#include <functional>
#include <future>
#include <initializer_list>
#include <map>
#include <string>
#include <tuple>

int main()
{
  std::initializer_list<int> myInts = {1, 2, 3};
  std::initializer_list<int>::iterator myIntBegin = myInts.begin();

  std::map<int, std::string> myMap = {{1, std::string("one")}, {2, std::string("two")}};
  std::map<int, std::string>::iterator myMapBegin = myMap.begin();

  std::function< std::string(const std::string&) > func= [](const std::string& a){ return a;};

  std::future<std::string> futureLambda= std::async([](const std::string& s ) {return std::string("Hello ") + s;}, std::string("lambda function."));

  std::chrono::time_point<std::chrono::system_clock> begin = std::chrono::system_clock::now();

  std::pair<int, std::string> pa = std::make_pair(1, std::string("second"));

  std::tuple<std::string, int, double, bool, char> tup = std::make_tuple(std::string("second"), 4, 1.1, true, 'a');
}
