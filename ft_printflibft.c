/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflibft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:40:34 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/15 23:58:10 by mnassi           ###   ########.fr       */
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
		len += ft_putadress(va_arg(ap, unsigned long long), 16);
	if (c == '%')
		len += ft_putchar(c);
	if (c == 'x')
		len += ft_puthexa(va_arg(ap, unsigned int), 16, 'x');
	if (c == 'X')
		len += ft_puthexa(va_arg(ap, unsigned int), 16, 'X');
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
