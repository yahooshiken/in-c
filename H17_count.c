#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dt {
  char *str;
  struct dt *left;
  struct dt *right;
  int cnt;
};

struct dt *dataAdd(struct dt *p, char *s) {
  int cmp;

  if (p == NULL) {
    p = (struct dt *)malloc(sizeof(struct dt));
    p->str = (char *)malloc(strlen(s) + 1);
    strcpy(p->str, s);
    p->left = NULL;
    p->right = NULL;
    p->cnt = 1;
  } else {
    cmp = strcmp(s, p->str);
    if (cmp == 0) {
      p->cnt++;
    } else if (cmp > 0) {
      p->right = dataAdd(p->right, s);
    } else {
      p->left = dataAdd(p->left, s);
    }
  }

  return p;
}

void dataPrint(struct dt *p) {
  if (p == NULL) {
    return;
  }

  dataPrint(p->left);
  printf("%d: %s", p->cnt, p->str);
  dataPrint(p->right);
}

int main() {
  char str[200];
  struct dt *p = NULL;
  while (fgets(str, 200, stdin) != NULL) {
    p = dataAdd(p, str);
  }

  dataPrint(p);
  return 0;
}
