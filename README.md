# C Preprocessor Implementation

## Project Overview
This project implements selected C preprocessor operations using C programming.

## Features
- **Comment Removal:** Handles comments in C source files.
- **Header Inclusion:** Includes header file contents in the preprocessed output.
- **Macro Replacement:** Replaces defined macros with their corresponding values.
- **Output Generation:** Generates a preprocessed output file with the `.i` extension.

## Technologies Used
- C Programming
- GCC Compiler
- Linux / Ubuntu
- Makefile
- Git and GitHub

## Project Structure
- `main.c` — Main program
- `comment_removal.c` — Comment removal module
- `header_inclusion.c` — Header inclusion module
- `macro_replacement.c` — Macro replacement module
- `Makefile` — Build configuration
- `test.c` — Test input

## Compilation
Run:

```bash
make
```

## Execution
Run:

```bash
./mypreprocessor test.c
```

Check your Makefile to confirm that the executable name is `mypreprocessor`.

## Learning Outcomes
- File handling in C
- String processing
- Pointers and dynamic memory allocation
- Modular programming
- Compilation and build automation

## Note
This is an educational implementation of selected preprocessor features, not a complete replacement for the standard C preprocessor.
