#include <stdio.h>

void func(int data[], int head, int tail) {
  int pv, i, p, tmp;
  if (head >= tail) {
    return;
  }

  pv = data[head];
  for (p = head, i = head + 1; i <= tail; i++) {
    if (pv > data[i]) {
      p++;
      tmp = data[p];
      data[p] = data[i];
      data[i] = tmp;
    }
  }

  data[head] = data[p];
  data[p] = pv;
  func(data, head, p - 1);
  func(data, p + 1, tail);
}

int main() {
  const int n = 10;
  int arr[n] = {5, 7, 3, 4, 8, 1, 2, 9, 0, 6};

  func(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}