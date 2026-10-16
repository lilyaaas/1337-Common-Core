/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilyass <lilyass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:48:18 by lilyass           #+#    #+#             */
/*   Updated: 2026/10/16 17:48:19 by lilyass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list      *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);

    new_node->content = content;
    new_node->next = NULL;

    return (new_node);
}