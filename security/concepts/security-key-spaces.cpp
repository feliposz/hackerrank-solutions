#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string msg;
    getline(cin, msg);
    int key;
    cin >> key;
    for (char c : msg) {
        int v = c - '0';
        v = (v + key) % 10;
        cout << v;
    }
    return 0;
}

