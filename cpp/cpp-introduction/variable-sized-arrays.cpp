#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<vector<int>> vv;

    int num_arrays, num_queries;
    cin >> num_arrays >> num_queries;

    while (num_arrays-- > 0) {
        int array_size;
        cin >> array_size;
        vector<int> v;
        while (array_size-- > 0) {
            int value;
            cin >> value;
            v.push_back(value);
        }
        vv.push_back(v);
    }

    while (num_queries-- > 0) {
        int i, j;
        cin >> i >> j;
        cout << vv[i][j] << endl;
    }

    return 0;
}


