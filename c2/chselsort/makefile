CC=gcc
CFLAGS=-Wall
BIN=chselsort
OUTPUT=sorted.txt

all: $(BIN)

chselsort: chselsort.c
	$(CC) $(CFLAGS) $^ -o $@

sort: chselsort
	./$(BIN) input.txt $(OUTPUT)

clean:
	rm $(BIN) $(OUTPUT)
