/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:00:59 by anepali           #+#    #+#             */
/*   Updated: 2022/11/18 16:02:22 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	i = 0;
	j = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (big[j] != '\0')
	{
		i = 0;
		while (little[i] != '\0' && (j + i) < len)
		{
			if (big[j + i] != little[i])
				break ;
			i++;
		}
		if (little[i] == '\0')
			return ((char *)&big[j]);
		j++;
	}
	return (0);
}
