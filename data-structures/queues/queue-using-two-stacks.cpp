#include <cmath>
#include <cstdio>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

list<int> in_stack;

void enqueue(int x) {
    /*
    while (out_stack.size()) {
        in_stack.push_back(out_stack.back());
        out_stack.pop_back();
    }
    in_stack.push_back(x);
    */
    in_stack.push_back(x);
}

void dequeue() {
    /*
    while (in_stack.size()) {
        out_stack.push_back(in_stack.back());
        in_stack.pop_back();
    }
    out_stack.pop_back();
    */
    in_stack.pop_front();
}

int peek() {
    /*
    while (in_stack.size()) {
        out_stack.push_back(in_stack.back());
        in_stack.pop_back();
    }
    return out_stack.back();
    */
    return in_stack.front();
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            enqueue(x);
        } else if (op == 2) {
            dequeue();
        } else {
            cout << peek() << endl;
        }
    }
    
    return 0;
}

