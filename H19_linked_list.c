#include <stdio.h>
#include <stdlib.h>

struct CELL {
  double data;
  struct CELL *next;
  struct CELL *prev;
};

struct CELL *get_last(struct CELL *p) {
  struct CELL *x = p;
  while (x->next != NULL) {
    x = x->next;
  }
  return x;
}

struct CELL *insert(struct CELL *p, double d) {
  while (p != NULL && p->next != NULL) {
    p = p->next;
  }

  struct CELL *n = (struct CELL *)malloc(sizeof(struct CELL));
  if (p != NULL) {
    p->next = n;
  }
  n->data = d;
  n->next = NULL;
  n->prev = p;

  return n;
}

int main() {
  struct CELL *first = insert(NULL, 1.0);
  struct CELL *cell1 = insert(first, 2.0);
  struct CELL *cell2 = insert(cell1, 3.0);
  struct CELL *last = insert(cell2, 4.0);

  printf("%.1f \n", (get_last(first))->data);
  printf("%.1f \n", (get_last(cell1))->data);
  printf("%.1f \n", (get_last(cell2))->data);
  printf("%.1f \n", (get_last(last))->data);

  return 0;
}