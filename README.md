# LPC Simulator

A simulation program for the **Little Person Computer (LPC)**, built in C, to emulate its operations and execute programs written in the **Little Person Language (LPL)**.

## Features
- Simulates a 100-word memory system.
- Executes operations such as:
  - Arithmetic (`ADD`, `SUBTRACT`, `MULTIPLY`, `DIVIDE`)
  - Control flow (`JUMP`, `JUMPNEG`, `JUMPZERO`, `HALT`)
  - Input/Output (`READ`, `WRITE`)
- Provides error handling for:
  - Invalid instructions
  - Division by zero
  - Accumulator overflow
- Outputs detailed memory dumps on fatal errors.

## Project Details
This program was developed as part of an academic assignment to build a software-based simulator for the **Little Person Computer**. The LPC is a simplified virtual computer model with:
- An accumulator register for computations.
- A 4-bit signed decimal word size.
- A set of operations defined in the Little Person Language (LPL).

## How It Works
1. **Instruction Format**:
   - Each instruction is a 4-digit word, consisting of:
     - **Opcode**: The first two digits specifying the operation.
     - **Operand**: The last two digits specifying the memory address.
   - Example: `2010` represents `LOAD` operation from memory location `10`.

2. **Execution Process**:
   - The program initializes special registers (Accumulator, Program Counter, etc.).
   - Loads an LPC program into memory.
   - Executes instructions sequentially or based on control flow.

3. **Error Handling**:
   - Invalid opcodes trigger an error with a memory dump.
   - Division by zero halts execution with an error message.
   - Accumulator overflow is detected and flagged.

## Requirements
- **C Compiler** (e.g., GCC or Clang)
- Linux, macOS, or Windows with a terminal/command prompt.

## Installation and Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/Kr224/LPC-Simulator.git
   cd LPC-Simulator

