#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'jimOrders' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY orders as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
 struct CustOrder {
    int customer;
    int request;
    int time;
 };
 
 int cmp(const void *a, const void *b)
{
    struct CustOrder *A = (struct CustOrder *)a;
    struct CustOrder *B = (struct CustOrder *)b;
    
    int serv_a = A->request + A->time;
    int serv_b = B->request + B->time;
    
    if (serv_a == serv_b) {
        return A->customer - A->customer;
    }
    return serv_a - serv_b;
}
 
int* jimOrders(int orders_rows, int orders_columns, int** orders, int* result_count) {
    struct CustOrder *cust_orders = malloc(orders_rows * sizeof(struct CustOrder));

    for (int i = 0; i < orders_rows; i++) {
        cust_orders[i].customer = i + 1;
        cust_orders[i].request = orders[i][0];
        cust_orders[i].time = orders[i][1];
    }

    qsort(cust_orders, orders_rows, sizeof(struct CustOrder), cmp);
    
    int *result = malloc(orders_rows * sizeof(int));
    
    for (int i = 0; i < orders_rows; i++) {
        result[i] = cust_orders[i].customer;
    }
    
    *result_count = orders_rows;
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int** orders = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(orders + i) = malloc(2 * (sizeof(int)));

        char** orders_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++) {
            int orders_item = parse_int(*(orders_item_temp + j));

            *(*(orders + i) + j) = orders_item;
        }
    }

    int result_count;
    int* result = jimOrders(n, 2, orders, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

