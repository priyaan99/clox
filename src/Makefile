CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
OBJS=main.o chunk.o memory.o
NAME=clox

clox: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

main.o: main.c common.h
	$(CC) -c $< $(CFLAGS)

chunk.o: chunk.c chunk.h memory.h
	$(CC) -c $< $(CFLAGS)

memory.o: memory.c memory.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm $(OBJS) $(NAME)
