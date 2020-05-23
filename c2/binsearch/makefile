CC=gcc
CFLAGS=-Wall -Werror
BINS=binsearch_example binsearch_test

all: $(BINS)

binsearch.o: binsearch.c
	$(CC) -c $(CFLAGS) $^ -o $@

binsearch_example: binsearch.o binsearch_example.c
	$(CC) $(CFLAGS) $^ -o $@

binsearch_test: binsearch.o binsearch_test.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f binsearch.o $(BINS)
