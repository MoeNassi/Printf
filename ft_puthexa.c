/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:24:57 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/15 20:42:55 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long frs, int base, char mod)
{
	int		len;
	int		tem;
	char	arr[32];
	int		rep;

	rep = 0;
	tem = 0;
	if (!frs)
		return (write(1, "0", 1), 1);
	while (frs != 0)
	{
		rep = frs % base;
		if (rep < 16)
		{
			if (mod == 'x')
				arr[tem++] = MIN[rep];
			if (mod == 'X')
				arr[tem++] = MAX[rep];
		}
		frs /= base;
	}
	len = tem;
	while (tem > 0)
		ft_putchar(arr[--tem]);
	return (len);
}
