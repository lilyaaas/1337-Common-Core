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