#include <stdio.h>

#define NUM 10

void counting_sort(int a[], int b[], int c[], int atemp[]) {
  int i, j;
  for (i = 0; i < NUM; i++) {
    c[i] = 0;
  }
  for (j = 0; j < NUM; j++) {
    c[a[j]] += 1;
  }
  for (i = 1; i < NUM; i++) {
    c[i] = c[i] + c[i - 1];
  }
  for (j = NUM - 1; j >= 0; j--) {
    b[c[a[j]] - 1] = atemp[j];
    c[a[j]]--;
  }
}

int main() {
  int i, j;
  int aradall[NUM] = {56, 42, 333, 60, 1, 71, 92, 235, 53, 19};
  int aradcrt[NUM], b[NUM], c[NUM];

  for (i = 0; i < NUM; i++) {
    aradcrt[i] = aradall[i] % 10;
  }
  counting_sort(aradcrt, b, c, aradall);
  for (i = 0; i < NUM; i++) {
    aradall[i] = b[i];
  }
  for (i = 0; i < NUM; i++) {
    aradcrt[i] = aradall[i] / 10 % 10;
  }

  counting_sort(aradcrt, b, c, aradall);
  for (i = 0; i < NUM; i++) {
    aradall[i] = b[i];
  }
  for (i = 0; i < NUM; i++) {
    aradcrt[i] = aradall[i] / 100 % 10;
  }
  counting_sort(aradcrt, b, c, aradall);
  for (i = 0; i < NUM; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");
}