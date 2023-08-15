#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

// We grow the size of the array by a factor of 2, 1.5 is another common choice.

// Most dynamic array implementations have a minimum threshold like this (8). Selection depends on real-world usage.
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

// This will deal with four cases
// 1. oldSize = 0, newSize = None-zero, Allocate new block.
// 2. oldSize = None-zero, newSize = 0, Free allocation.
// 3. oldSize = Non-zero, newSize = Smaller, Shrink existing allocation.
// 4. oldSize = None-zero, newSize = Larger, Grow existing allocation.
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif