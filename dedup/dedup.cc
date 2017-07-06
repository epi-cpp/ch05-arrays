#include "dedup.h"
#include <iostream>
#include <iterator>

using namespace std;

void dump(const vector<int>& a) {
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ""));
  cout << endl;
}

void dedup(vector<int>& a) {
  int i = 1;
  auto prev = a.begin();
  while (i < a.size()) {
    if (*prev != a[i]) {
      ++prev;
      *prev = a[i];
    }
    ++i;
  }
  a.erase(prev+1, a.end());
}
