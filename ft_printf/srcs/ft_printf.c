/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:08:20 by lilyass           #+#    #+#             */
/*   Updated: 2026/11/10 00:55:11 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	conversion(va_list arg, const char *str, size_t *i)
{
	int len;

	len = 0;
    if (str[*i + 1] == 'c')
        len += ft_putchar(va_arg(arg, int));
    else if (str[*i + 1] == 's')
        len += ft_putstr(va_arg(arg, char *));
	else if (str[*i + 1] == 'p')
		ft_putadd(va_arg(arg, unsigned long), &len);
    else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
        ft_putnbr(va_arg(arg, int), &len);
	else if (str[*i + 1] == 'u')
		ft_putunsgd(va_arg(arg, unsigned int), &len);
    else if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
        ft_puthex(va_arg(arg, unsigned int), &len, str[*i + 1]);
	else if (str[*i + 1] == '%')
        len += ft_putchar('%');
	else if (str[*i + 1])
		len += ft_putchar(str[*i + 1]);

	return (len);
}

int ft_printf(const char *str, ...)
{
    va_list			args;
    size_t			i;
    int				printed_chars;

    if (!str)
        return (-1);
	if (write(1, "", 0) == -1)
		return (-1);

    i = 0;
    printed_chars = 0;
    va_start(args, str);

    while (str[i])
    {
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
                break ;
			printed_chars += conversion(args, str, &i);
			i++;
		} else
			printed_chars += ft_putchar(str[i]);
		i++;
    }

    va_end(args);
    return (printed_chars);
}
