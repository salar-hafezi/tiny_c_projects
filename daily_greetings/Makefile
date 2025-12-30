CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11
LDFLAGS =
TARGET  = greetings
OBJS    = main.o moon_phases.o utils.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

main.o: main.c moon_phases.h utils.h
	$(CC) $(CFLAGS) -c main.c

moon_phases.o: moon_phases.c moon_phases.h
	$(CC) $(CFLAGS) -c moon_phases.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f $(OBJS) $(TARGET)
