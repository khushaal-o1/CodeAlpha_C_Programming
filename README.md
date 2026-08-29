# CodeAlpha C Programming Internship Projects

This repository contains two console applications developed in C for the CodeAlpha C Programming Internship.

## Projects

### Task 1 — Calculator

An interactive calculator supporting:

- Addition, subtraction, multiplication, and division
- Division-by-zero protection
- Validation for menu choices and numeric input
- A menu loop that runs until the user chooses to exit

Source: [`Task-1-Calculator/calculator.c`](Task-1-Calculator/calculator.c)

### Task 2 — Matrix Operations

An interactive matrix program supporting:

- Addition of two matrices with matching dimensions
- Multiplication of compatible matrices
- Matrix transposition
- Validation for matrix dimensions and values
- Matrices from 1×1 up to 10×10

Source: [`Task-2-Matrix-Operations/matrix_operations.c`](Task-2-Matrix-Operations/matrix_operations.c)

## Requirements

- A C compiler such as GCC, Clang, or MSVC
- A terminal or command prompt

## Build and Run

### Calculator

```bash
gcc -std=c11 -Wall -Wextra -pedantic Task-1-Calculator/calculator.c -o calculator
./calculator
```

### Matrix Operations

```bash
gcc -std=c11 -Wall -Wextra -pedantic Task-2-Matrix-Operations/matrix_operations.c -o matrix_operations
./matrix_operations
```

On Windows, run `calculator.exe` or `matrix_operations.exe` after compilation.

## Repository Structure

```text
CodeAlpha_C_Programming/
├── Task-1-Calculator/
│   └── calculator.c
├── Task-2-Matrix-Operations/
│   └── matrix_operations.c
└── README.md
```

## Testing

The programs are written for C11 and include handling for normal operations, invalid menu input, division by zero, incompatible matrix dimensions, and out-of-range matrix sizes. Compile them with the warning flags shown above before submission or deployment.

## Author

Created by [khushaal-o1](https://github.com/khushaal-o1) as part of the CodeAlpha C Programming Internship.
