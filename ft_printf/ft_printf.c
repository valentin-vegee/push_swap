/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenavid <tbenavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:56:37 by tbenavid          #+#    #+#             */
/*   Updated: 2025/12/13 11:09:11 by tbenavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	format(char *str, int i, va_list arg)
{
	int		len;
	char	*base_min;
	char	*base_maj;

	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	len = 0;
	if (str[i] == 'c')
		len = len + ft_print_char(va_arg(arg, int));
	if (str[i] == 's')
		len = len + ft_print_str(va_arg(arg, char *));
	if (str[i] == 'p')
		len = len + ft_print_ptr(va_arg(arg, void *));
	if (str[i] == 'u')
		len = len + ft_print_unsigned(va_arg(arg, unsigned int));
	if (str[i] == 'd' || str[i] == 'i')
		len = len + ft_print_num(va_arg(arg, int));
	if (str[i] == 'x')
		len = len + ft_putnbr_base(va_arg(arg, unsigned int), base_min);
	if (str[i] == 'X')
		len = len + ft_putnbr_base(va_arg(arg, unsigned int), base_maj);
	if (str[i] == '%')
		len = len + ft_print_char('%');
	return (len);
}

int	ft_printf(char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			len = len + format(str, i, args);
		}
		else
			{
				ft_print_char(str[i]);
				len++;
			}
		i++;
	}
	return (len);
}
