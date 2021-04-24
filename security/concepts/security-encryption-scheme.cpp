#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    long result = 1;
    while (n > 0) {
        result *= n--;
    }
    printf("%ld", result);
    return 0;
}

