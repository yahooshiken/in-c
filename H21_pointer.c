#include <stdio.h>

int main() {
  int i;
  int *dp;
  int data[8];

  dp = data;
  data[0] = 10;
  dp++;
  *dp = 20;
  dp += 4;
  *dp++ = 40;
  *++dp = 50;
  (*dp)++;

  for (i = 0; i < 8; i++) {
    printf("data[%d]=%d\n", i, data[i]);
  }

  printf("value of data=%06x\n", data); // 問題だと 0x001000 = 8
  printf("value of data=%06x\n", dp);   // 問題だと 0x010010 = 32
}
