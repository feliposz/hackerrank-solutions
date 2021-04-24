#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    
    int *perm = malloc(sizeof(int) * (n+1));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &perm[i]);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (i == perm[perm[i]]) {
            count++;
        }
    }
    
    if (count == n) {
        printf("YES");
    } else {
        printf("NO");
    }
    
    return 0;
}

