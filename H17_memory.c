#include <stdio.h>

int main() {
  int char_size = sizeof(char);
  int pointer_size = sizeof(char *); // 過去問だと4バイト

  printf("char size: %d\n", char_size);
  printf("pointer size: %d\n", pointer_size);

  char a[10];
  char *b[10];
  char(*c)[10];

  printf("char a[10]: %lu\n", sizeof(a));
  printf("char *b[10]: %lu\n", sizeof(b));
  printf("char (*c)[10]: %lu\n", sizeof(c) + sizeof(*c));
}