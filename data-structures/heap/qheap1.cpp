#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    set<int> h;
        
    int q;
    cin >> q;
    
    while (q-- > 0) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            h.insert(x);
        } else if (op == 2) {
            cin >> x;
            h.erase(x);
        } else {
            auto it = h.begin();
            cout << *it << endl;
        }
    }
    
    return 0;
}

