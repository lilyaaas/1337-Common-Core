#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int     len;

    len = 0;
    while (lst)
    {
        len++;
        lst = lst->next;
    }

    return (len);
}