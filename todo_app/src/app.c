#include "app.h"
#include "time_helper.h"
#include <stdio.h>
#include <stdlib.h>

#define TIME_STR_MAX_SIZE 64

void start_app(void) {
  // show current time
  char *now_str = calloc(TIME_STR_MAX_SIZE, sizeof(char));
  current_time(now_str, TIME_STR_MAX_SIZE);
  puts(now_str);
}
