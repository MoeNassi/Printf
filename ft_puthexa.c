/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:24:57 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/13 03:15:29 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(int frs)
{
	int	tem;
	int	len;

	len = 0;
	tem = frs;
	while (tem != 0)
	{
		tem /= 10;
		len++;
	}
	return (len);
}

int	ft_puthexa(int frs, int base)
{
	int		len;
	int		tem;
	char	*save;
	char	arr[25];
	int		rep;

	save = "0123456789abcdef";
	rep = 0;
	len = ft_count(frs);
	tem = 0;
	while (frs != 0)
	{
		rep = frs % base;
		if (rep <= 15)
		{
			arr[tem++] = save[rep];
			rep = 0;
		}
		frs = frs / base;
	}
	while (tem >= 0)
		write(1, &arr[tem--], 1);
	return (len);
}
