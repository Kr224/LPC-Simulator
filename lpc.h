#ifndef A_3_LPC_H
#define A_3_LPC_H

// Input/Output Operations
#define READ 10        // Read from stdin to a specific memory location
#define WRITE 11       // Write from a specific location in memory to stdout

// Load/Store Operations
#define LOAD 20        // Load a word from a specific memory location into the accumulator
#define STORE 21       // Store a word from the accumulator into a specific memory location

// Arithmetic Operations
#define ADD 30         // Add a word from a memory location to the accumulator
#define SUBTRACT 31    // Subtract a word from a memory location from the accumulator
#define DIVIDE 32      // Divide the accumulator by a word from a memory location
#define MULTIPLY 33    // Multiply a word from memory with the accumulator

// Control Flow Operations
#define JUMP 40        // Jump to a specified memory location
#define JUMPNEG 41     // Jump if the accumulator value is negative
#define JUMPZERO 42    // Jump if the accumulator value is zero
#define HALT 43        // Halt the program

// Constants
#define SENTINEL -99999 // Sentinel value for end of input
#define TRUE 1
#define FALSE 0
#define SIZE 100       // Memory size (100 words)
#define MIN_VALUE -9999 // Minimum allowable value for accumulator and data
#define MAX_VALUE 9999  // Maximum allowable value for accumulator and data

#endif // A_3_LPC_H
