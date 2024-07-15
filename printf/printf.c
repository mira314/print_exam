#include <unistd.h>
#include <stdio.h>
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
        i++;
    }
    return (count);
}

int put_nbr(long int nb)
{
    int count = 0;
    char c;

    if (nb < 0)
    {
        nb = -nb;
        count += put_char('-');
    }
    if (nb >= 10)
        count +=  put_nbr(nb / 10);
    c = nb % 10 + 48;
    count += put_char(c);
    return (count);
}
int	ft_puthex(unsigned int nb)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
	{
		count += ft_puthex(nb / 16);
		count += ft_puthex(nb % 16);
	}
	else
		count += put_char(hex[nb]);
	return (count);
}
int	ft_printf(const char *format, ... )
{
    int i = 0;
    int len = 0;
    va_list pointer;
    va_start(pointer, format);
    while (format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'x'))
        {
            i++;
            if (format[i] == 's')
            	len += put_str(va_arg(pointer, char *));
            else if (format[i] == 'd')
            	len += put_nbr(va_arg(pointer, int));
            else if (format[i] == 'x')
            	len += ft_puthex(va_arg(pointer, unsigned int));
        }
        else
            len += put_char(format[i]);
        i++;
    }
    va_end(pointer);
    return (len);
}
int main(int argc, char const *argv[])
{
	int len= 0;
	int len1= 0;
	len = ft_printf("teste %x\n",145, "oui");
	len1 = ft_printf("teste %x\n",145, "oui");
	printf("len %d\n",len );
	printf("len1 %d\n",len1 );
	return 0;
}

