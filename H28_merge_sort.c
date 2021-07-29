#include <stdio.h>
#define MAX_ELEMENTS 1000

void merge_sort(int data[], int low, int high) {
  int mid, i, j, k;
  int tempdata[MAX_ELEMENTS];

  if (low >= high) {
    return;
  }

  mid = (low + high) / 2;
  merge_sort(data, low, mid);
  merge_sort(data, mid + 1, high);

  for (i = 0; i <= mid; i++) {
    tempdata[i] = data[i];
  }

  for (j = high, i = mid + 1; i <= high; i++, j--) {
    tempdata[i] = data[j];
  }

  i = low, j = high;

  for (k = low; k <= high; k++) {
    if (tempdata[i] < tempdata[j]) {
      data[k] = tempdata[i++];
    } else {
      data[k] = tempdata[j--];
    }
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {76, 34, 67, 32, 78, 45};
  merge_sort(arr, 0, 5);

  for (int i = 0; i < 6; i++) {
    printf("%d \n", arr[i]);
  }

  return 0;
}
