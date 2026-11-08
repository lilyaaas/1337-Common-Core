/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:08:20 by lilyass           #+#    #+#             */
/*   Updated: 2026/11/08 23:41:59 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list			args;
    char			*s;
    char			c;
    int				n;
    int				printed_chars;
    int				i;
    unsigned long	address;
    unsigned int	hex_num;

    if (!format)
        return (-1);

    i = 0;
    printed_chars = 0;
    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == '%')
        {
            write(1, "%", 1);
            printed_chars++;
            i += 2;
            continue;
        }
        if (format[i] == '%' && format[i + 1] == 's')
        {
            s = va_arg(args, char *);
            if (!s)
                s = "(null)";
            write(1, s, ft_strlen(s));
            printed_chars += ft_strlen(s);
            i += 2;
            continue;
        }
        if (format[i] == '%' && format[i + 1] == 'c')
        {
            c = va_arg(args, int);
            write(1, &c, 1);
            printed_chars++;
            i += 2;
            continue;
        }
        if (format[i] == '%' && format[i + 1] == 'd')
        {
            n = va_arg(args, int);
            ft_putnbr(n, &printed_chars);
            i += 2;
            continue;
        }
        if (format[i] == '%' && format[i + 1] == 'p')
        {
            address = va_arg(args, unsigned long);
			if (!address)
			{
				write(1, "(nil)", 5);
				printed_chars += 5;
			}else
            {
                printed_chars += write(1, "0x", 2);
                ft_puthex(address, &printed_chars, 'p');
            }
            i += 2;
            continue;
        }
        if (format[i] == '%' && format[i + 1] == 'x')
        {
            hex_num = va_arg(args, unsigned int);
            ft_puthex(hex_num, &printed_chars, 'x');
            i += 2;
            continue;
        }
        if (format[i] == '%' && format[i + 1] == 'X')
        {
            hex_num = va_arg(args, unsigned int);
            ft_puthex(hex_num, &printed_chars, 'X');
            i += 2;
            continue;
        }
        write(1, &format[i], 1);
        printed_chars++;
        i++;
    }

    va_end(args);
    return (printed_chars);
}
