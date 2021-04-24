#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    
    int sum = 0;
    int check = 0;
    for (int i = 1; i <= n; i++) {
        int value;
        scanf("%d", &value);
        sum += i;
        check += value;
    }
    if (sum == check) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

