*This project has been created as part of the 42 curriculum by lilyass.*

# ft_printf

## Description

The goal of this project is to recode the C standard library function `printf()`.
Unlike standard string manipulation, `ft_printf` requires dynamic memory stack parsing using **Variadic Arguments**. This project serves as a deep dive into low-level system architecture, specifically how arguments are pushed to the CPU stack and how to read raw memory when the data types are unknown at compile time.

**Prototype:** `int ft_printf(const char *, ...);`

### Supported Conversions (Mandatory)

* `%c` - Prints a single character.

* `%s` - Prints a string.

* `%p` - Prints a `void *` pointer in hexadecimal format.

* `%d` - Prints a decimal (base 10) number.

* `%i` - Prints an integer (base 10).

* `%u` - Prints an unsigned decimal (base 10) number.

* `%x` - Prints a number in hexadecimal (base 16) lowercase.

* `%X` - Prints a number in hexadecimal (base 16) uppercase.

* `%%` - Prints a percent sign.

## Algorithm & Data Structures

For the mandatory scope, the core algorithm relies on a **Linear Parsing & Dispatch Array**.

1. **The Traversal:** The function iterates through the constant string character by character. If a normal character is encountered, it is immediately dispatched to a `write` wrapper.

2. **The Intercept:** When a `%` character is detected, the parser intercepts the next character as the "format specifier".

3. **The Stack Raid (`va_list`):** Using the `<stdarg.h>` macros, the algorithm initializes a `va_list` pointer. Depending on the intercepted specifier, it uses `va_arg` to cast the current stack memory address to the correct data type (e.g., `int`, `char *`, `unsigned int`), processes it into a string or character, and writes it to Standard Output (`fd 1`).

4. **Return Value:** A strict counter is maintained across all sub-functions to track the exact number of bytes successfully written to the system, returning this total at the end to perfectly mimic the original `printf`.

## Instructions

### Compilation

To compile the library, clone the repository and run `make`. This will compile the source files and the included `libft`, generating the static library `libftprintf.a`.

```
make        # Compiles libftprintf.a
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Recompiles the entire project

```

### Execution (Linking)

To use `ft_printf` in your own projects, include the header and compile your code alongside the static library:

```
#include "ft_printf.h"

int main()
{
    ft_printf("Hello %s, ur score is %d and ur ranking is %d\n", "player", 1337, 42);
    return (0);
}

```

Compile with:

```
cc main.c libftprintf.a -o my_program

```

## Resources

* [Linux Programmer's Manual: `man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html)

* [Linux Programmer's Manual: `man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html)

* **AI Usage:** AI was used as a sparring partner and architectural coach to analyze the low-level mechanics of Variadic Arguments, `write` system calls, and Two's Complement memory behavior. No code was blindly copied; AI was leveraged strictly for foundational understanding and edge-case security testing.