/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:41:37 by anepali           #+#    #+#             */
/*   Updated: 2022/11/22 16:59:59 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	p = 0;
	i = 0;
	if (start > ft_strlen(s))
	{
		p = malloc(sizeof(char));
		if (p)
			p[0] = '\0';
		return (p);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = (char *)malloc(len + 1);
	if (!p)
		return (0);
	while (i++ < len)
		*(p + i - 1) = *(s + start + i - 1);
	*(p + i - 1) = '\0';
	return (p);
}
