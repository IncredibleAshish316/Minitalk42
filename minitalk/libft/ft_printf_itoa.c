/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:46:15 by anepali           #+#    #+#             */
/*   Updated: 2022/12/27 16:33:49 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_itoa(long int n, int *str_len)
{
	char	*base;

	base = "0123456789";
	if (n > INT_MAX || n < INT_MIN)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		(*str_len)++;
	}
	if (n >= 0 && n <= 9)
	{
		write(1, &base[n], 1);
		(*str_len)++;
	}
	else
	{
		ft_printf_itoa((n / 10), str_len);
		ft_printf_itoa((n % 10), str_len);
	}
}
