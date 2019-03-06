
int lexicographic_sort(const char* a, const char* b) {
  return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  return strcmp(b, a);
}

int count_distinct(const char *s) {
    int c[256] = {0};

    while (*s) {
        c[*s] = 1;
        s++;
    }

    int distinct = 0;
    for (int i = 0; i < 256; i++) {
        distinct += c[i];
    }
    return distinct;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
  int res = count_distinct(a) - count_distinct(b);
  return res ? res : lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
  int res = strlen(a) - strlen(b);
  return res ? res : lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len; j++) {
            if (cmp_func(arr[j-1], arr[j]) > 0) {
                char *tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}


