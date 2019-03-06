#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    int a, b, max_and = 0, max_or = 0, max_xor = 0;
    for (b = 1; b <= n; b++) {
        for (a = 1; a < b; a++) {
          int and = a & b, or = a | b, xor = a ^ b;
          if (and<k &&and> max_and)
            max_and = and;
          if (or <k && or> max_or)
            max_or = or ;
          if (xor<k && xor> max_xor)
            max_xor = xor;
        }
    }
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
 
    return 0;
}

