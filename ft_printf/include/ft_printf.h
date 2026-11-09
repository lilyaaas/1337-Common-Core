/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:06:23 by lilyass           #+#    #+#             */
/*   Updated: 2026/11/09 22:39:43 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// Function prototypes
int		ft_printf(const char *format, ...);

// Helper function prototypes
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putunsgd(unsigned int n, int *printed_chars);
void	ft_putnbr(int n, int *printed_chars);
void	ft_putadd(unsigned long add, int *printed_chars);
void	ft_puthex(unsigned long hex, int *printed_chars, char format);
size_t	ft_strlen(const char *s);

#endif
