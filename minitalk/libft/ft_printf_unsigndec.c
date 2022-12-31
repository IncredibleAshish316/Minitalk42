/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigndec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:16:31 by anepali           #+#    #+#             */
/*   Updated: 2022/12/27 16:33:31 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_unsigndec(unsigned int n, int *str_len)
{
	char	*base;

	base = "0123456789";
	if (n >= 0 && n <= 9)
	{
		write(1, &base[n], 1);
		(*str_len)++;
	}
	else
	{
		ft_printf_unsigndec((n / 10), str_len);
		ft_printf_unsigndec((n % 10), str_len);
	}
}
