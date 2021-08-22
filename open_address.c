#include <stdio.h>
#include <stdlib.h>

typedef int KEY;
typedef int DATA;

#define EMPTY (KEY)0
#define DELETED (KEY)1

#define BUCKET_SIZE 100

typedef struct bucket {
  KEY key;
  DATA data;
} BUCKET;

BUCKET table[BUCKET_SIZE];

int keyequal(KEY a, KEY b) { return a == b; }

int hash(int h) { return h % BUCKET_SIZE; }

int rehash(int h) { return (h + 1) % BUCKET_SIZE; }

void init() {
  for (int i = 0; i < BUCKET_SIZE; i++) {
    table[i].key = EMPTY;
  }
}

void show_table() {
  printf("=== SHOW TABLE ===\n");
  for (int i = 0; i < BUCKET_SIZE; i++) {
    if (table[i].key == DELETED) {
      printf("%d is deleted.\n", i);

    } else if (table[i].key != EMPTY) {
      printf("%d is not empty.\n", i);
    }
  }
}

DATA *find(KEY key) {
  int hashedKey, count;
  KEY k;

  count = 0;
  hashedKey = hash(key);
  while ((k = table[hashedKey].key) != EMPTY) {
    if (k != DELETED && keyequal(key, k)) {
      return &table[hashedKey].data;
    }
    if (++count > BUCKET_SIZE) {
      return NULL;
    }

    hashedKey = rehash(hashedKey);
  }
  return NULL;
}

int insert(KEY key, DATA *data) {
  int hashedKey, count;
  KEY k;

  count = 0;
  hashedKey = hash(key);
  while ((k = table[hashedKey].key) != EMPTY && k != DELETED) {
    if (keyequal(key, k)) {
      return 0;
    }
    if (++count > BUCKET_SIZE) {
      fprintf(stderr, "hash table overflow\n");
      exit(1);
    }
    hashedKey = rehash(hashedKey);
  }

  table[hashedKey].key = key;
  table[hashedKey].data = *data;
  return 1;
}

int delete (KEY key) {
  int hashedKey, count;
  KEY k;

  count = 0;
  hashedKey = hash(key);
  while ((k = table[hashedKey].key) != EMPTY) {
    if (k != DELETED && keyequal(key, k)) {
      table[hashedKey].key = DELETED;
      return 1;
    }

    if (++count > BUCKET_SIZE) {
      return 0;
    }

    hashedKey = rehash(hashedKey);
  }

  return 0;
}

int main() {

  DATA arr[] = {3, 4};

  init();
  show_table();

  insert(5, arr);
  insert(105, arr);
  insert(17, arr);
  insert(117, arr);
  insert(10017, arr);
  insert(21, arr);
  insert(121, arr);
  insert(50, arr);
  show_table();

  delete (17);
  delete (21);
  delete (22);
  delete (5);
  show_table();

  insert(5, arr);
  show_table();

  return 0;
}