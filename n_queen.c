#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0

#define FREE 1
#define NOT_FREE 0

#define N 8

int pos[N];
int col[N];
int down[2 * N - 1];
int up[2 * N - 1];

void init_board() {
  for (int i = 0; i < N; i++) {
    pos[i] = -1;
    col[i] = FREE;
  }
  for (int i = 0; i < 2 * N - 1; i++) {
    down[i] = FREE;
    up[i] = FREE;
  }
}

void show_queens() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (pos[i] == j) {
        printf("Q ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int try(int a) {
  for (int b = 0; b < N; b++) {
    if (col[b] == FREE && up[a + b] == FREE && down[a - b + (N - 1)] == FREE) {
      pos[a] = b;
      col[b] = NOT_FREE;
      up[a + b] = NOT_FREE;
      down[a - b + (N - 1)] = NOT_FREE;

      if (a + 1 >= N) {
        return SUCCESS;
      } else {
        if (try(a + 1) == SUCCESS) {
          return SUCCESS;
        } else {
          pos[a] = -1;
          col[b] = FREE;
          up[a + b] = FREE;
          down[a - b + (N - 1)] = FREE;
        }
      }
    }
  }
  return FAIL;
}

int count = 0;

void try_all(int a) {
  for (int b = 0; b < N; b++) {
    if (col[b] == FREE && up[a + b] == FREE && down[a - b + (N - 1)] == FREE) {
      pos[a] = b;
      col[b] = NOT_FREE;
      up[a + b] = NOT_FREE;
      down[a - b + (N - 1)] = NOT_FREE;

      if (a + 1 >= N) {
        printf("Answer %d\n", ++count);
        show_queens();
      } else {
        try_all(a + 1);
      }
      pos[a] = -1;
      col[b] = FREE;
      up[a + b] = FREE;
      down[a - b + (N - 1)] = FREE;
    }
  }
}

int main() {
  init_board();
  show_queens();
  if (try(0) == SUCCESS) {
    show_queens();
  }

  // try_all(0);

  return 0;
}