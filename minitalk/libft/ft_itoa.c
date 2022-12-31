/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:45:30 by anepali           #+#    #+#             */
/*   Updated: 2022/12/31 14:50:51 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;
	long	n2;

	n2 = n;
	len = ft_len(n2);
	p = (char *)malloc(len + 1);
	if (!p)
		return (0);
	if (n2 < 0)
	{
		p[0] = '-';
		n2 = -1 * n2;
	}
	if (n2 == 0)
		p[0] = '0';
	p[len--] = '\0';
	while (n2)
	{
		p[len] = n2 % 10 + '0';
		len--;
		n2 = n2 / 10;
	}
	return (p);
}
