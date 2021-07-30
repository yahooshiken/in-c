#include <stdio.h>

#define M 100

void func(unsigned int A[], unsigned int B[], int n) {
  int i;
  unsigned int C[M + 1];

  for (i = 0; i <= M; i++) {
    C[i] = 0;
  }

  for (i = 0; i < n; i++) {
    C[A[i]]++;
  }

  for (i = 0; i < M; i++) {
    C[i + 1] += C[i];
  }

  for (i = 0; i <= n - 1; i++) {
    // 安定ソートにするには、逆順にする
    // for (i = n - 1; i >= 0; i--) {
    B[--C[A[i]]] = A[i];
  }
}

int main() {
  unsigned int arrA[8] = {33, 12, 57, 31, 52, 76, 14, 21};
  unsigned int arrB[8];
  func(arrA, arrB, 8);

  for (int i = 0; i < 8; i++) {
    printf("%d ", arrB[i]);
  }
}
