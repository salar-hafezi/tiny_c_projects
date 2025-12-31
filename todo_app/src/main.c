/*
 * Author: Salar Hafezi
 * Date: 2025-12-31
 * Purpose: A simple todo app using file system for permanent storage
 */
#include "app.h"
#include <stdbool.h>
#include <stdlib.h>

#define BUF_SIZE 256
const char *file_name = "todos.txt";
bool is_app_running = true;
short todos_count = 0;
char **todos = NULL;

int main(void) {
  start_app();
  return 0;
}
