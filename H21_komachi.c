#include <stdio.h>

int main() {
  int i, s, sign[10];
  long n, x;

  do {
    for (i = 1; i <= 9; i++) {
      printf("%d-th operator [-1, 0, 1]: ", i);
      scanf("%d", &sign[i]);
    }

    x = 0, n = 0, s = 1;
    for (i = 1; i <= 9; i++) {
      if (sign[i] == 0) {
        n = 10 * n + i;
      } else {
        x = x + s * n;
        s = sign[i];
        n = i;
      }
    }
    x = x + s * n;

    for (i = 1; i <= 9; i++) {
      if (sign[i] == 1) {
        printf("+");
      } else if (sign[i] == -1) {
        printf("-");
      }
      printf("%d", i);
    }

    if (x == 100) {
      printf("=100\n");
    } else {
      printf("!=100\n");
    }

  } while (x != 100);
  return 0;
}