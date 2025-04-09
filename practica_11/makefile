# Makefile para compilar el traductor trad2

trad2: trad2.tab.c
	gcc -o trad2 trad2.tab.c

trad2.tab.c trad2.tab.h: trad2.y
	bison -d trad2.y

clean:
	rm -f trad2 trad2.tab.c trad2.tab.h
