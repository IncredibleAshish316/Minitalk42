/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:28:40 by anepali           #+#    #+#             */
/*   Updated: 2022/11/23 13:58:22 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	foundin_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_assign(char *p, size_t start, size_t end, char const *s1)
{
	while (start < end)
	{
		*p = *(s1 + start);
		p++;
		start++;
	}
	*p = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*p;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (foundin_set(s1[start], set))
		start++;
	while (foundin_set(s1[end - 1], set))
		end--;
	if (end < start)
		start = 0;
	p = (char *)malloc(end - start + 1);
	if (p)
	{
		ft_assign(p, start, end, s1);
		return (p);
	}
	else
		return (0);
}
