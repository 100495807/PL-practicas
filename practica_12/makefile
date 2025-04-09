# Makefile para compilar el traductor trad3

trad3: trad3.tab.c
	gcc -o trad3 trad3.tab.c

trad3.tab.c trad3.tab.h: trad3.y
	bison -d trad3.y

clean:
	rm -f trad3 trad3.tab.c trad3.tab.h
