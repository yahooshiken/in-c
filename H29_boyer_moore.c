#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int boyer_moore_search(char text[], int text_len, char pattern[], int pat_len) {
  int skip[128];
  int i, j;
  for (i = 0; i < 128; i++) {
    skip[i] = pat_len;
  }

  for (i = 0; i < pat_len - 1; i++) {
    skip[pattern[i]] = pat_len - (i + 1);
  }

  i = pat_len - 1;
  while (i < text_len) {
    j = pat_len - 1;
    while (text[i] == pattern[j]) {
      if (j == 0) {
        return i;
      }
      i--;
      j--;
    }
    i = i + max(skip[text[i]], pat_len - j);
  }
  return -1;
}

int main() {
  char *text = "aabcdeadeb";
  char *pattern = "ade";
  int text_len = 10;
  int pat_len = 3;

  int idx = boyer_moore_search(text, text_len, pattern, pat_len);
  printf("%s\n", text);
  for (int i = 0; i < idx; i++) {
    printf(" ");
  }
  printf("%s\n", pattern);

  return 0;
}
