#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum {
    OP_RETURN,
} OpCode;

typedef struct
{
    /*
    1. If the array have available space (count != capacity), just append the new number to that spot.

    2. Otherwise no space (count == capacity), allocate a new array with more capacity, copy the existing elements from old array to new, delete old array, update the new code pointer.*/

    /*
    Copying over entire old array makes the operation seems like O(n), however, amortized analysis shows that as long as we grow the array by a multiple of its current size, when we average out the cost of a sequence of appends, each append is O(1).*/

    // number of elements in array we have allocated
    int capacity;
    // number of elements in array actually in use
    int count;
    uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);


#endif