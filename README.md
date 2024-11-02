# Brainfk Interpreter and Text-to-Brainfk Converter

## Overview
This repository contains a C-based interpreter for the Brainfk programming language and a Python script that converts plain text into Brainfk code. The interpreter executes Brainfk code, allowing you to run Brainfk programs. The Python script efficiently translates each character of text to its Brainfk equivalent.

## Brainfk Interpreter (C)

### Code Explanation
The Brainfk interpreter processes a given Brainfk code string or reads from a file. It uses a dynamically allocated array of integers to represent the Brainfk memory tape and an integer pointer to navigate this tape.

The interpreter implements the following functionalities:
- **Memory Management**: It allocates an array of integers to simulate the memory used in Brainfk.
- **Command Execution**: It interprets Brainfk commands, including incrementing or decrementing memory cells, moving the pointer, and handling input and output.
- **Loop Handling**: It supports loops using the `[` and `]` commands, allowing for complex logic based on the value at the current memory pointer.

### Usage
To compile the interpreter, use a C compiler:
```bash
gcc -o bf_interpreter bf_interpreter.c
```

To run the interpreter with Brainfk code directly:
```bash
./bf_interpreter "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++."
```
Or to run it with a file containing Brainfk code:
```bash
./bf_interpreter -f code.bf
```

## Text to Brainfk Converter (Python)

### Code Explanation
The Python script translates each character of input text to Brainfk code using the `smallest_factors_with_adjustment` function, which computes the optimal factors for the ASCII values of characters.

Key features of the script include:
- **ASCII Conversion**: It converts each character to its ASCII value and finds factors to represent that value in Brainfk.
- **Efficient Code Generation**: It minimizes the size of the Brainfk code by using the smallest possible factors. If the ASCII value is prime, it considers factors of the value plus or minus one to find a better representation.
- **File Output**: The generated Brainfk code is saved in an `output.bf` file.

### Usage
Run the Python script to generate Brainfk code from text input:
```bash
python text_to_bf.py
```

When prompted, enter the text you want to convert. The script will create an `output.bf` file with the corresponding Brainfk code.

## Conclusion
This project provides a functional interpreter for the Brainfk programming language along with a tool to convert plain text into its Brainfk equivalent. The implementation is designed for efficiency and simplicity, allowing easy execution of Brainfk code and generation of Brainfk from text.


