/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 05:46:33 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/15 20:43:08 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(unsigned long long frs, int base)
{
	int		len;
	int		tem;
	int		rep;
	char	arr[64];

	tem = 0;
	rep = 0;
	write(1, "0x", 2);
	if (!frs)
		return (write(1, "0", 1), 3);
	while (frs != 0)
	{
		rep = frs % base;
		if (rep < 16)
			arr[tem++] = MIN[rep];
		frs /= base;
	}
	len = tem + 2;
	while (tem > 0)
		ft_putchar(arr[--tem]);
	return (len);
}

// int main()
// {
// 	ft_putadress(LONGMAX, 16);
// 	printf("\n%p\n", LONGMAX);
// }
