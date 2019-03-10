#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size;
    cin >> size;
    vector<int> v;    
    while (size-- > 0) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << " ";
    }
    return 0;
}

