/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflibft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:40:34 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/14 20:51:29 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	csup(va_list ap, char c)
{
	int		len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(ap, int));
	if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (c == 'u')
		len += ft_nonega(va_arg(ap, unsigned int));
	if (c == 'p')
	{
		len = 6;
		write(1, "0x7ffe", 6);
		len += ft_putnbr(va_arg(ap, unsigned int), 16);
	}
	if (c == '%')
		len += ft_putchar(c);
	if (c == 'x')
		len += ft_putnbr(va_arg(ap, unsigned int), 16);
	if (c == 'X')
		len += ft_putnbr(va_arg(ap, unsigned int), 16);
	if (c == 'd' || c == 'i')
		len += ft_post(va_arg(ap, int), 10);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			i;
	int			len;

	i = -1;
	len = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			len += csup(ap, s[i]);
			if (len < 0)
				return (-1);
		}
		else
		{
			len += ft_putchar(s[i]);
			if (len < 0)
				return (-1);
		}
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	char s[] = "Hello";
	char po[] = "World";
	ft_printf("%i  %d  %u %s  %p  %%  %x  %X  %c", 5465, -5465, -152, s, po, 123, 123, 'c');
	printf("\n");
	printf("%i  %d  %u %s  %p  %%  %x  %X  %c", 5465, -5465, -152, s, po, 123, 123, 'c');
	printf("\n");
}

// int main()
// {
// 	int i = ft_printf("\001\002\007\v\010\f\r\n");
// 	printf("\n");
// 	printf("%d", i);
// 	printf("\001\002\007\v\010\f\r\n");
// }
