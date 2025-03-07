CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = drLL.c
OBJ = drLL.o
EXEC = drLL

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
