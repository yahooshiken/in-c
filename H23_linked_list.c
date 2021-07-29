
#include <stdio.h>
#include <stdlib.h>

struct CELL {
  int value;
  struct CELL *next;
};

struct CELL *insert(struct CELL *x, int val) {
  struct CELL *p;
  p = (struct CELL *)malloc(sizeof(struct CELL));

  p->value = val;
  p->next = NULL;
  x->next = p;

  return p;
}

int main() {
  struct CELL *root = (struct CELL *)malloc(sizeof(struct CELL));
  root->value = 0;
  root->next = NULL;

  struct CELL *cell1 = insert(root, 1);
  struct CELL *cell2 = insert(cell1, 2);
  struct CELL *cell3 = insert(cell2, 3);

  struct CELL *p = root;
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}