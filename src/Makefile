CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
OBJS=main.o chunk.o memory.o debug.o value.o vm.o compiler.o scanner.o object.o
NAME=clox

clox: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 

main.o: main.c common.h chunk.h debug.h vm.h
	$(CC) -c $< $(CFLAGS)
 
chunk.o: chunk.c chunk.h memory.h value.h common.h
	$(CC) -c $< $(CFLAGS)

memory.o: memory.c memory.h common.h
	$(CC) -c $< $(CFLAGS)

debug.o: debug.c debug.h chunk.h value.h
	$(CC) -c $< $(CFLAGS)

value.o: value.c value.h object.h memory.h value.h common.h 
	$(CC) -c $< $(CFLAGS)

vm.o: vm.c vm.h chunk.h common.h compiler.h debug.h object.h memory.h
	$(CC) -c $< $(CFLAGS)

compiler.o: compiler.c compiler.h chunk.h common.h scanner.h debug.h object.h
	$(CC) -c $< $(CFLAGS)

scanner.o: scanner.c scanner.h common.h
	$(CC) -c $< $(CFLAGS)

object.o: object.c object.h memory.h value.h vm.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm $(OBJS) $(NAME)
