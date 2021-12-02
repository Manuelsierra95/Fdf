/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:19:57 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 16:16:19 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_hexsize(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	size = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (ft_toupper(base[j] == ft_toupper(str[i])))
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	ft_poshex(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (0);
}

int	ft_hexconvert(char c, char d)
{
	char	*base;
	int		num;

	base = "0123456789ABCDEF";
	num = ft_poshex(base, d) + (ft_poshex(base, c) * 16);
	return (num);
}

int	ft_parsecolor(char *str, t_color *color)
{
	int	size;

	size = ft_hexsize(str);
	if (size == 2)
		color->r = ft_hexconvert(str[0], str[1]);
	else if (size == 4)
	{
		color->r = ft_hexconvert(str[0], str[1]);
		color->g = ft_hexconvert(str[2], str[3]);
	}
	else if (size == 6)
	{
		color->r = ft_hexconvert(str[0], str[1]);
		color->g = ft_hexconvert(str[2], str[3]);
		color->b = ft_hexconvert(str[4], str[5]);
	}
	color->rgb = (color->r << 16) | (color->g << 8) | color->b;
	return (color->rgb);
}
