#include <time.h>

char *phase[8] = {
    "waxing crescent", "at first quarter", "waxing gibbous",  "full",
    "waning gibbous",  "at last quarter",  "waning crescent", "new"};

short get_moon_phase_number(int year, int month, int day) {
  int d, g, e;
  d = day;
  if (month == 2)
    d += 31;
  else if (month > 2)
    d += 59 + (month - 3) * 30.6 + 0.5;
  g = (year - 1900) % 19;
  e = (11 * g + 29) % 30;
  if (e == 25 || e == 24)
    ++e;
  return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}

char *get_moon_phase_string(struct tm *clock) {
  short moon_phase_number = get_moon_phase_number(
      clock->tm_year + 1900, clock->tm_mon, clock->tm_mday);
  return phase[moon_phase_number];
}
