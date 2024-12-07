.PHONY: clean run

my_program: main.o lab1.o
	gcc  -Wall -Wextra -o my_program main.o lab1.o

main.o: main.c calc.h
	gcc -c main.c

lab1.o: calc.c calc.h
	gcc -c lab1.c

clean:
	rm -f main.o lab1.o my_program

run: my_program
	./my_program "$@"