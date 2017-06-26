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
  string iStr, jStr;
  while (true) { 
    vector<int> nums;
    cout << "Enter an number or 'q' to exit: ";
    cin >> numStr;
    if (numStr == "q") {
      break;
    }
    else {
      nums.clear();
      copy(numStr.begin(), numStr.end(), back_inserter(nums));
      for (auto& d : nums) d -= '0';
      increment(nums);
      cout << numStr << "+1 = ";
      dump(nums);
    }
  }
  return 0;
}
