CC=/usr/pkg/bin/gcc
CFLAGS= -g -Wall -I.

all: io_bound cpu_bound mixed_bound

io_bound:
	$(CC) $(CFLAGS) io_bound.c -o io_bound

cpu_bound:
	$(CC) $(CFLAGS) cpu_bound.c -o cpu_bound

mixed_bound:
	$(CC) $(CFLAGS) mixed_bound.c -o mixed_bound

clean:
	rm io_bound cpu_bound mixed_bound
