#include <stdio.h>
#include <stdlib.h>

int size[] = {2, 3, 5, 7, 9};
int value[] = {2, 4, 7, 11, 14};

#define N (sizeof(size) / sizeof(size[0]))

#define MAX_M 200

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Error\n");
  }

  int m = atoi(argv[1]);
  printf("Size of knapsack is %d\n", m);

  if (m >= MAX_M) {
    printf("Error\n");
  }

  int total[MAX_M];
  int choice[MAX_M];
  for (int i = 0; i <= m; i++) {
    total[i] = 0;
    choice[i] = -1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = size[i]; j <= m; j++) {
      int repack_total = total[j - size[i]] + value[i];

      if (repack_total > total[j]) {
        total[j] = repack_total;
        choice[j] = i;
      }
    }
  }

  for (int i = m; choice[i] >= 0; i -= size[choice[i]]) {
    printf("Item: %d (Value: %d, Size: %d) \n", choice[i], value[choice[i]],
           size[choice[i]]);
  }
  printf("Total value: %d \n", total[m]);

  return 0;
}
