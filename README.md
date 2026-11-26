*This project has been created as part of the 42 curriculum by irebah.*

# ft_printf

## Description

The **ft_printf** project consists of recreating the behavior of the standard C `printf()` function.

The goal of this project is to understand and implement variadic functions in C using `va_list`, `va_start`, `va_arg`, and `va_end`.

The implementation processes a format string, identifies conversion specifiers, retrieves the corresponding arguments, and prints the appropriate output to the standard output.

## Supported Conversions

The implementation supports the following conversions:

| Specifier | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints an integer in decimal format. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned hexadecimal number using lowercase letters. |
| `%X` | Prints an unsigned hexadecimal number using uppercase letters. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

To compile the library, clone the repository and run:

```bash
make
```

This generates the `libftprintf.a` static library.

### Makefile Commands

- `make`: Compiles the project.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the compiled library.
- `make re`: Rebuilds the project from scratch.

### Usage

To use `ft_printf` in your own C program, include the header file and link the static library during compilation.

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "World", 42);
    return (0);
}
```

Compile your program with:

```bash
cc main.c -L. -lftprintf -I. -o program
```

Run it with:

```bash
./program
```

## Algorithm and Data Structures

### 1. Format String Processing

The main function iterates through the format string character by character.

- If the current character is not `%`, it is printed directly.
- If a `%` is encountered, the next character is checked to identify the conversion specifier.
- The corresponding handler function is called to process the argument.

This approach separates format parsing from the actual printing operations.

### 2. Variadic Arguments

The project uses the C standard `<stdarg.h>` library to handle a variable number of arguments.

The following macros are used:

- `va_start`: Initializes access to the variadic arguments.
- `va_arg`: Retrieves the next argument with the expected type.
- `va_end`: Ends the use of the variadic argument list.

The conversion specifier determines the expected argument type.

### 3. Number Conversion Algorithms

Decimal and hexadecimal numbers are printed using recursive functions.

For decimal numbers, the algorithm divides the number by 10 to process its digits.

For hexadecimal numbers, the algorithm divides the number by 16 and uses a character lookup table to select the appropriate hexadecimal digit.

Recursion allows the most significant digits to be printed before the least significant digits.

### 4. Pointer Conversion

Pointer addresses are converted into hexadecimal representation.

The implementation handles the pointer prefix and the hexadecimal digits separately.

### 5. Error Handling and Return Value

Each printing function returns the number of characters successfully written.

If a printing operation fails, the error is propagated to the calling function.

The main function returns the total number of characters printed, or `-1` when an error occurs.

## Resources

### References

- C Standard Library documentation.
- `man printf`
- `man stdarg`
- `man write`
- GNU C Library documentation.
- 42 / 1337 project subject.

### AI Usage

AI tools were used as learning and support resources during the development of this project.

They helped with:

- Understanding variadic functions and the `stdarg.h` macros.
- Explaining format specifiers and argument types.
- Understanding recursion and number conversion algorithms.
- Reviewing code logic and identifying potential errors.
- Understanding memory management and error handling.

The implementation and final code were studied, tested, and adapted as part of the learning process.