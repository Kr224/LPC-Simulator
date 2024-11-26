#include <stdio.h>
#include "lpc.h"

int main() {
    int memory[SIZE] = {0}; //Initialize memory array to zero
    int accumulator = 0; //Holds the current working value
    int programCounter = 0; //Points to the next instruction
    int instructionReg = 0; //Current instruction
    int opCode = 0; //First two digits of instruction
    int operand = 0; //Last two digits of instruction
    int input;

    //Load Program into Memory
    while (1) {
        scanf("%d", &input);

        if (input == SENTINEL) {
            break; //End the input if -99999
        }

        //Valid instructions should be between MIN_VALUE and MAX_VALUE
        if (input < MIN_VALUE || input > MAX_VALUE) {
            printf("***ERROR - Invalid input, please enter a value between %d and %d\n", MIN_VALUE, MAX_VALUE);
            continue; //Skip this input and prompt again
        }

        memory[programCounter++] = input; //Store input in memory and increment program counter

    }

    //Reset programCounter for execution phase
    programCounter = 0;

    printf("***Start LPC Execution***\n");
    //Execution Loop
    while (1) {
        //Fetch next instruction
        instructionReg = memory[programCounter];
        opCode = instructionReg / 100; //Extract the first two digits for opCode
        operand = instructionReg % 100; //Extract the last two digits for operand

        //Increment program counter (except for jumps)
        programCounter ++;

        //Execute Operation based on opCode
        switch (opCode) {
            case READ: {
                //Read an integer and store it in the memory location specified by operand
                //printf("Enter a value: ");
                scanf("%d", &memory[operand]);
                break;
            }
            case WRITE: {
                //Write the value at memory location operand to output
                printf("Contents of %02d: %d\n", operand, memory[operand]);
                break;
            }
            case LOAD: {
                //Load value from memory[operand] into the accumulator
                accumulator = memory[operand];
                break;
            }
            case STORE: {
                // Store accumulator's value into memory[operand]
                memory[operand] = accumulator;
                break;
            }
            case ADD: {
                //Add memory[operand] to accumulator; check for overflow
                accumulator += memory[operand];
                if (accumulator > MAX_VALUE || accumulator < MIN_VALUE) {
                    printf("***FATAL ERROR - Accumulator overflow***\n");
                    goto memory_dump; // Jump to memory dump on fatal error
                }
                break;
            }
            case SUBTRACT: {
                //Subtract memory[operand] from accumulator, check for overflow
                accumulator -= memory[operand];
                if (accumulator > MAX_VALUE || accumulator < MIN_VALUE) {
                    printf("***FATAL ERROR - Accumulator overflow***\n");
                    goto memory_dump;
                }
                break;
            }
            case DIVIDE: {
                //Divide accumulator by memory[operand]; check for divide by zero
                if (memory[operand] == 0) {
                    printf("***FATAL ERROR - Attempt to divide by zero***\n");
                    goto memory_dump;
                }
                accumulator /= memory[operand];
                break;
            }
            case MULTIPLY: {
                //Multiply accumulator by memory[operand]; check for overflow
                accumulator *= memory[operand];
                if (accumulator > MAX_VALUE || accumulator < MIN_VALUE) {
                    printf("***FATAL ERROR - Accumulator overflow***\n");
                    goto memory_dump;
                }
                break;
            }
            case JUMP: {
                // Jump to the specified memory location (operand)
                programCounter = operand;
                break;
            }
            case JUMPNEG: {
                // Jump to operand if accumulator is negative
                if (accumulator < 0) {
                    programCounter = operand;
                }
                break;
            }
            case JUMPZERO: {
                // Jump to operand if accumulator is zero
                if (accumulator == 0) {
                    programCounter = operand;
                }
                break;
            }
            case HALT: {
                // Halt execution
                printf("***End LPC Execution***\n");
                goto end_execution;
            }

            default: {
                // Invalid opCode, trigger fatal error
                printf("***FATAL ERROR - Invalid opcode %d***\n", opCode);
                goto memory_dump;
            }
        }
    }

    memory_dump:
    //Print memory dump on fatal error
    printf("\n***MEMORY DUMP***\n");
    printf("Registers:\n");
    printf("Accumulator: %+05d\n", accumulator);
    printf("Program Counter: %02d\n", programCounter);
    printf("Instruction Register: %+05d\n", instructionReg);
    printf("Opcode: %02d\n", opCode);
    printf("Operand: %02d\n\n", operand);

    printf("Memory:\n");
    for (int i = 0; i < SIZE; i++) {
        if (i % 10 == 0) printf("\n%02d ", i);
        printf("%+05d ", memory[i]);
    }
    printf("\n");

    end_execution:
    return 0;
}