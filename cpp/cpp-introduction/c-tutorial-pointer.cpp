#include <stdio.h>

void update(int *a,int *b) {
    int new_a = *a + *b;
    int new_b = *a - *b;
    if (new_b < 0) new_b = -new_b;
    *a = new_a;
    *b = new_b;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


