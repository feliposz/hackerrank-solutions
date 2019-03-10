#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size;
    cin >> size;
    vector <int> v;
    while (size-- > 0) {
      int val;
      cin >> val;
      v.push_back(val);
    }
    int queries;
    cin >> queries;
    while (queries-- > 0) {
      int query;
      cin >> query;
      vector<int>::iterator low = lower_bound(v.begin(), v.end(), query);
      if (*low == query) {
        cout << "Yes " << (low - v.begin() + 1) << endl;
      } else {
        cout << "No " << (low - v.begin() + 1) << endl;
      }
    }
    return 0;
}

