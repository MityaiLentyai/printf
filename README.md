*This project has been created as part of the 42 curriculum by dzzayats.*

## Description

This repository contains a custom implementation of the `ft_printf` function in C. The goal is to reproduce a subset of the standard `printf` behavior while following 42 school coding standards. The implementation supports formatted output for common conversion specifiers and includes helper functions to manage string and number formatting.

## Instructions

1. Clone or download the repository.
2. Run `make` to build the static library archive.
3. The build produces `libftprintf.a`.
4. Add `ft_printf.h` to your own source and include it with `#include "ft_printf.h"`.
5. Compile your own `main.c` with the archive, for example:
   - `cc main.c libftprintf.a -o main`
   - or `gcc main.c -L. -lftprintf -o main`
6. If you use a separate `libftprintf` directory or custom object files, make sure the archive path is correct, e.g.:
   - `cc main.c ./libftprintf.a -o main`
7. Review the source files:
   - `ft_printf.c` for the main `ft_printf` implementation
   - `helper_functions.c` and `helper_functions_2.c` for auxiliary formatting routines
   - `ft_printf.h` for function declarations and constants
8. Use `make fclean` to remove compiled object files and the archive when finished.

## Resources

- `man 3 printf` for standard `printf` behavior and supported format specifiers
- `man 3 write` for low-level output handling
- `man 3 va_start`, `man 3 va_arg`, and `man 3 va_end` for variadic function support
- `man7.org` for additional Linux man pages and documentation
-  different youtube sources with explanations on variadic functions

