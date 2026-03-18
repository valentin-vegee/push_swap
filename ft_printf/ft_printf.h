/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenavid <tbenavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:11:49 by tbenavid          #+#    #+#             */
/*   Updated: 2025/12/13 11:11:46 by tbenavid         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		format(char *str, int i, va_list arg);
int		ft_printf(char *str, ...);
int		ft_strlen(char *str);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_put_hexa(unsigned long n);
int		ft_print_ptr(void *ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_print_num(int i);
int		ft_putnbr_base(unsigned int n, char *base);

#endif
