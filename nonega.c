/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonega.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:23:08 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/13 02:30:23 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nonega(unsigned int c, int base)
{
	int	len;

	len = 0;
	if (c < 0)
	{
		len += ft_putchar('-');
		c = c * (-1);
	}
	while (c != 0)
	{
		len++;
		c /= 10;
	}
	ft_putnbr(c, base);
	return (len);
}
