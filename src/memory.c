#include <stdlib.h>

#include "chunk.h"
#include "memory.h"
#include "object.h"
#include "vm.h"

void* reallocate(void* pointer, size_t old_size, size_t new_size) {
	if (new_size == 0) {
		free(pointer);
		return NULL;
	}

	void* result = realloc(pointer, new_size);
	if (result == NULL) exit(1);
	return result;
}

static void free_object(Obj* object) {
	switch (object->type) {
		case OBJ_STRING: {
			ObjString* string = (ObjString*)object;
			FREE_ARRAY(char, string->chars, string->length + 1);
			FREE(ObjString, object);
			break;
		}
		case OBJ_FUNCTION: {
			// cast Obj to ObjFunction as obj and obj function have pointer pointing to same location
			ObjFunction* function = (ObjFunction*)object;
			free_chunk(&function->chunk);
			FREE(ObjFunction, object);
			break;
		}
	}
}

void free_objects() {
	Obj* object = vm.objects;
	while (object != NULL) {
		Obj* next = object->next;
		free_object(object);
		object = next;
	}
}
