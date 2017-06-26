#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "multiply.h"

using namespace std;

int main(int argc, char* argv[]) {
  default_random_engine seed((random_device())());
  string numStr;
  while (true) { 
    vector<int> mult1;
    vector<int> mult2;
    cout << "Enter two numbers or 'q' to exit: ";
    cin >> numStr;
    if (numStr == "q") {
      break;
    }
    else {
      mult1.clear();
      copy(numStr.begin(), numStr.end(), back_inserter(mult1));
      cin >> numStr;
      mult2.clear();
      copy(numStr.begin(), numStr.end(), back_inserter(mult2));
      for (auto& d : mult1) d -= '0';
      for (auto& d : mult2) d -= '0';
      auto prod = multiply(mult1, mult2);
      dump(mult1);
      cout << " * ";
      dump(mult2);
      cout << " = ";
      dump(prod);
    }
  }
  return 0;
}
