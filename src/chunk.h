#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
	OP_CONSTANT,
	OP_NIL,
	OP_TRUE,
	OP_FALSE,
	OP_POP,
	OP_GET_LOCAL,
	OP_GET_GLOBAL,
	OP_DEFINE_GLOBAL,
	OP_SET_LOCAL,
	OP_SET_GLOBAL,
	OP_EQUAL,
	OP_GREATER,
	OP_LESS,
	OP_ADD,
	OP_SUBTRACT,
	OP_MULTIPLY,
	OP_DIVIDE,
	OP_NOT,
	OP_NEGATE,
	OP_PRINT,
	OP_JUMP,
	OP_JUMP_IF_FALSE,
	OP_LOOP,
	OP_RETURN,
} OpCode;

typedef struct {
	int index;
	int line;
} Line;

typedef struct {
	int count;
	int capacity;
	uint8_t* code;

	int l_count;
	int l_capacity;
	Line* lines;

	ValueArray constants;
} Chunk;

void init_chunk(Chunk* chunk);
void free_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte, int line);
int add_constant(Chunk* chunk, Value value);

int get_line(Chunk* chunk, int index);

#endif
