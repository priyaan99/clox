CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
OBJS=main.o chunk.o memory.o debug.o value.o
NAME=clox

clox: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 

main.o: main.c common.h chunk.h debug.h 
	$(CC) -c $< $(CFLAGS)
 
chunk.o: chunk.c chunk.h memory.h value.h
	$(CC) -c $< $(CFLAGS)

memory.o: memory.c memory.h
	$(CC) -c $< $(CFLAGS)

debug.o: debug.c debug.h chunk.h value.h
	$(CC) -c $< $(CFLAGS)

value.o: value.c value.h memory.h common.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm $(OBJS) $(NAME)
