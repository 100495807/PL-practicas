# Nombre del ejecutable final
TARGET = trad1e

# Archivos fuente generados
BISON_FILE = trad1e.y
BISON_C = trad1e.tab.c
BISON_H = trad1e.tab.h

LEX_FILE = trad1e.l
LEX_C = lex.yy.c

# Compilador y flags
CC = gcc
CFLAGS = -Wall

# Si tienes archivo .l con Flex:
ifdef USE_FLEX
all: $(TARGET)

$(TARGET): $(LEX_C) $(BISON_C)
	$(CC) $(CFLAGS) -o $@ $(LEX_C) $(BISON_C)

$(LEX_C): $(LEX_FILE)
	flex $(LEX_FILE)

$(BISON_C): $(BISON_FILE)
	bison -d $(BISON_FILE)
else
# Sin Flex (solo Bison)
all: $(TARGET)

$(TARGET): $(BISON_C)
	$(CC) $(CFLAGS) -o $@ $(BISON_C)

$(BISON_C): $(BISON_FILE)
	bison -d $(BISON_FILE)
endif

clean:
	rm -f $(TARGET) $(BISON_C) $(BISON_H) $(LEX_C)
