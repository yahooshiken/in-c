#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 20

typedef struct data {
  int age;
  char name[100];
} data;

typedef struct node {
  char *key;
  data details;
  struct node *next;
} node;

node *htable[HT_SIZE];

int hash(char key[]) {
  int i = 0;
  while (*key) {
    i += *key++;
  }
  return i % HT_SIZE;
}

int keyequal(char key1[], char key2[]) {
  int lk1 = strlen(key1);
  int lk2 = strlen(key2);

  if (lk1 != lk2) {
    return 0;
  }
  for (int i = 0; i < lk1; i++) {
    if (key1[i] != key2[i]) {
      return 0;
    }
  }
  return 1;
}

void init_htable() {
  for (int i = 0; i < HT_SIZE; i++) {
    htable[i] = NULL;
  }
}

void show_htable() {
  for (int i = 0; i < HT_SIZE; i++) {
    if (htable[i] != NULL) {
      node *p = htable[i];
      printf("%d: ", i);
      while (p != NULL) {
        printf("%d %s->", p->details.age, p->details.name);
        p = p->next;
      }
      printf("\n");
    }
  }
}

data *find(char key[]) {
  for (node *p = htable[hash(key)]; p != NULL; p = p->next) {
    if (keyequal(key, p->key)) {
      return &(p->details);
    }
  }
  return NULL;
}

int insert(char key[], data *details) {
  node *p;
  int h;
  if (find(key) != NULL) {
    return 0;
  }
  if ((p = (node *)malloc(sizeof(node))) == NULL) {
    fprintf(stderr, "Out of memory\n");
    exit(2);
  }

  p->key = key;
  p->details = *details;

  h = hash(key);
  p->next = htable[h];
  htable[h] = p;

  return 1;
}

int delete (char key[]) {
  int h = hash(key);
  if (htable[h] == NULL) {
    return 0;
  }
  node *p, *q;
  if (keyequal(key, htable[h]->key)) {
    p = htable[h];
    htable[h] = p->next;
    free(p);
    return 1;
  }
  for (q = htable[h], p = q->next; p != NULL; q = p, p = p->next) {
    if (keyequal(key, p->key)) {
      q->next = p->next;
      free(p);
      return 1;
    }
  }
  return 0;
}

int main() {
  init_htable();
  data a = {20, "Handai"};
  insert("s12", &a);
  data b = {21, "Kyodai"};
  insert("s13", &b);
  data c = {22, "Todai"};
  insert("s22", &c);
  data *d = find("s13");

  if (d != NULL) {
    printf("Find result\n");
    printf("%d %s\n\n", d->age, d->name);
  }

  printf("Before delete\n");
  show_htable();
  delete ("s13");
  printf("After delete\n");
  show_htable();

  return 0;
}