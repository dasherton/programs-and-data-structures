CC=gcc
CFLAGS=-Wall -Werror
BINS=test intcpy intcpy_

all: $(BINS)

libintio.o: intio.c intio.h
	$(CC) $(CFLAGS) -c intio.c -o $@

libintio.so: intio.c intio.h
	$(CC) $(CFLAGS) -shared -fPIC intio.c -o $@

test: test.c libintio.o
	$(CC) $(CFLAGS) $^ -o $@

intcpy: libintio.o intcpy.c
	$(CC) $(CFLAGS) $^ -o $@

intcpy_: intcpy.c libintio.so
	$(CC) $(GCC) $^ -L. -lintio -o $@

clean:
	rm -f *.o *.so $(BINS)
