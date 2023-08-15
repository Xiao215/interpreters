#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize){
    if (newSize == 0){
        free(pointer);
        return NULL;
    }

    // When oldSize is zero, realloc() is equivalent to calling malloc().
    void* result = realloc(pointer, newSize);

    // Allocation can fail if there isn't enough memory, and realloc will return NULL.
    if (result == NULL) exit(1);
    return result;
}