CC=gcc
CFLAGS=-Wall -Werror

all: test intcpy

libintio.o: intio.c intio.h
	$(CC) $(CFLAGS) -c intio.c

test:
	$(CC) $(FLAGS) test.c intio.o -o test.exe

intcpy:
	$(CC) $(CFLAGS) intio.c intcpy.c -o intcpy.exe

clean:
	rm -f *.o test.exe intcpy.exe
