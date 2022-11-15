/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:25:26 by mnassi            #+#    #+#             */
/*   Updated: 2022/11/15 20:43:19 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# define LONGMAX 9223372036854775807
# define MIN "0123456789abcdef"
# define MAX "0123456789ABCDEF"

int	ft_printf(const char *s, ...);
int	ft_putstr(const char *s);
int	ft_putchar(char c);
int	ft_putnbr(unsigned int c, int base);
int	ft_nonega(unsigned int c);
int	ft_post(int c, int base);
int	ft_puthexa(unsigned long frs, int base, char mod);
int	ft_putadress(unsigned long long frs, int base);
int	ft_count(int frs);

#endif