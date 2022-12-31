/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putpointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:26 by anepali           #+#    #+#             */
/*   Updated: 2022/12/27 16:33:41 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putpointer(unsigned long int str, int *str_len)
{
	if (str)
	{
		write(1, "0x", 2);
		*str_len += 2;
		ft_printf_hex(str, 'x', str_len);
	}
	else
	{
		write(1, "(nil)", 5);
		*str_len += 5;
	}
}
