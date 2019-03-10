#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  vector<int> v;
  int size;
  cin >> size;
  while (size-- > 0) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << ' ';
  }

  return 0;
}

