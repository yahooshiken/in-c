
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
double stack[STACKSIZE];
int i = 0;

double push(double d) {
  if (i >= STACKSIZE - 1) {
    return -1;
  }

  stack[i] = d;
  i++;

  return d;
}

double pop(double *d) {
  if (i <= 0) {
    return -1;
  }

  i--;
  double val = stack[i];
  *d = val;
  return val;
}

int main() {
  double *p = (double *)malloc(sizeof(double) * 3);

  assert(pop(p) == -1);

  assert(push(1.0) == 1.0);
  assert(push(2.0) == 2.0);
  assert(push(3.0) == 3.0);

  assert(pop(p) == 3.0);
  assert(pop(p + 1) == 2.0);
  assert(pop(p + 2) == 1.0);

  assert(*p == 3.0);
  assert(*(p + 1) == 2.0);
  assert(*(p + 2) == 1.0);

  for (int i = 0; i < STACKSIZE; i++) {
    push((double)i);
  }

  assert(push(1.0) == -1);
}