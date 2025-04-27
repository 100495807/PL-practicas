# Makefile para compilar trad4.y y back4.y (frontend + backend)

# Compilador y flags
CC = gcc
CFLAGS = -Wall

# Archivos y ejecutables
TRAD_TARGET = trad4
TRAD_BISON_FILE = trad4.y
TRAD_BISON_C = trad4.tab.c
TRAD_BISON_H = trad4.tab.h

BACK_TARGET = back4
BACK_BISON_FILE = back4.y
BACK_BISON_C = back4.tab.c
BACK_BISON_H = back4.tab.h

# Regla principal
all: $(TRAD_TARGET) $(BACK_TARGET)

# Cómo construir trad4
$(TRAD_TARGET): $(TRAD_BISON_C)
	$(CC) $(CFLAGS) -o $@ $(TRAD_BISON_C)

$(TRAD_BISON_C) $(TRAD_BISON_H): $(TRAD_BISON_FILE)
	bison -d $(TRAD_BISON_FILE)

# Cómo construir back4
$(BACK_TARGET): $(BACK_BISON_C)
	$(CC) $(CFLAGS) -o $@ $(BACK_BISON_C)

$(BACK_BISON_C) $(BACK_BISON_H): $(BACK_BISON_FILE)
	bison -d $(BACK_BISON_FILE)

# Limpieza
clean:
	rm -f $(TRAD_TARGET) $(BACK_TARGET) \
	      $(TRAD_BISON_C) $(TRAD_BISON_H) \
	      $(BACK_BISON_C) $(BACK_BISON_H)
