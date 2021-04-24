#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {    
    for (;;) {
        int c = getchar();
        if (c >= '0' && c <= '9') {
            printf("%d", (c - '0' + 1) % 10);
        } else {
            break;
        }
    }
    return 0;
}

