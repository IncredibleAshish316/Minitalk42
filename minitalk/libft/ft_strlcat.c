/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:57:12 by anepali           #+#    #+#             */
/*   Updated: 2022/11/12 14:14:37 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	while ((i < (size - 1 - len_dst)) && (src[j] != '\0'))
	{
		dst[len_dst + j] = src[j];
		i++;
		j++;
	}
	dst[len_dst + j] = '\0';
	return (len_src + len_dst);
}
