#include "time_helper.h"
#include <time.h>

void current_time(char *now_str, short time_str_max_size) {
  time_t now;
  struct tm *clock;

  time(&now);
  clock = localtime(&now);
  strftime(now_str, time_str_max_size, "Today is %A, %B %d, %Y%nIt is %r%n",
           clock);
}
