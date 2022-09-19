#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

#define STACK_MAX 256

typedef struct {
	// pointer to chunk.
	Chunk* chunk;
	// instruction pointer to opcode about to be executed. 
	uint8_t* ip; 
	Value stack[STACK_MAX];
	Value* stack_top;
} VM;

typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROE,
} InterpretResult;

void init_vm();
void free_vm();
InterpretResult interpret(Chunk* chunk);
void push(Value value);
Value pop();

#endif
