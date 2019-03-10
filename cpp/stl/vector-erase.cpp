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
    int del_1, del_a, del_b;
    cin >> del_1 >> del_a >> del_b;
    del_1--;
    del_a--;
    del_b--;
    v.erase(v.begin() + del_1);
    v.erase(v.begin() + del_a, v.begin() + del_b);
    cout << v.size() << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      cout << *it << " ";
    }
    return 0;
}

