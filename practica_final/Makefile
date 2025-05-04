# Makefile para compilar trad.y y back.y (frontend + backend)

# Compilador y flags
CC = gcc
CFLAGS = -Wall

# Archivos y ejecutables
TRAD_TARGET = trad
TRAD_BISON_FILE = trad.y
TRAD_BISON_C = trad.tab.c
TRAD_BISON_H = trad.tab.h

BACK_TARGET = back
BACK_BISON_FILE = back.y
BACK_BISON_C = back.tab.c
BACK_BISON_H = back.tab.h

# Regla principal
all: $(TRAD_TARGET) $(BACK_TARGET)

# Cómo construir trad
$(TRAD_TARGET): $(TRAD_BISON_C)
	$(CC) $(CFLAGS) -o $@ $(TRAD_BISON_C)

$(TRAD_BISON_C) $(TRAD_BISON_H): $(TRAD_BISON_FILE)
	bison -d $(TRAD_BISON_FILE)

# Cómo construir back
$(BACK_TARGET): $(BACK_BISON_C)
	$(CC) $(CFLAGS) -o $@ $(BACK_BISON_C)

$(BACK_BISON_C) $(BACK_BISON_H): $(BACK_BISON_FILE)
	bison -d $(BACK_BISON_FILE)

# Limpieza
clean:
	rm -f $(TRAD_TARGET) $(BACK_TARGET) \
	      $(TRAD_BISON_C) $(TRAD_BISON_H) \
	      $(BACK_BISON_C) $(BACK_BISON_H)
