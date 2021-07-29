#include <stdio.h>

int convert(char *s) {
  int i, size;
  // size = sizeof(s); // 64bit環境だと8になる.
  for (i = 0; s[i] != '\0'; i++) {
    size++;
  }

  for (i = 0; i < size; i++) {
    if (('A' <= *s && *s <= 'M') || ('a' <= *s && *s <= 'm')) {
      *s += 13;
    } else if (('N' <= *s && *s <= 'Z') || ('n' <= *s && *s <= 'z')) {
      *s -= 13;
    }
    s++;
  }

  return size;
}

int main() {
  // char s* = "Osaka Univ."; ← メモリを連番で取ってくれない
  char s[] = "Osaka Univ.";
  int i = convert(s);
  printf("After: %s, NumChar: %d\n", s, i);

  return 0;
}
