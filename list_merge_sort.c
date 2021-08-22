#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *merge(struct node *a, struct node *b) {
  struct node head;
  struct node *p = &head;

  while (a != NULL && b != NULL) {
    if (a->value <= b->value) {
      p->next = a;
      p = a;
      a = a->next;
    } else {
      p->next = b;
      p = b;
      b = b->next;
    }
  }

  if (a == NULL) {
    p->next = b;
  } else {
    p->next = a;
  }

  return head.next;
}

struct node *merge_sort(struct node *x) {
  if (x == NULL || x->next == NULL) {
    return x;
  }

  struct node *a = x, *b = x->next;

  if (b != NULL) {
    b = b->next;
  }

  while (b != NULL) {
    a = a->next;
    b = b->next;
    if (b != NULL) {
      b = b->next;
    }
  }

  struct node *p = a->next;
  a->next = NULL;

  return merge(merge_sort(x), merge_sort(p));
}

struct node *add(struct node *p, int value) {
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->value = value;
  new->next = NULL;

  if (p == NULL) {
    return new;
  }

  p->next = new;
  return new;
}

void print_list(struct node *x) {
  struct node *p = x;
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("\n");
}

int main() {
  struct node *root = add(NULL, 310);
  struct node *node_1 = add(root, 123);
  struct node *node_2 = add(node_1, 39);
  struct node *node_3 = add(node_2, 51);
  struct node *node_4 = add(node_3, 91);
  struct node *node_5 = add(node_4, 139);
  struct node *node_6 = add(node_5, 151);
  struct node *node_7 = add(node_6, 191);

  print_list(root);
  merge_sort(root);
  print_list(node_2);

  return 0;
}