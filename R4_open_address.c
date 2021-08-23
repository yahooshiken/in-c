#include <stdio.h>
#include <string.h>
#define AtoZ ('Z' - 'A' + 1)
#define HT_SIZE 10
#define NOISE_PARAM 100

struct {
  char name[4];
  int price;
} hash_table[HT_SIZE];

int hash(char *key) {
  unsigned long h = 0;
  h = (key[0] - 'A') + (key[1] - 'A') + (key[2] - 'A');
  return h % HT_SIZE;
}

int rehash(char *key) {
  unsigned long h = 0;
  h = (key[0] - 'A') * AtoZ * AtoZ + (key[1] - 'A') * AtoZ + (key[2] - 'A');
  return h * h / NOISE_PARAM % HT_SIZE;
}

int insert(char *key, int data) {
  int hash_value = hash(key);

  if (strcmp(hash_table[hash_value].name, "") == 0) {
    strcpy(hash_table[hash_value].name, key);
    hash_table[hash_value].price = data;
    return 1;
  }
  hash_value = rehash(key);
  if (strcmp(hash_table[hash_value].name, "") == 0) {
    strcpy(hash_table[hash_value].name, key);
    hash_table[hash_value].price = data;
    return 1;
  }

  while (hash_value < HT_SIZE) {
    hash_value++;
    if (strcmp(hash_table[hash_value].name, "") == 0) {
      strcpy(hash_table[hash_value].name, key);
      hash_table[hash_value].price = data;
      return 1;
    }
  }
  printf("Rehash Error.\n");
  return 0;
}

int main() {
  for (int i = 0; i < HT_SIZE; i++) {
    strcpy(hash_table[i].name, "");
    hash_table[i].price = 0;
  }

  insert("ACE", 100);
  insert("ACT", 200);
  insert("CAT", 300);

  for (int i = 0; i < HT_SIZE; i++) {
    printf("%d: %s %d\n", i, hash_table[i].name, hash_table[i].price);
  }

  return 0;
}