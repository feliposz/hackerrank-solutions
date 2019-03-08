#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s) {

  // Find the largest index k such that s[k] < s[k + 1]
  int k = -1;
  for (int i = 0; i < n - 1; i++) {
    if (strcmp(s[i], s[i + 1]) < 0) {
      k = i;
    }
  }

  // If no such index exists, the permutation is the last permutation.
  if (k < 0) {
    return 0;
  }

  // Find the largest index l greater than k such that s[k] < s[l].
  int l = -1;
  for (int i = k + 1; i < n; i++) {
    if (strcmp(s[k], s[i]) < 0) {
      l = i;
    }
  }

  // Impossible?
  if (l < 0) {
    exit(1);
  }

  // Swap the value of s[k] with that of s[l].
  char *tmp = s[k];
  s[k] = s[l];
  s[l] = tmp;

  // Reverse the sequence from s[k + 1] up to and including the final element
  // s[n].
  for (int i = k + 1, j = n - 1; i < j; i++, j--) {
    char *tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }

  return 1;
}


