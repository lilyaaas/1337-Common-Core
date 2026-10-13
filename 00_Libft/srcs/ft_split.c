#include "libft.h"

static size_t count_words(const char *s, char c)
{
    size_t i;
    size_t words;

    i = 0;
    words = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            while (s[i] && s[i] != c)
                i++;
            words++;
        }
        else
            i++;
    }
    return (words);
}

static void *free_split(char **tab, size_t i)
{
    while (i > 0)
    {
        i--;
        free(tab[i]);
    }
    free(tab);
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    char **tab;
    size_t i;
    size_t j;
    size_t start;

    if (!s)
        return (NULL);
    tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!tab)
        return (NULL);

    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            tab[j] = ft_substr(s, start, i - start);
            if (!tab[j])
                return (free_split(tab, j));
            j++;
        }
        else
            i++;
    }
    tab[j] = NULL;
    return(tab);
}