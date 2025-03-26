EXEC = calc8
BISON_FILE = calc8.y
BISON_C = calc8.c  # cambia nombre aquí para evitar confusión con .tab.h
CC = gcc
CFLAGS = -lm

all: $(EXEC)

$(EXEC): $(BISON_C)
	$(CC) -o $(EXEC) $(BISON_C) $(CFLAGS)

$(BISON_C): $(BISON_FILE)
	bison $(BISON_FILE) -o $(BISON_C)

clean:
	rm -f $(EXEC) calc8.c
