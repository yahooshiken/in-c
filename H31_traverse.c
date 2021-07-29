#include <stdio.h>
#include <stdlib.h>

struct binarytree {
  char data;
  struct binarytree *lchild;
  struct binarytree *rchild;
};

typedef struct binarytree btree;
typedef struct binarytree *pbtree;

void create_binary_tree(pbtree *t) {
  char chin;
  while (1) {
    scanf("%c", &chin);
    if (chin >= 'A' && chin <= 'Z') {
      break;
    }

    if (chin == '#') {
      *t = NULL;
      return;
    }
  }

  *t = (pbtree)malloc(sizeof(btree));
  if (!*t) {
    printf("Error");
    exit(1);
  }
  (*t)->data = chin;
  create_binary_tree(&((*t)->lchild));
  create_binary_tree(&((*t)->rchild));
}

#define STACK_SIZE 4

struct stack {
  pbtree *top;
  pbtree *base;
  int stacksize;
};

typedef struct stack btreestack;
typedef struct stack *pbtreestack;

void init_stack(pbtreestack s) {
  s->base = (pbtree *)malloc(STACK_SIZE * sizeof(pbtree));
  if (!s->base) {
    printf("Error");
    exit(1);
  }

  s->top = s->base;
  s->stacksize = STACK_SIZE;
}

void push_stack(pbtreestack s, pbtree e) {
  if (s->top - s->base >= s->stacksize) {
    printf("Error");
    exit(1);
  }
  s->top++;
  *(s->top) = e;
  // *(s->top++) = e;
}

pbtree pop_stack(pbtreestack s) {
  if (s->top == s->base) {
    printf("Error");
  }
  pbtree e = *(s->top);
  s->top--;
  return e;
  // return *(--(s->top));
}

int is_empty_stack(pbtreestack s) {
  if (s->top == s->base) {
    return 1;
  }
  return 0;
}

void preorder_loop_traverse(pbtree t) {
  pbtree p = t;
  btreestack s;
  init_stack(&s);
  while (p || !is_empty_stack(&s)) {
    if (p) {
      printf("%c", p->data);
      push_stack(&s, p);
      p = p->lchild;
    } else {
      p = pop_stack(&s);
      p = p->rchild;
    }
  }
}

int main() {
  pbtree t = NULL;
  create_binary_tree(&t);
  preorder_loop_traverse(t);
  return 0;
}
