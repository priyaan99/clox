#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "common.h"
#include "object.h"
#include "table.h"
#include "value.h"

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

/// Each time a function is called, we create one of these structs. 
/// Function calls are a core operation, so they need to be as fast as possible therefore statically acllocated

/// represent single ongoing function call
typedef struct {
	ObjFunction* function; // pointer to function being executed
	uint8_t* ip; // pointer to bytecode currently being executed
	Value* slots; // pointer to first local in vm value stack, a.k.a frame pointer
} CallFrame;

typedef struct {
	CallFrame frames[FRAMES_MAX];
	int frame_count;

	Value stack[STACK_MAX];
	Value* stack_top;
	Table globals;
	Table strings;
	Obj* objects;
} VM;

typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR,
} InterpretResult;

extern VM vm;

void init_vm();
void free_vm();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif
