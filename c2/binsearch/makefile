CC=gcc
CFLAGS=-Wall -Werror

binsearch.o: binsearch.c
	$(CC) -c $(CFLAGS) $^ -o $@

binsearch_example: binsearch.o binsearch_example.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f binsearch.o binsearch_example
