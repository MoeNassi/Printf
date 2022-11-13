/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflibft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:40:34 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/13 03:17:48 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	csup(va_list ap, char c, int len)
{
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	if (c == 'u')
		nonega(va_arg(ap, unsigned int), 10);
	if (c == 'p')
	{
		write(1, "0x", 2);
		ft_puthexa(va_arg(ap, int), 16);
	}
	if (c == '%')
		ft_putchar(va_arg(ap, int));
	if (c == 'x')
		ft_puthexa(va_arg(ap, unsigned int), 16);
	if (c == 'X')
		ft_putnbr(va_arg(ap, unsigned int), 16);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), 10);
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
		if (s[i] != '%')
		{
			i = -1;
			while (s[++i])
				ft_putchar(s[i]);
		}
		if (s[i] == '%')
		{
			i++;
			csup(ap, s[i], len);
		}
	}
	va_end(ap);
	if (len < 0)
		return (-1);
	return (len);
}
