#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "dedup.h"

using namespace std;

int main(int argc, char* argv[]) {
  default_random_engine seed((random_device())());
  string numStr;
  while (true) { 
    vector<int> mult1;
    cout << "Enter two numbers or 'q' to exit: ";
    cin >> numStr;
    if (numStr == "q") {
      break;
    }
    else {
      mult1.clear();
      int num = 0;
      istringstream issNum(numStr);
      for (int i = 0; i < num; ++i) {
        const int jump = uniform_int_distribution<int>{0, num-1}(seed);
        mult1.push_back(jump);
      }
      dump(mult1);
      dedup(mult1);
      dump(mult1);
    }
  }
  return 0;
}
