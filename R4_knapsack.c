#include <stdio.h>

int max_op(int a, int b) { return (a > b) ? a : b; }

int knap_sack(int i, int wu, int wt[], int val[]) {
  int result = 0;

  if (i == 0 || wu == 0) {
    result = 0;
  } else if (wt[i - 1] > wu) {
    result = knap_sack(i - 1, wu, wt, val);
  } else {
    result = max_op(knap_sack(i - 1, wu, wt, val),
                    val[i - 1] + knap_sack(i - 1, wu - wt[i - 1], wt, val));
  }

  printf("%d step: %d\n", i, result);
  return result;
}

int main() {
  int val[] = {6, 10, 12, 0};
  int wt[] = {1, 2, 3, 0};
  int wu = 5;

  int n = sizeof(val) / sizeof(val[0]) - 1;
  printf("Final result: %d\n", knap_sack(n, wu, wt, val));

  return 0;
}