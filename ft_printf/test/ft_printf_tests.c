#include <stdio.h>
#include <limits.h>
#include "include/ft_printf.h"

int	main(void)
/*
    Compile this using "cc -Wno-format test.c libftprintf.a"
    so GCC allows the intentional undefined behavior tests to run
*/
{
	int		ret_ft;
	int		ret_std;
	char	*null_str = NULL;
	int		stack_var = 1337;

	ft_printf("======================= CHAR TESTS (%%c) =======================\n");
	ret_ft = ft_printf("TEST 1 (normal)    : |%c|\n", '@');
	ret_std = printf("TEST 1 (normal)    : |%c|\n", '@');
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 2 (space)     : |%c|\n", ' ');
	ret_std = printf("TEST 2 (space)     : |%c|\n", ' ');
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 3 (ASCII 97)  : |%c|\n", 97);
	ret_std = printf("TEST 3 (ASCII 97)  : |%c|\n", 97);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 4 (overflow+) : |%c|\n", '0' + 256);
	ret_std = printf("TEST 4 (overflow+) : |%c|\n", '0' + 256);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 5 (overflow-) : |%c|\n", '0' - 256);
	ret_std = printf("TEST 5 (overflow-) : |%c|\n", '0' - 256);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 6 (NULL byte) : |%c|\n", '\0');
	ret_std = printf("TEST 6 (NULL byte) : |%c|\n", '\0');
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ft_printf("======================= STR TESTS (%%s) ========================\n");
	ret_ft = ft_printf("TEST 1 (normal)    : |%s|\n", "1337 Khouribga");
	ret_std = printf("TEST 1 (normal)    : |%s|\n", "1337 Khouribga");
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 2 (NULL)      : |%s|\n", null_str);
	ret_std = printf("TEST 2 (NULL)      : |%s|\n", null_str);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 3 (empty)     : |%s|\n", "");
	ret_std = printf("TEST 3 (empty)     : |%s|\n", "");
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 4 (hidden \\0) : |%s|\n", "visible\0secret_leak");
	ret_std = printf("TEST 4 (hidden \\0) : |%s|\n", "visible\0secret_leak");
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ft_printf("===================== POINTER TESTS (%%p) ======================\n");
	ret_ft = ft_printf("TEST 1 (stack addr): |%p|\n", &stack_var);
	ret_std = printf("TEST 1 (stack addr): |%p|\n", &stack_var);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 2 (NULL)      : |%p|\n", NULL);
	ret_std = printf("TEST 2 (NULL)      : |%p|\n", NULL);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 3 (void * 0)  : |%p|\n", (void *)0);
	ret_std = printf("TEST 3 (void * 0)  : |%p|\n", (void *)0);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 4 (ULONG_MAX) : |%p|\n", (void *)-1);
	ret_std = printf("TEST 4 (ULONG_MAX) : |%p|\n", (void *)-1);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 5 (LONG_MIN)  : |%p %p|\n", (void *)LONG_MIN, (void *)LONG_MAX);
	ret_std = printf("TEST 5 (LONG_MIN)  : |%p %p|\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ft_printf("=================== INT TESTS (%%d and %%i) =====================\n");
	ret_ft = ft_printf("TEST 1 (zero)      : |%d| |%i|\n", 0, -0);
	ret_std = printf("TEST 1 (zero)      : |%d| |%i|\n", 0, -0);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 2 (INT_MAX)   : |%d| |%i|\n", INT_MAX, INT_MAX);
	ret_std = printf("TEST 2 (INT_MAX)   : |%d| |%i|\n", INT_MAX, INT_MAX);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 3 (INT_MIN)   : |%d| |%i|\n", INT_MIN, INT_MIN);
	ret_std = printf("TEST 3 (INT_MIN)   : |%d| |%i|\n", INT_MIN, INT_MIN);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ft_printf("==================== UNSIGNED TESTS (%%u) ======================\n");
	ret_ft = ft_printf("TEST 1 (zero)      : |%u|\n", 0);
	ret_std = printf("TEST 1 (zero)      : |%u|\n", 0);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 2 (UINT_MAX)  : |%u|\n", UINT_MAX);
	ret_std = printf("TEST 2 (UINT_MAX)  : |%u|\n", UINT_MAX);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 3 (neg wrap)  : |%u|\n", -1);
	ret_std = printf("TEST 3 (neg wrap)  : |%u|\n", -1);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 4 (-42 wrap)  : |%u|\n", -42);
	ret_std = printf("TEST 4 (-42 wrap)  : |%u|\n", -42);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ft_printf("================== HEXADECIMAL TESTS (%%x / %%X) ================\n");
	ret_ft = ft_printf("TEST 1 (zero)      : |%x| |%X|\n", 0, 0);
	ret_std = printf("TEST 1 (zero)      : |%x| |%X|\n", 0, 0);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 2 (UINT_MAX)  : |%x| |%X|\n", UINT_MAX, UINT_MAX);
	ret_std = printf("TEST 2 (UINT_MAX)  : |%x| |%X|\n", UINT_MAX, UINT_MAX);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 3 (neg -1)    : |%x| |%X|\n", -1, -1);
	ret_std = printf("TEST 3 (neg -1)    : |%x| |%X|\n", -1, -1);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 4 (INT_MIN)   : |%x| |%X|\n", INT_MIN, INT_MIN);
	ret_std = printf("TEST 4 (INT_MIN)   : |%x| |%X|\n", INT_MIN, INT_MIN);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ft_printf("================= MIXED STACK ALIGNMENT TEST ==================\n");
	ret_ft = ft_printf("MIX : |%c|%s|%p|%d|%i|%u|%x|%X|%%|\n",
			'Z', null_str, &stack_var, INT_MIN, 42, -1, 255, 255);
	ret_std = printf("MIX : |%c|%s|%p|%d|%i|%u|%x|%X|%%|\n",
			'Z', null_str, &stack_var, INT_MIN, 42, -1, 255, 255);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ft_printf("============== UNDEFINED BEHAVIOR & CRASH TESTS ===============\n");
	ret_ft = ft_printf(NULL);
	ret_std = printf(NULL);
	printf("TEST 1 (NULL format)       -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 2 (extra args)        : |%d|\n", 42, "ignored", 999, NULL);
	ret_std = printf("TEST 2 (extra args)        : |%d|\n", 42, "ignored", 999, NULL);
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("TEST 3 (trailing percent)  : |%");
	printf("|\n");
	ret_std = printf("TEST 3 (trailing percent)  : |%");
	printf("|\n");
	printf("RETURN -> ft: %d | std: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("TEST 4 (unknown flag %%k)   : |%k|\n");
	ret_std = printf("TEST 4 (unknown flag %%k)   : |%k|\n");
	printf("RETURN -> ft: %d | std: %d\n", ret_ft, ret_std);

	return (0);
}