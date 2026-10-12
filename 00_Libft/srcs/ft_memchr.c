#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr;
    size_t                 i;

    if (!s)
        return (NULL);

    ptr = (const unsigned char *)s;
    i = 0;

    while (i < n)
    {
        if (ptr[i] == (unsigned char)c)
            return ((void *)&ptr[i]);
        i++;
    }

    return (NULL);
}