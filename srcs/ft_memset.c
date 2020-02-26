#include "../includes/lem.h"

void    *ft_memset(void *b, int c, size_t len)
{
        size_t a;

        a = 0;
        while (a < len)
        {
                *((char*)b + a) = c;
                a++;
        }
        return (b);
}