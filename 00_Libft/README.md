*This project has been created as part of the 42 curriculum by lilyass.*

# Libft - My very first own library

## Description
Libft is the first project of the 42 Common Core. The goal is to create a custom C library containing a set of standard libc functions, as well as some additional utility functions and a linked list implementation. This library (`libft.a`) will be used as a foundational tool for all future C projects in the curriculum.

## Instructions
To compile and manage the library, use the provided `Makefile` with the following commands:
- `make` or `make all`: Compiles all standard and linked list functions into `libft.a`.
- `make clean`: Removes all `.o` object files.
- `make fclean`: Removes the object files and the `libft.a` library.
- `make re`: Cleans and recompiles everything from scratch.

## Resources and AI Usage
During the development of this project, the following resources were utilized:
- Standard Linux `man` pages (e.g., `man 3 malloc`, `man 3 write`) for behavior replication.
- 42 Norme documentation for strict C coding standards.
- AI Assistant was used as a conceptual thought partner and tutor to explain C.

## Functions Implemented

### Part 1 - Libc functions
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`
- `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`
- `ft_atoi`, `ft_calloc`, `ft_strdup`

### Part 2 - Additional functions
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`
- `ft_strmapi`, `ft_striteri`
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Part 3 - Linked list functions
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`
- `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`