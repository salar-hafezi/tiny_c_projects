greetings: moon_phases.o utils.o main.o
	gcc moon_phases.o utils.o main.o -o greetings
main.o: moon_phases.h moon_phases.c utils.h utils.c main.c
	gcc -c main.c -o main.o
moon_phases.o: moon_phases.h moon_phases.c
	gcc -c moon_phases.c -o moon_phases.o
utils.o: utils.h utils.c
	gcc -c utils.c -o utils.o
