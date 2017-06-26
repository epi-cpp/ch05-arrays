#include "multiply.h"
#include <iostream>
#include <iterator>

using namespace std;

void dump(const vector<int>& a) {
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ""));
  cout << endl;
}

void increment(vector<int>& a) {
  auto size = a.size();
  int carry = 0;
  int inc = 1;
  for (int i = size - 1; i >= 0; --i) {
    a[i] = ((a[i]+inc+carry) % 10);
    inc = 0;
    carry = (a[i] == 0) ? 1 : 0;
  }
}
