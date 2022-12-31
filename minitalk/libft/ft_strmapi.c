/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:50:55 by anepali           #+#    #+#             */
/*   Updated: 2022/11/17 15:41:24 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*p;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	p = (char *)malloc(len + 1);
	if (p)
	{
		while (i < len)
		{
			p[i] = f(i, s[i]);
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
