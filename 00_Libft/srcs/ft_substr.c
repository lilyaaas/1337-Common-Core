#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t      i;
    size_t      s_len;
    char        *sub;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    
    sub = malloc(len + 1);
    if (!sub)
        return (NULL);

    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}