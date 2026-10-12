int ft_tolower(int c)
{
    if (c <= 'Z' && c >= 'A')
        c += 32;
    return (c);
}