SHELL := /bin/sh
CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
LDFLAGS = -lm
EXEC = mathlib-test
OBJS = mathlib-test.o bbp.o e.o euler.o madhava.o newton.o viete.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $(EXEC) $(OBJS)

mathlib-test.o: mathlib-test.c
	$(CC) $(CFLAGS) -c mathlib-test.c

bbp.o: bbp.c
	$(CC) $(CFLAGS) -c bbp.c

e.o: e.c
	$(CC) $(CFLAGS) -c e.c

euler.o: euler.c
	$(CC) $(CFLAGS) -c euler.c

madhava.o: madhava.c
	$(CC) $(CFLAGS) -c madhava.c

newton.o: newton.c
	$(CC) $(CFLAGS) -c newton.c

viete.o: viete.c
	$(CC) $(CFLAGS) -c viete.c

clean:
	rm -f $(EXEC) $(OBJS)

format:
	clang-format -i -style=file *.[ch]

scan-build: clean
	scan-build --use-cc=$(CC) make
