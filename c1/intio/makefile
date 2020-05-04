CC=gcc
CFLAGS=-Wall -Werror

all: test intcpy

libintio.o: intio.c intio.h
	$(CC) $(CFLAGS) -c intio.c -o $@

test: test.c libintio.o
	$(CC) $(CFLAGS) $^ -o $@

intcpy: libintio.o intcpy.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o test intcpy
