/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:03:17 by anepali           #+#    #+#             */
/*   Updated: 2022/11/12 14:10:15 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	buff;
	char	*p;

	buff = n * size;
	p = (char *)malloc(buff);
	if (p)
		ft_bzero(p, buff);
	return (p);
}
