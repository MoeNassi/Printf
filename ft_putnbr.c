/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:23:44 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/14 20:18:58 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned int c, int base)
{
	int			len;
	int			store;
	char		arr[25];
	int			j;

	store = c;
	len = 0;
	j = 0;
	while (c != 0)
	{
		store = c % base;
		if (store >= 10)
			arr[++j] = store + 55;
		if (store < 10)
			arr[++j] = store + 48;
		c = c / base;
	}
	len = j;
	while (j > 0)
		write(1, &arr[j--], 1);
	return (len);
}
