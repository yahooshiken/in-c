
#include <stdio.h>
#include <stdlib.h>

typedef int KEY;

typedef struct node {
  KEY data;
  struct node *left;
  struct node *right;
} NODE;

int keyequal(KEY a, KEY b) { return a == b; };
int keylt(KEY a, KEY b) { return a < b; };

NODE *insert(NODE *root, KEY key) {
  NODE **p;
  NODE *new;

  p = &root;
  while (*p != NULL) {
    if (keyequal(key, (*p)->data)) {
      return NULL;
    } else if (keylt(key, (*p)->data)) {
      p = &(*p)->left;
    } else {
      p = &(*p)->right;
    }
  }

  if ((new = malloc(sizeof(NODE))) == NULL) {
    printf("Error\n");
    exit(1);
  }

  new->left = NULL;
  new->right = NULL;
  new->data = key;
  *p = new;

  return new;
}

void order(NODE *n) {
  if (n == NULL) {
    return;
  }
  order(n->left);
  printf("%d ", n->data);
  order(n->right);
}

int main() {
  NODE root;
  root.left = NULL;
  root.right = NULL;
  root.data = 3;

  insert(&root, 5);
  insert(&root, 2);
  insert(&root, 1);
  insert(&root, 4);

  order(&root);
  return 0;
}