#include <stdio.h>

#define MAX_HEAP 1000

int arr[MAX_HEAP + 1];

int n = 0;

void down_heap(int from, int to) {
  int val = arr[from];

  int i = from;
  while (i <= to / 2) {
    int j = i * 2;
    if (j + 1 <= to && arr[j] > arr[j + 1]) {
      j++;
    }

    if (val <= arr[j]) {
      break;
    }

    arr[i] = arr[j];
    i = j;
  }

  arr[i] = val;
}

void swap(int *arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void heap_sort() {
  for (int i = n / 2; i >= 1; i--) {
    down_heap(i, n);
  }

  for (int i = n; i >= 2; i--) {
    swap(arr, 1, i);
    down_heap(1, i - 1);
  }
}

void show_arr(int arr[], int size) {
  for (int i = 1; i <= size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  n = 10;

  arr[1] = 29;
  arr[2] = 69;
  arr[3] = 93;
  arr[4] = 52;
  arr[5] = 33;
  arr[6] = 3;
  arr[7] = 17;
  arr[8] = 24;
  arr[9] = 81;
  arr[10] = 42;

  show_arr(arr, n);
  heap_sort();
  show_arr(arr, n);

  return 0;
}