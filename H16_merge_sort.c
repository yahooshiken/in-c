#include <stdio.h>

void sort(int *A, int low, int high, int *B) {
  int i, j, k;
  for (i = low; i <= high; ++i) {
    B[i] = A[i];
  }

  if (low >= high) {
    return;
  }

  sort(B, low, (low + high) / 2, A);
  sort(B, (low + high) / 2 + 1, high, A);

  i = j = low, k = (low + high) / 2 + 1;

  while (k <= high && j <= (low + high) / 2) {
    if (A[j] < A[k]) {
      B[i++] = A[j++];
    } else {
      B[i++] = A[k++];
    }
  }

  while (k <= high) {
    B[i++] = A[k++];
  }
  while (j <= (low + high) / 2) {
    B[i++] = A[j++];
  }
}

int main() {
  const int n = 10;
  int arrA[n] = {5, 7, 3, 4, 8, 1, 2, 9, 0, 6};
  int arrB[n];
  sort(arrA, 0, n - 1, arrB);

  for (int i = 0; i < n; i++) {
    printf("%d ", arrB[i]);
  }
}