/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:31:51 by lilyass           #+#    #+#             */
/*   Updated: 2026/10/17 20:26:13 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	long	res;
	int		sign;
	long	max_value;

	i = 0;
	res = 0;
	sign = 1;
	max_value = 9223372036854775807;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (max_value - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
