#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int n, s, p, q;
    cin >> n >> s >> p >> q;
    unordered_map<int,int> t;
    int v = s;
    for (int i = 0; i < n; i++) {
        int repeat = ++t[v & 0x7FFFFFFF];
        if (repeat > 1) {
            break;
        }
        if (i > 100000) {
            cout << n;
            return 0;
        }
        v = v * p + q;
    }
    cout << t.size();
    //cout << n;
    return 0;
}

