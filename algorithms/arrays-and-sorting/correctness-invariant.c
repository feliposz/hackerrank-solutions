#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void checkSort(int N, int arr[]) {
    for (int i = 1; i < N; i++) {
        if (arr[i-1] > arr[i]) {
            fprintf(stderr, "not ok %d\n", N);
            return;
        }
    }
    fprintf(stderr, "ok %d\n", N);
}

void insertionSort(int N, int arr[]) {
    int i,j;
    int value;    
    for(i=1;i<N;i++) // arr = { 4, 1 }
    {
        checkSort(i, arr); // i = 2
        value=arr[i]; // 1
        j=i-1; // i = 2, j = 1
        while(j>=0 && value<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=value;
    }
    checkSort(i, arr);
    for(j=0;j<N;j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }
}

int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}

