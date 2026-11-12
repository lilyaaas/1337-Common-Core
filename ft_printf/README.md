*This project has been created as part of the 42 curriculum by lilyass.*

# ft_printf

## Description

The goal of this project is to recode the C standard library function `printf()`.
Unlike standard string manipulation, `ft_printf` requires dynamic memory stack parsing using **Variadic Arguments**. This project serves as a deep dive into low-level system architecture, specifically how arguments are pushed to the CPU stack and how to read raw memory when the data types are unknown at compile time.

**Prototype:** `int ft_printf(const char *, ...);`

## Contents

- `include/ft_printf.h`: public function declaration and internal helper declarations.
- `srcs/ft_printf.c`: format-string traversal and conversion dispatch.
- `srcs/helpers.c`: character, string, integer, pointer, and hexadecimal output helpers.
- `test/ft_printf_tests.c`: comparison-style tests against the system `printf` for common values and edge cases.
- `Makefile`: builds the static library `libftprintf.a`.

## Supported Conversions

| Specifier | Argument type | Output |
| --- | --- | --- |
| `%c` | `int` (promoted character) | One character |
| `%s` | `char *` | String up to its terminating null byte; a null pointer prints `(null)` |
| `%p` | `void *` | Lowercase hexadecimal address with `0x` prefix; a null pointer prints `(nil)` |
| `%d` | `int` | Signed decimal integer |
| `%i` | `int` | Signed decimal integer |
| `%u` | `unsigned int` | Unsigned decimal integer |
| `%x` | `unsigned int` | Lowercase hexadecimal integer |
| `%X` | `unsigned int` | Uppercase hexadecimal integer |
| `%%` | None | A literal percent sign |


## How It Works

`ft_printf` walks the format string from left to right. Ordinary characters are written directly. When it sees `%`, it dispatches the next character to the matching conversion handler. The handler retrieves the corresponding argument using `va_arg`; helper functions convert numeric values to output a digit at a time. Output is written to file descriptor 1 using `write`.

The implementation uses the `va_list` interface from `<stdarg.h>`; it does not inspect or read raw stack memory. The return value is accumulated from the helper write calls and is intended to represent the number of characters printed.

## Build

Requirements: a C compiler and `make`.

From the project directory:

```sh
make        # Build libftprintf.a
make clean  # Remove object files
make fclean # Remove object files and libftprintf.a
make re     # Clean and rebuild the library
```

The library is built from `srcs/ft_printf.c` and `srcs/helpers.c` with `-Wall -Wextra -Werror`. No external `libft` is required. The Makefile does not define a test target.

## Use the Library

Include the public header and link the generated archive:

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello %s, ur score is %d and ur ranking is %d\n", "player", 1337, 42);
    return (0);
}
```

For example, if the program is saved as `main.c`:

```sh
cc -Wall -Wextra -Werror -Iinclude main.c libftprintf.a -o my_program
./my_program
```

## Tests

Build the library first, then compile the comparison test from the project root:

```sh
cc -Wno-format -Iinclude test/ft_printf_tests.c libftprintf.a -o ft_printf_tests
./ft_printf_tests
```

The test program compares output counts and behavior for the supported conversions, including null strings and pointers, integer limits, mixed conversions, and extra arguments. It also contains null-format and incomplete-format cases; these are non-portable edge cases and should not be treated as guarantees of standard `printf` behavior.

## Scope and Limitations

This project implements the basic conversion set above. It does not currently implement flags, field width, precision, length modifiers, or the other conversions supported by the standard library. Error handling for failed writes is also simpler than libc `printf`; the implementation is intended for the required project scope rather than as a fully compatible replacement.
