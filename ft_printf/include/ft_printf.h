/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:06:23 by lilyass           #+#    #+#             */
/*   Updated: 2026/11/08 23:07:59 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// Function prototypes
int ft_printf(const char *format, ...);

// Helper function prototypes
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *s);
void    ft_puthex(unsigned long n, int *count, char format);

#endif
