#include <stdio.h>
#include <stdlib.h>

typedef int KEY;

typedef struct node {
  KEY data;
  struct node *left;
  struct node *right;
} NODE;

int keyequal(KEY key1, KEY key2) { return key1 == key2; }
int keylt(KEY key1, KEY key2) { return key1 < key2; }

NODE *insert(NODE **p, KEY key) {
  NODE *new;
  while (*p != NULL) {
    if (keyequal(key, (*p)->data)) {
      return NULL;
    } else if (keylt(key, (*p)->data)) {
      p = &(*p)->left;
    } else {
      p = &(*p)->right;
    }
  }

  if ((new = (NODE *)malloc(sizeof(NODE))) == NULL) {
    printf("Out of memory\n");
    exit(1);
  }

  new->data = key;
  new->left = NULL;
  new->right = NULL;

  *p = new;
  return new;
}

NODE *deletemin(NODE **p) {
  NODE *x;
  while ((*p)->left != NULL) {
    p = &(*p)->left;
  }

  x = *p;
  *p = (*p)->right;
  return x;
}

int delete (NODE **p, KEY key) {
  NODE *x;
  while (*p != NULL) {
    if (keyequal(key, (*p)->data)) {
      x = *p;
      if (x->left == NULL && x->right == NULL) {
        *p = NULL;
      } else if (x->right == NULL) {
        *p = x->left;
      } else if (x->left == NULL) {
        *p = x->right;
      } else {
        *p = deletemin(&x->right);
        (*p)->right = x->right;
        (*p)->left = x->left;
      }
      free(x);
      return 1;
    } else if (keylt(key, (*p)->data)) {
      p = &(*p)->left;
    } else {
      p = &(*p)->right;
    }
  }
  return 0;
}

void inorder(NODE *p) {
  if (p == NULL) {
    return;
  }

  inorder(p->left);
  printf("%d ", p->data);
  inorder(p->right);
}

int main() {
  NODE *root = NULL;
  for (int i = 0; i < 10; i++) {
    insert(&root, i);
  }
  inorder(root);
  printf("\n");

  delete (&root, 3);
  inorder(root);
  printf("\n");

  return 0;
}