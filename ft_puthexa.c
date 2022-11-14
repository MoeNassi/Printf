/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:24:57 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/14 20:09:46 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long frs, int base)
{
	int		len;
	int		tem;
	char	arr[30];
	int		rep;

	rep = 0;
	len = 0;
	tem = 0;
	while (frs != 0)
	{
		rep = frs % base;
		if (rep < 16)
			arr[tem++] = MIN[rep];
		frs = frs / base;
	}
	while (tem >= 0)
		ft_putchar(arr[--tem]);
	return (len);
}
