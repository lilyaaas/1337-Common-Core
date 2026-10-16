/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:46:43 by lilyass           #+#    #+#             */
/*   Updated: 2026/10/16 17:46:44 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char	*s;
    size_t i;

    if (!dst && !src)
        return (NULL);

    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    i = 0;

    while (i < n)
    {
        d[i] = s[i];
        i++;
    }

    return (dst);
}