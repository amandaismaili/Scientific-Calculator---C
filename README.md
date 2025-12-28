## Scientific calculator in C
- A command-line calculator written in C that supports basic arithmetic, advanced functions, trigonometry, memory operations, and history tracking. It also handles edge cases like division by zero and invalid factorial inputs.

## Features
- Basic operations: +, -, *, /, power, remainder
- Advanced operations: factorial, square root, natural logarithm (ln), logarithm base 10, exponential (e^x)
- Trigonometry: sin, cos, tan, asin, acos, atan (supports degrees and radians)
- Memory functions: M+, M-, MR, MC
- Operation history stored in history.txt
- Input validation for numbers
- Prevents invalid operations like division by zero or sqrt of negative numbers

## How to compile
- gcc main.c operations.c -o main.exe

## How to run
./main

## Usage
- Run the program.
- Choose an operation from the menu.
- Enter the required numbers.
- The result will be displayed and stored in history.txt.
- You can perform additional calculations or view history.