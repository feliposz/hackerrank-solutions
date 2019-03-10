#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
  int queries;
  cin >> queries;
  set<int> s;
  while (queries-- > 0) {
    int type, val;
    cin >> type >> val;
    switch (type) {
    case 1:
      s.insert(val);
      break;
    case 2:
      s.erase(val);
      break;
    case 3:
      set<int>::iterator it = s.find(val);
      if (it == s.end()) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
      break;
    }
  }
  return 0;
}




