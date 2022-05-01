CC=gcc
BINARY=kitchen

LIB=-pthread
INCLUDE=

%: %.c
		$(CC) -o $@ $< $(LIB)

all:    $(BINARY)

clean:
		rm -f *.o $(BINARY)