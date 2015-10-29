cc = $(CC)
CFLAGS = -O2 -std=c89 -Wpedantic -Wall -Werror
bin = mem
lib = linklist
.PHONY: $(bin) clean

all:	$(bin)

$(bin):	main.o mem.o linklist.o
	$(cc) -o $(bin) main.o mem.o linklist.o


main.o:	main.c
	$(cc) -c $(CFLAGS) -o main.o main.c

mem.o:	mem.c
	$(cc) -c $(CFLAGS) -o mem.o mem.c

linklist.o:	linklist.c
	$(cc) -c $(CFLAGS) -o linklist.o linklist.c

clean:
	rm -f *.o $(bin) *.a *~
