/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_else.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenavid <tbenavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:45:08 by tbenavid          #+#    #+#             */
/*   Updated: 2025/12/13 11:19:03 by tbenavid         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_put_hexa(unsigned long n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len = len + ft_put_hexa(n / 16);
	len = len + ft_print_char(base[n % 16]);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 10)
		i = i + ft_print_unsigned(n / 10);
	i = i + ft_print_char((n % 10) + '0');
	return (i);
}

int	ft_print_num(int i)
{
	int	j;

	j = 0;
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	if (i > 10)
		j = j + ft_print_num(i / 10);
	j = j + ft_print_char((i % 10) + '0');
	return (j);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	unsigned int	len_base;
	int				len;

	len = 0;
	len_base = 16;
	if (n >= len_base)
		len = len + ft_putnbr_base((n / len_base), base);
	len = len + ft_print_char(base[n % len_base]);
	return (len);
}
