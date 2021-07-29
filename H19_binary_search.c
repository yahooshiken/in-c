#include <assert.h>
#include <stdio.h>

int func(int data[], int head, int tail, int key) {
  int center = (head + tail) / 2;

  if (head > tail) {
    return -1;
  }

  else if (data[center] == key) {
    return center;
  }

  else if (data[center] > key) {
    return func(data, head, center - 1, key);
  }

  else {
    return func(data, center + 1, tail, key);
  }
}

int main() {
  const int n = 10;
  int arr[n] = {10, 34, 40, 52, 66, 89, 91, 103, 123};

  int found = func(arr, 0, n, 123);
  int notfound = func(arr, 0, n, 4);

  assert(found == 8);
  assert(notfound == -1);

  return 0;
}