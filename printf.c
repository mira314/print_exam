#include <unistd.h>
#include <stdarg.h>
int put_char(char c)
{
    write (1, &c, 1);
    return (1);
}
int put_str(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if(!str)
        str = "(null)";
    while (str[i])
    {
        count += put_char(str[i]);
        +++;
    }
    return (count);
}

int put_nbr(long long int nb, int base)
{
    int count = 0;
    char *hexa = "0123456789abcdef";
    char c;

    if (nb < 0)
    {
        nb = -nb;
        count += put_char('-');
    }
    if (nb >= base)
        count +=  put_nbr(nb / base, base);
    c = hexa[nb % base];
    count += put_char(c);
    return (count);
}
