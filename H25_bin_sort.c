#include <stdio.h>

#define M 100

void func(int A[], int n) {
  int i, j;
  int C[M + 1];

  for (i = 0; i <= M; i++) {
    C[i] = -1;
  }

  for (i = 0; i < n; i++) {
    C[A[i]] = A[i];
  }

  j = 0;
  for (i = 0; i <= M; i++) {
    if (C[i] != -1) {
      A[j++] = C[i];
    }
  }
}

int main() {
  int arr[8] = {33, 12, 57, 31, 52, 76, 14, 21};
  func(arr, 8);

  for (int i = 0; i < 8; i++) {
    printf("%d ", arr[i]);
  }
}
