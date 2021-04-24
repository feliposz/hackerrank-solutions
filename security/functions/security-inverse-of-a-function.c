#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {


    int n;
    scanf("%d", &n);
    
    int *inv = malloc(sizeof(int) * n);
    for (int i = 1; i <= n; i++) {
        int value;
        scanf("%d", &value);
        inv[value-1] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", inv[i]);
    }
       
    return 0;
}

