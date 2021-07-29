#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} NODE;

NODE *root = NULL;

NODE *erase2(NODE **p) {
  NODE *x;
  while ((*p)->right != NULL) {
    p = &(*p)->right;
  }
  x = *p;
  *p = (*p)->left;
  return x;
}

void erase(int key) {
  NODE **p, *x;
  p = &root;

  while (*p != NULL) {
    if (key == (*p)->data) {
      x = *p;
      if (x->left == NULL && x->right == NULL) {
        *p = NULL;
      } else if (x->right == NULL) {
        *p = x->left;
      } else if (x->left == NULL) {
        *p = x->right;
      } else {
        *p = erase2(&(*p)->left);
        (*p)->right = x->right;
        (*p)->left = x->left;
      }

      free(x);
    } else if (key < (*p)->data) {
      p = &(*p)->left;
    } else {
      p = &(*p)->right;
    }
  }
}

void insert(int key) {
  NODE **p, *n;
  p = &root;
  while (*p != NULL) {
    if (key == (*p)->data)
      return;
    else if (key < (*p)->data)
      p = &(*p)->left;
    else
      p = &(*p)->right;
  }

  n = (NODE *)malloc(sizeof(NODE));
  n->left = NULL;
  n->right = NULL;
  n->data = key;
  *p = n;
}

void order(NODE *p) {
  if (p == NULL)
    return;

  printf("%d, ", p->data);
  order(p->left);
  order(p->right);
}

int main(int argc, char const *argv[]) {
  int data[11] = {10, 5, 15, 3, 7, 13, 17, 6, 14, 16, 19};

  for (int i = 0; i < 11; i++) {
    insert(data[i]);
  }

  order(root);
  printf("\n");
  erase(10);
  order(root);
  printf("\n");

  return 1;
}
