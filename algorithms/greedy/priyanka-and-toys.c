#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Complete the toys function below.
int toys(int w_count, int* w) {
    qsort(w, w_count, sizeof(int), cmp);
    
    int max_w = w[0] + 4;
    
    int containers = 1;
    for (int i = 0; i < w_count; i++) {
        if (w[i] > max_w) {            
            containers++;
            max_w = w[i] + 4;
        }
    }
    
    return containers;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** w_temp = split_string(readline());

    int* w = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* w_item_endptr;
        char* w_item_str = *(w_temp + i);
        int w_item = strtol(w_item_str, &w_item_endptr, 10);

        if (w_item_endptr == w_item_str || *w_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(w + i) = w_item;
    }

    int w_count = n;

    int result = toys(w_count, w);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

