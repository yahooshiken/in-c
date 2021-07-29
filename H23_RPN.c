#include <ctype.h>
#include <stdio.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int size = 0;
char s[] = "23+45++";

void push(int val) {
  stack[size] = val;
  size++;
}

int pop() {
  size--;
  int val = stack[size];
  return val;
}

int main() {
  char c;
  int k = 0;
  int a, b;

  c = s[k];

  while (c != '\0') {
    if (isdigit(c)) {
      push(c - '0');
    } else {
      switch (c) {
      case '+':
        a = pop();
        b = pop();
        push(a + b);
        break;
      default:
        break;
      }
    }
    c = s[++k];
  }

  printf("Result: %d\n", pop());
}
