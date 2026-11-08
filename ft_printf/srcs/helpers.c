/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 20:21:49 by lilyass           #+#    #+#             */
/*   Updated: 2026/11/08 22:58:04 by lilyass          ###   ########.fr       */
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

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n, int *count)
{
	long	num;
    char    c;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
        (*count)++;
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10, count);
    c = (num % 10) + '0';
    (*count)++;
	write(1, &c, 1);
}

void    ft_puthex(unsigned long n, int *count, char format)
{
    char hex_digit;

    if (n >= 16)
        ft_puthex(n / 16, count, format);

    if (format == 'X')
        hex_digit = "0123456789ABCDEF"[n % 16];
    else
        hex_digit = "0123456789abcdef"[n % 16];

    *count += write(1, &hex_digit, 1);
}