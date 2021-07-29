#include <stdio.h>
#include <stdlib.h>

typedef int DATATYPE;

struct CELL {
  struct CELL *next;
  DATATYPE data;
};

struct CELL *create(DATATYPE data) {
  struct CELL *p = (struct CELL *)malloc(sizeof(struct CELL));
  p->next = NULL;
  p->data = data;

  return p;
}

// mallocを用いずに宣言したローカル変数のアドレスは関数終了時にメモリ空間（スタック領域）から破棄されるので、
// アドレスを参照してもCELL構造体の値を参照することはできない
// struct CELL *create(DATATYPE data) {
//   struct CELL p;
//   p.next = NULL;
//   p.data = data;

//   return &p;
// }

int main() {
  struct CELL *cell1 = create(1);
  struct CELL *cell2 = create(2);
  struct CELL *cell3 = create(3);

  cell1->next = cell2;
  cell2->next = cell3;

  struct CELL *p;
  for (p = cell1; p != NULL; p = p->next) {
    printf("%d\n", p->data);
  }
  return 0;
}