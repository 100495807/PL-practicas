# Makefile para compilar el traductor trad1

trad1: trad1.tab.c
	gcc -o trad1 trad1.tab.c

trad1.tab.c trad1.tab.h: trad1.y
	bison -d trad1.y

clean:
	rm -f trad1 trad1.tab.c trad1.tab.h
