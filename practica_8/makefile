# Nombre del ejecutable
EXEC = calc7

# Archivos fuente generados por Bison
BISON_FILE = calc7.y
BISON_C = calc7.tab.c
BISON_H = calc7.tab.h

# Compilador y banderas
CC = gcc
CFLAGS = -lm

# Reglas de compilación
all: $(EXEC)

$(EXEC): $(BISON_C)
	$(CC) -o $(EXEC) $(BISON_C) $(CFLAGS)

$(BISON_C): $(BISON_FILE)
	bison -d $(BISON_FILE) -o $(BISON_C)

clean:
	rm -f $(EXEC) $(BISON_C) $(BISON_H)
