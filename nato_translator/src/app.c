#include "app.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *nato[] = {
    "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
    "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
    "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
    "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

void start_app(char *mode, char *file_name) {
  if (strcmp(mode, "encode") == 0) {
    encode(file_name);
    return;
  }
  if (strcmp(mode, "decode") == 0) {
    decode(file_name);
    return;
  }
  fprintf(stderr, "Invalid mode '%s'.\n", mode);
  exit(1);
}
void encode(char *file_name) {
  char ch;
  FILE *fp;
  fp = fopen(file_name, "r");
  if (!fp) {
    fprintf(stderr, "Unable to open '%s'.\n", file_name);
    exit(1);
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isalpha(ch)) {
      printf("%s ", nato[toupper(ch) - 'A']);
    }
  }
  putchar('\n');
  fclose(fp);
}
void decode(char *file_name) {
  char buf[64];
  char *match;
  char ch;
  FILE *fp;
  fp = fopen(file_name, "r");
  if (!fp) {
    fprintf(stderr, "Unable to open '%s'.\n", file_name);
    exit(1);
  }
  while (!feof(fp)) {
    fgets(buf, 64, fp);
    match = strtok(buf, " ,.!?:;\"'");
    while (match) {
      if ((ch = is_term(match)))
        putchar(ch);
      match = strtok(NULL, " ,.!?:;\"'");
    }
  }
  putchar('\n');
}
char is_term(char *term) {
  int x;
  char *n, *t;
  for (x = 0; x < 26; x++) {
    n = (char *)nato[x];
    t = term;
    while (*n != '\0') {
      if ((*n | 0x20) != (*t | 0x20))
        break;
      n++;
      t++;
    }
    if (*n == '\0')
      return *nato[x];
  }
  return '\0';
}
