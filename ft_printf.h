/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:25:26 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/13 02:30:17 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

int	ft_printf(const char *s, ...);
int	ft_putstr(const char *s);
int	ft_putchar(char c);
int	ft_putnbr(int c, int base);
int	nonega(unsigned int c, int base);
int	ft_puthexa(int frs, int base);

#endif