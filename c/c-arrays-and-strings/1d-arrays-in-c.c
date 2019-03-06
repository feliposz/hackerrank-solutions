#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    scanf("%d", &n);
    arr = (int*) calloc(n, sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    free(arr);
    return 0;
}


