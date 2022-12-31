/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:28:35 by anepali           #+#    #+#             */
/*   Updated: 2022/11/12 14:13:34 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*p;

	len = ft_strlen(s);
	p = (char *)malloc(len + 1);
	if (p)
	{
		ft_memcpy(p, s, len);
		p[len] = '\0';
		return (p);
	}
	else
		return (0);
}
