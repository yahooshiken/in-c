#include <stdio.h>

int arr[10] = {5, 7, 3, 4, 8, 1, 2, 9, 0, 6};

int *func(int *sp, int *ep) {
  int *ip, *jp, pv, temp;
  ip = sp;
  jp = ep;

  pv = *jp;

  while (1) {
    while (*ip++ < pv)
      ;

    ip--;
    while (ip < --jp && pv < *jp)
      ;

    if (ip >= jp)
      break;

    temp = *ip;
    *ip = *jp;
    *jp = temp;

    ip++;
  }

  temp = *ip;
  *ip = *ep;
  *ep = temp;

  printf("        ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return ip;
}

void sort(int *sp, int *ep) {
  int *vp;

  vp = func(sp, ep);

  if (sp < vp - 1) {
    sort(sp, vp - 1);
  }

  if (vp + 1 < ep) {
    sort(vp + 1, ep);
  }
}

int main() {

  printf("Before: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  sort(&arr[0], &arr[9]);

  printf("After:  ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}