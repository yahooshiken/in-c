#include <stdio.h>

void func(int a[], int s, int r);
int subfunc(int a[], int s, int r);

void func(int a[], int s, int r) {
  int v;
  if (s >= r) {
    return;
  }

  v = subfunc(a, s, r);
  func(a, s, v - 1);
  func(a, v + 1, r);
}

int subfunc(int a[], int s, int r) {
  int i, j, p, t;
  i = s - 1;
  j = r;
  p = a[r];

  while (1) {
    while (a[++i] < p)
      ;

    while (i < --j && p < a[j])
      ;

    if (i >= j)
      break;

    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  t = a[i];
  a[i] = a[r];
  a[r] = t;

  return i;
}

int main() {
  int arr[10] = {5, 7, 3, 4, 8, 1, 2, 9, 0, 6};

  func(arr, 0, 9);

  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}