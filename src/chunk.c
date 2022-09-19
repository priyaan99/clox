#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void init_chunk(Chunk* chunk) {
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
    chunk->l_count = 0;
    chunk->l_capacity = 0;
    chunk->lines = NULL;
    init_value_array(&chunk->constants);
}

void write_chunk(Chunk* chunk, uint8_t byte, int line) {
	if (chunk->capacity < chunk->count+1) {
		int old_capacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(old_capacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code,
				old_capacity, chunk->capacity);
	}

	chunk->code[chunk->count] = byte;
	chunk->count++;

    // Line
    if (chunk->l_capacity < chunk->l_count+1) {
        int old_capacity = chunk->l_capacity;
        chunk->l_capacity = GROW_CAPACITY(old_capacity);
        chunk->lines = GROW_ARRAY(Line, chunk->lines,
                old_capacity, chunk->l_capacity);
    }

    if (chunk->l_count == 0) {
        chunk->lines[chunk->l_count].line = line;
        chunk->lines[chunk->l_count].index = chunk->count-1;
        chunk->l_count++;
    } else {
        if (line != chunk->lines[chunk->l_count-1].line) {
            chunk->lines[chunk->l_count].line = line;
            chunk->lines[chunk->l_count].index = chunk->count-1;
            chunk->l_count++;
        }
    }
}

int get_line(Chunk* chunk, int index) {
    int line = 0;
    
    for (int i = 0; i < chunk->l_count; i++) 
    {
        if (index < chunk->lines[i].index) break;
        line = chunk->lines[i].line;
    }

    return line;
}

int add_constant(Chunk* chunk, Value value) {
    // returns address to value in constants array
    write_value_array(&chunk->constants, value);
    return chunk->constants.count - 1;
}

void free_chunk(Chunk* chunk) {
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	FREE_ARRAY(Line, chunk->lines, chunk->l_capacity);
    free_value_array(&chunk->constants);
	init_chunk(chunk);
}


