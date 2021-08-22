#include <stdio.h>

int partition(int arr[], int l, int r) {

  int i = l - 1;
  int j = r;
  int pivot = arr[r];

  while (1) {
    while (arr[++i] < pivot)
      ;

    while (i < --j && pivot < arr[j])
      ;

    if (i >= j) {
      break;
    }

    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  int tmp = arr[i];
  arr[i] = arr[r];
  arr[r] = tmp;

  return i;
}

void quick_sort(int arr[], int n) {
  int sp = 1;
  int low[30], high[30];

  low[0] = 0;
  high[0] = n - 1;

  while (sp > 0) {
    sp--;
    int l = low[sp];
    int r = high[sp];

    if (l >= r)
      ;
    else {
      int v = partition(arr, l, r);
      if (v - l < r - v) {
        low[sp] = v + 1;
        high[sp] = r;
        sp++;
        low[sp] = l;
        high[sp] = v - 1;
        sp++;
      } else {
        low[sp] = l;
        high[sp] = v - 1;
        sp++;
        low[sp] = v + 1;
        high[sp] = r;
        sp++;
      }
    }
  }
}

int main() {
  const int n = 10;
  int arr[n] = {35, 17, 33, 89, 31, 163, 72, 90, 26, 21};
  quick_sort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}