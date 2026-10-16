/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:48:31 by lilyass           #+#    #+#             */
/*   Updated: 2026/10/16 17:48:32 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
    size_t      len;
    char        *dest;

    len = ft_strlen(s1) + 1;
    dest = malloc(len);

    if (!dest)
        return (NULL);

    ft_memcpy(dest, s1, len);
    return (dest);
}