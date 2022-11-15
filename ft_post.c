/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:22:26 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/15 05:15:39 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_post(int c, int base)
{
	int		len;

	len = ft_count(c);
	if (!c)
		return (ft_putchar('0'), 1);
	if (c < 0)
	{
		len += ft_putchar('-');
		c = c * (-1);
	}
	ft_putnbr(c, base);
	return (len);
}
