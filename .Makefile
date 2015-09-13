cc = gcc
CFLAGS = -O2 -std=c89 -Wpedantic -Wall -Werror
bin = l2
lib = linklist
.PHONY: $(bin) clean

all: $(bin)
$(bin):	main.o linklist.o
	$(cc) -o $(bin) main.o linklist.o
main.o:	main.c
	$(cc) -c $(CFLAGS) -o main.o main.c

linklist.o:	linklist.c
	$(cc) -c $(CFLAGS) -o linklist.o linklist.c
clean:
	rm -f *.o $(bin) *.a *~
