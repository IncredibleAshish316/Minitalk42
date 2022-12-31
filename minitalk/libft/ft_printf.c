/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:27:03 by anepali           #+#    #+#             */
/*   Updated: 2022/12/27 16:33:13 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	check(char str, va_list arg, int *str_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == 'c')
		ft_printf_putchar(va_arg(arg, int), str_len);
	else if (str == 'd' || str == 'i')
		ft_printf_itoa(va_arg(arg, int), str_len);
	else if (str == 's')
		ft_printf_putstr(va_arg(arg, char *), str_len);
	else if (str == 'p')
		ft_printf_putpointer(va_arg(arg, long unsigned int), str_len);
	else if (str == 'x' || str == 'X')
		ft_printf_hex(va_arg(arg, unsigned int), str, str_len);
	else if (str == 'u')
		ft_printf_unsigndec(va_arg(arg, unsigned int), str_len);
	else if (str == '%')
		*str_len += write(1, &str, 1);
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		str_len;

	str_len = 0;
	va_start(arg, str);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check((*str), arg, &str_len);
		}
		else
		{
			str_len += write(1, str, 1);
		}
		str++;
	}
	va_end(arg);
	return (str_len);
}
