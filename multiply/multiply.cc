#include "multiply.h"
#include <iostream>
#include <iterator>

using namespace std;

void dump(const vector<int>& a) {
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ""));
  cout << endl;
}

void add(vector<int>& a, vector<int>& b, vector<int>& sum) {
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
  vector<int> p;
  vector<int> s;
  auto sizea = a.size();
  auto sizeb = b.size();
  int carry = 0;
  for (int i = sizea - 1; i >= 0; --i) {
    auto k = sizea - i - 1; 
    for (int j = sizeb - 1; j >= 0; --j) {
      k += sizeb - j - 1;
      if (p.size() <= k) p.push_back(0);
      auto prod = (a[i]*b[j]+carry);
      p[k] += (prod % 10);
      carry = (prod / 10);
    }
  }
  return {p.rbegin(), p.rend()};
}
