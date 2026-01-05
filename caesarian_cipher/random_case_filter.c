#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  time_t now;
  time(&now);
  srand((unsigned int)now);
  int ch;

  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      int chance = rand() % 2;
      if (chance == 0)
        putchar(toupper(ch));
      else
        putchar(tolower(ch));
    } else
      putchar(ch);
  }

  return 0;
}
