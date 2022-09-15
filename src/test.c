#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"

void test_get_line() {
	Chunk chunk;
	init_chunk(&chunk);

	int constant = add_constant(&chunk, 1.2);
	write_chunk(&chunk, OP_CONSTANT, 1);
	write_chunk(&chunk, constant, 1);

	write_chunk(&chunk, OP_CONSTANT, 1);
	write_chunk(&chunk, constant, 1);

	write_chunk(&chunk, OP_CONSTANT, 2);
	write_chunk(&chunk, constant, 2);

	write_chunk(&chunk, OP_CONSTANT, 2);
	write_chunk(&chunk, constant, 2);

	write_chunk(&chunk, OP_CONSTANT, 3);
	write_chunk(&chunk, constant, 3);

	write_chunk(&chunk, OP_RETURN, 4);
	
	disassemble_chunk(&chunk, "test chunk");

	for (int i = 0; i < chunk.l_count; i++) 
		printf("index %d\tline %d\n", chunk.lines[i].index, chunk.lines[i].line);

	printf("%d\n", get_line(&chunk, 1)); // => 1 
	printf("%d\n", get_line(&chunk, 3)); // => 1 
	printf("%d\n", get_line(&chunk, 4)); // => 2
	printf("%d\n", get_line(&chunk, 7)); // => 2
	printf("%d\n", get_line(&chunk, 8)); // => 3
	printf("%d\n", get_line(&chunk, 9)); // => 3
	printf("%d\n", get_line(&chunk, 10)); // => 4

	free_chunk(&chunk);
}
