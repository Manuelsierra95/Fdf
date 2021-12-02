/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:59:35 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/01 17:12:07 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char *temp, char *s2)
{
	char	*a;
	size_t	lentemp;
	size_t	lens2;

	lentemp = ft_strlen(temp);
	lens2 = ft_strlen(s2);
	if (!temp || !s2)
		return (NULL);
	a = malloc((lentemp + lens2 + 1) * sizeof(char));
	if (!a)
		return (NULL);
	ft_memcpy(a, temp, lentemp);
	ft_memcpy(a + lentemp, s2, lens2);
	a[lentemp + lens2] = '\0';
	free(temp);
	return (a);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}
