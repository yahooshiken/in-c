#include <stdio.h>

int brute_force_search(char text[], int text_len, char pattern[], int pat_len) {
  int i = 0, j = 0;
  while (i < text_len && j < pat_len) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }

  return j == pat_len ? i - pat_len : -1;
}

int main() {
  char *text = "aabcdeadeb";
  char *pattern = "ade";
  int text_len = 10;
  int pat_len = 3;

  int idx = brute_force_search(text, text_len, pattern, pat_len);
  printf("%s\n", text);
  for (int i = 0; i < idx; i++) {
    printf(" ");
  }
  printf("%s\n", pattern);

  return 0;
}
