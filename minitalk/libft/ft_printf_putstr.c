/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:05:41 by anepali           #+#    #+#             */
/*   Updated: 2022/12/27 16:33:36 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putstr(char *s, int *str_len)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*str_len += 6;
		return ;
	}
	while (*s)
	{
		write(1, s++, 1);
		(*str_len)++;
	}
}
