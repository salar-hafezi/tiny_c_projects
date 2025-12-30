/*
 * Author: Salar Hafezi
 * Date: 2025-12-30
 * Purpose: A greeting generator with date-time & sayings
 */

#include "moon_phases.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  time_t now;
  struct tm *clock;
  short hour;
  char *time_of_day = NULL;
  char time_string[64];
  char *moon_phase = NULL;
  char **sayings = NULL;
  short count;
  int saying;

  const char file_name[] = "pithy.txt";
  time(&now);
  clock = localtime(&now);
  hour = clock->tm_hour;
  get_time_of_day(hour, time_of_day);
  strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);
  moon_phase = get_moon_phase_string(clock);

  if (argc < 2) {
    puts("Hello, you handsome beast!");
  } else {
    printf("Good %s, %s!\n", time_of_day, argv[1]);
  }
  puts(time_string);
  printf("The Moon is %s\n", moon_phase);
  count = read_pithy(file_name, &sayings);
  if (count == 0) {
    fprintf(stderr, "No sayings loaded\n");
    return 1;
  }
  srand((unsigned)time(NULL));
  saying = rand() % (count - 1);
  printf("%s", sayings[saying]);

  for (int i = 0; i < count; i++)
    free(sayings[i]);
  free(sayings);
  return 0;
}
