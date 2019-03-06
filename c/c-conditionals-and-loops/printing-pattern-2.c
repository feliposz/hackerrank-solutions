#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int i, j;
    for (i = -n+1; i < n; i++) {
        for (j = -n+1; j < n; j++) {
            int ring = 1 + (abs(i) > abs(j) ? abs(i) : abs(j));
            printf("%d ", ring);
        }
        printf("\n");
    }
    return 0;
}


