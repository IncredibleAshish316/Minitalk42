/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:14:43 by anepali           #+#    #+#             */
/*   Updated: 2022/12/27 16:33:52 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_hex(unsigned long int n, char c, int *str_len)
{
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	{
		if (n < 16)
		{
			if (c == 'x')
				write(1, &base[n], 1);
			else
				write(1, &base2[n], 1);
			(*str_len)++;
		}
		else
		{
			ft_printf_hex((n / 16), c, str_len);
			ft_printf_hex((n % 16), c, str_len);
		}
	}
}
