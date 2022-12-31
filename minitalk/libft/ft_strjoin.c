/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:06:22 by anepali           #+#    #+#             */
/*   Updated: 2022/11/18 14:41:14 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	p = (char *)malloc(s2_len + s1_len + 1);
	if (p)
	{
		ft_strlcpy(p, s1, s2_len + s1_len + 1);
		ft_strlcat(p, s2, s2_len + s1_len + 1);
	}
	return (p);
}
