
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
double stack[STACKSIZE];
int i = 0;

int push(double d) {
  if (i >= STACKSIZE) {
    printf("Over\n");
    return -1;
  }

  stack[i] = d;
  i++;

  return i;
}

int pop(double *d) {
  if (i <= 0) {
    return -1;
  }

  i--;
  *d = stack[i];
  return i;
}

int main() {
  double *p = (double *)malloc(sizeof(double) * 3);

  assert(pop(p) == -1);

  assert(push(1.0) == 1);
  assert(push(2.0) == 2);
  assert(push(3.0) == 3);

  assert(pop(p) == 2);
  assert(pop(p + 1) == 1);
  assert(pop(p + 2) == 0);

  assert(*p == 3.0);
  assert(*(p + 1) == 2.0);
  assert(*(p + 2) == 1.0);

  for (int i = 0; i < STACKSIZE; i++) {
    push((double)i);
  }

  assert(push(1.0) == -1);
}