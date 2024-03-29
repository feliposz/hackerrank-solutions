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

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles)
{

    int r_q_lo = 1;
    int r_q_hi = n;
    int c_q_lo = 1;
    int c_q_hi = n;

    int r_qi = n - r_q + 1;
    int c_qi = n - c_q + 1;

    // TODO: real diagonal coordinates
    int d1_r_lo = r_q + 1 - min(r_q, c_q);
    int d1_c_lo = c_q + 1 - min(r_q, c_q);
    int d1_r_hi = r_q + n - max(r_q, c_q);
    int d1_c_hi = c_q + n - max(r_q, c_q);

    int d2_r_lo =  r_q  + 1 - min(r_q, c_qi);
    int d2_c_lo = -c_qi + n + min(r_q, c_qi);
    int d2_r_hi =  r_q  + n - max(r_q, c_qi);
    int d2_c_hi = c_q - (n - max(r_q, c_qi));

    printf("lo d1: %d %d\n", d1_r_lo, d1_c_lo);
    printf("hi d1: %d %d\n", d1_r_hi, d1_c_hi);
    printf("lo d2: %d %d\n", d2_r_lo, d2_c_lo);
    printf("hi d2: %d %d\n", d2_r_hi, d2_c_hi);

    for (int j = 0; j < k; j++)
    {
        int r_test = obstacles[j][0];
        int c_test = obstacles[j][1];

        // row blocks
        if (r_test == r_q)
        {
            if (c_test < c_q)
            {
                c_q_lo = max(c_q_lo, c_test + 1);
            }
            else
            {
                c_q_hi = min(c_q_hi, c_test - 1);
            }
        }

        // column blocks
        if (c_q == c_test)
        {
            if (r_test < r_q)
            {
                r_q_lo = max(r_q_lo, r_test + 1);
            }
            else
            {
                r_q_hi = min(r_q_hi, r_test - 1);
            }
        }

        // diagonal 1
        if (r_test - r_q == c_test - c_q)
        {
            if (r_test < r_q)
            {
                if (r_test + 1 > d1_r_lo)
                {
                    d1_r_lo = r_test + 1;
                    d1_c_lo = c_test + 1;
                }
            }
            else
            {
                if (r_test - 1 < d1_r_hi)
                {
                    d1_r_hi = r_test - 1;
                    d1_c_hi = c_test - 1;
                }
            }
        }

        // diagonal 2
        if (r_test - r_q == c_q - c_test)
        {
            if (r_test < r_q)
            {
                if (r_test + 1 > d2_r_lo)
                {
                    d2_r_lo = r_test + 1;
                    d2_c_lo = c_test - 1;
                }
            }
            else
            {
                if (r_test - 1 < d2_r_hi)
                {
                    d2_r_hi = r_test - 1;
                    d2_c_hi = c_test + 1;
                }
            }
        }

    }

    int total = 0;

    total += r_q_hi - r_q_lo;
    total += c_q_hi - c_q_lo;
    total += d1_r_hi - d1_r_lo;
    total += d2_r_hi - d2_r_lo;

    return total;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char** r_qC_q = split_string(readline());

    char* r_q_endptr;
    char* r_q_str = r_qC_q[0];
    int r_q = strtol(r_q_str, &r_q_endptr, 10);

    if (r_q_endptr == r_q_str || *r_q_endptr != '\0') { exit(EXIT_FAILURE); }

    char* c_q_endptr;
    char* c_q_str = r_qC_q[1];
    int c_q = strtol(c_q_str, &c_q_endptr, 10);

    if (c_q_endptr == c_q_str || *c_q_endptr != '\0') { exit(EXIT_FAILURE); }

    int** obstacles = malloc(k * sizeof(int*));

    for (int i = 0; i < k; i++) {
        *(obstacles + i) = malloc(2 * (sizeof(int)));

        char** obstacles_item_temp = split_string(readline());

        for (int j = 0; j < 2; j++) {
            char* obstacles_item_endptr;
            char* obstacles_item_str = *(obstacles_item_temp + j);
            int obstacles_item = strtol(obstacles_item_str, &obstacles_item_endptr, 10);

            if (obstacles_item_endptr == obstacles_item_str || *obstacles_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(obstacles + i) + j) = obstacles_item;
        }
    }

    int obstacles_rows = k;
    int obstacles_columns = 2;

    int result = queensAttack(n, k, r_q, c_q, obstacles_rows, obstacles_columns, obstacles);

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

