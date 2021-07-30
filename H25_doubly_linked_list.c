#include <stdio.h>
#include <stdlib.h>

struct CELL {
  struct CELL *next;
  struct CELL *prev;
  int data;
};

struct CELL *insert(struct CELL *x, int d) {
  struct CELL *p;

  if ((p = (struct CELL *)malloc(sizeof(struct CELL))) == NULL) {
    printf("Out of memory\n");
    exit(1);
  } else {
    p->data = d;
    p->prev = x;
    p->next = NULL;

    if (x != NULL) {
      p->next = x->next;
      x->next = p;
    }

    if (p->next != NULL) {
      p->next->prev = p;
    }
  }
  return p;
}

int main() {
  struct CELL *first = insert(NULL, 0);
  struct CELL *cell1 = insert(first, 1);
  struct CELL *cell2 = insert(cell1, 2);
  struct CELL *cell3 = insert(cell2, 3);
  struct CELL *cell4 = insert(first, 4);
  struct CELL *last = insert(cell3, 5);

  struct CELL *p = first;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
  p = last;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->prev;
  }
}