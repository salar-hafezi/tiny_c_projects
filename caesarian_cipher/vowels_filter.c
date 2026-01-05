#include <stdio.h>

int main(void) {
  int ch;

  while ((ch = getchar()) != EOF) {
    switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      putchar('*');
      break;
    default:
      putchar(ch);
    }
  }

  return 0;
}
