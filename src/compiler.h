#ifndef clox_compiler_h
#define clox_compiler_h

#include "chunk.h"
#include "object.h"

/// returns compiled top-level code
ObjFunction* compile(const char* source);

#endif
