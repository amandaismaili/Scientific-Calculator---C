# Scientific Calculator (C)
A command-line scientific calculator written in C that supports basic arithmetic, advanced mathematical functions, trigonometry, memory operations, and history tracking.

## Features

### Basic Operations
* Addition, subtraction, multiplication, division
* Power and remainder

### Advanced Functions
* Factorial
* Square root
* Natural logarithm (`ln`)
* Base-10 logarithm
* Exponential function (`e^x`)

### Trigonometry
* `sin`, `cos`, `tan`
* Inverse functions: `asin`, `acos`, `atan`
* Supports both degrees and radians

### Memory Operations
* `M+` (add to memory)
* `M-` (subtract from memory)
* `MR` (recall memory)
* `MC` (clear memory)

### Additional Features
* Operation history saved in `history.txt`
* Input validation for numeric values
* Handles edge cases:

  * Division by zero
  * Invalid factorial inputs
  * Square root of negative numbers

## Project Structure
* `main.c` – Program entry point and user interface
* `operations.c` – Implementation of mathematical operations

## How to Compile
```bash
gcc main.c operations.c -o calculator
```

## How to Run
```bash
./calculator
```

## Usage
* Launch the program
* Select an operation from the menu
* Enter the required inputs
* View results instantly
* Access calculation history in `history.txt`

## Notes
This project was developed to strengthen my understanding of C programming, including modular design, input validation, and handling mathematical edge cases.
