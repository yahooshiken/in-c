#include <stdio.h>

#define M 64
#define MASK 0x3f

void sort(unsigned int A[], unsigned int B[], int n) {
  int i, bit;
  int C[M];

  for (bit = 0; bit < 32; bit += 6) {
    for (i = 0; i < M; ++i) {
      C[i] = 0;
    }
    for (i = 0; i < n; ++i) {
      ++C[(A[i] >> bit) & MASK];
    }

    for (i = 1; i < M; ++i) {
      C[i] += C[i - 1];
    }

    for (i = n - 1; i >= 0; --i) {
      B[--C[(A[i] >> bit) & MASK]] = A[i];
    }

    for (i = 0; i < n; i++) {
      A[i] = B[i];
    }
  }
}

int main() {
  const int n = 6;
  unsigned int arrA[n] = {1234, 9876, 3456, 5645, 9257, 2368, 3432};
  unsigned int arrB[n];
  sort(arrA, arrB, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arrA[i]);
  }
}