#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {


    int n;
    scanf("%d", &n);
    
    int *perm = malloc(sizeof(int) * n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &perm[i-1]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", perm[perm[i]-1]);
    }

         
    return 0;
}

