/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 20:21:49 by lilyass           #+#    #+#             */
/*   Updated: 2026/11/10 00:47:40 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

void	ft_putnbr(int n, int *printed_chars)
{
	long	num;            

	num = n;
	if (num < 0)
	{
		num = -num;
        *printed_chars += ft_putchar('-');
	}
	if (num >= 10)
		ft_putnbr(num / 10, printed_chars);
    *printed_chars += ft_putchar((num % 10) + '0');
}

void	ft_putunsgd(unsigned int n, int *printed_chars)
{
	if (n >= 10)
		ft_putunsgd(n / 10, printed_chars);
    *printed_chars += ft_putchar((n % 10) + '0');
}

void	ft_putadd(unsigned long addrs, int *printed_chars)
{
	char	buffer[16];
	int		i;

	if (!addrs)
	{
        *printed_chars += ft_putstr("(nil)");
		return ;
	}

	*printed_chars += ft_putstr("0x");
	i = 0;
	while (addrs != 0)
	{
		buffer[i++] = "0123456789abcdef"[addrs % 16];
		addrs /= 16;
	}

	i--;
	while (i >= 0)
		*printed_chars += ft_putchar(buffer[i--]);
}

void    ft_puthex(unsigned long hex, int *printed_chars, char format)
{
    char hex_digit;

    if (hex >= 16)
        ft_puthex(hex / 16, printed_chars, format);

    if (format == 'X')
        hex_digit = "0123456789ABCDEF"[hex % 16];
    else
        hex_digit = "0123456789abcdef"[hex % 16];
    *printed_chars += ft_putchar(hex_digit);
}
