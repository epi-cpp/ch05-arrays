#include "adv_game.h"
#include <iostream>
#include <iterator>

using namespace std;

void dump(const vector<int>& a) {
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ""));
  cout << endl;
}

bool adv_game(vector<int>& a) {
  auto size = a.size();
  int i = 0;
  bool result = a[i] > 0;
  auto max = 0;
  auto max_i = i+1;
  while (i < size) {
    auto j = a[i];
    if (i+j >= size-1) {
      break;
    }
    max = 0;
    max_i = i+1;
    for (auto k = i+1; k <= (j+i); ++k) {
      if (a[k] > max) {
        max = a[k];
        max_i = k;
      }
    }
    i = max_i;
    if (max <= 0) {
      result = false;
      break;
    }
  }
  return result;
}
