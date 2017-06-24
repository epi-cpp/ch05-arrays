#include <iostream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

void dump(const vector<int>& a) {
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void pivot(vector<int>& a, int p) {
  auto size = a.size();
  int smaller = 0;
  int larger = size - 1;
  int pivot = a[p];
  int equal = 0;
  while (equal < larger) {
    if (a[equal] < pivot) {
      cout << "swap(1): " << a[equal] << " and " << a[smaller] << " - ";
      swap(a[equal], a[smaller]);
      ++smaller;
      ++equal;
      dump(a);
    }
    else if (a[equal] == pivot) {
      equal++;
    }
    else if (a[equal] > pivot) {
      cout << "swap(2): " << a[equal] << " and " << a[larger] << " - ";
      swap(a[equal],a[larger]);
      --larger;
      dump(a);
    }
  }
}

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
      int num = 0;
      istringstream issNum(numStr);
      issNum >> num;
      const int index = uniform_int_distribution<int>{0, num-1}(seed);
      cout << index << endl;
      for (int i = 0; i < num; ++i) {
        const int v = uniform_int_distribution<int>{0, num*2}(seed);
        nums.push_back(v);
        cout << v << " ";
      }
      cout << endl;
      cout << "pivot value: " << nums[index] << endl;
      pivot(nums, index);
      dump(nums);
    }
  }
  return 0;
}
