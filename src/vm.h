#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

typedef struct {
	// pointer to chunk.
	Chunk* chunk;
	// instruction pointer to opcode about to be executed. 
	uint8_t* ip; 
} VM;

typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROE,
} InterpretResult;

void init_vm();
void free_vm();
InterpretResult interpret(Chunk* chunk);

#endif
