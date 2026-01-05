#include <ctype.h>
#include <stdio.h>

void rot13(int *ch);

int main(void) {
  int ch;

  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      rot13(&ch);
    }
    putchar(ch);
  }

  return 0;
}

void rot13(int *ch) {
  if (islower(*ch)) {
    *ch = 'a' + ((*ch - 'a' + 13)) % 26;
  } else if (isupper(*ch)) {
    *ch = 'A' + ((*ch - 'A' + 13)) % 26;
  }
}
