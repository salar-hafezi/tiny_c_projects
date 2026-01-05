/*
 * Author: Salar Hafezi
 * Date: 2026-01-05
 * Purpose: A simple app to translate NATO words
 */

#include "app.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Please supply mode and text file arguments.\n");
    exit(1);
  }
  start_app(argv[1], argv[2]);
  return 0;
}
