#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s[1000];
    scanf("%[^\n]%*c", s);

    int dig[10] = {0};
    int i = 0;
    int n = strlen(s);
    for (i = 0; i < n; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            dig[c - '0']++;
        }
    }

    
    for (i = 0; i < 10; i++) {
        printf("%d ", dig[i]);
    }

    return 0;
}

