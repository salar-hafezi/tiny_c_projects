#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256
#define LSIZE 100

void get_time_of_day(short hour, char *result) {
  if (hour < 12)
    result = "Morning";
  else if (hour < 17)
    result = "Afternoon";
  else
    result = "Evening";
}

short read_pithy(const char *file_name, char ***list_base) {
  FILE *fp;
  char buffer[BSIZE];
  char *r, *entry;
  short items;
  char **base;

  fp = fopen(file_name, "r");
  if (fp == NULL) {
    fprintf(stderr, "Unable to open file %s\n", file_name);
    exit(1);
  }
  items = 0;
  base = calloc(LSIZE, sizeof(char *));
  if (base == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    fclose(fp);
    exit(1);
  }
  while (fgets(buffer, BSIZE, fp) != NULL) {
    entry = calloc(strlen(buffer) + 1, sizeof(char));
    if (!entry) {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(1);
    }
    strcpy(entry, buffer);
    base[items++] = entry;
    if (items % LSIZE == 0) {
      char **temp = realloc(base, sizeof(char *) * (items + LSIZE));
      if (temp == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        fclose(fp);
        exit(1);
      }
      base = temp;
    }
  }
  fclose(fp);
  *list_base = base;
  return items;
}
