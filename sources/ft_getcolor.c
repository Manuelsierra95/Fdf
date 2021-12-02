/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:44:16 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:11:07 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_percent(double start, double end, double current)
{
	double	placement;
	double	distance;
	double	result;

	placement = current - start;
	distance = end - start;
	result = placement / distance;
	return (result);
}

int	ft_getlight(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

void	rgb(char *str, t_color	*color)
{
	color->b = 0;
	color->g = 0;
	ft_parsecolor(str, color);
}

int	ft_drawcolor(t_aux *aux, int red, int green)
{
	double	percentage;
	t_color	colorstart;
	t_color	colorend;
	int		blue;

	rgb(aux->c1, &colorstart);
	rgb(aux->c2, &colorend);
	if (colorstart.rgb == colorend.rgb)
		return (colorstart.rgb);
	if (aux->dx > aux->dy)
		percentage = ft_percent(aux->x1, aux->x2, aux->x);
	else
		percentage = ft_percent(aux->y1, aux->y2, aux->y);
	red = ft_getlight(colorstart.r, colorend.r, percentage);
	green = ft_getlight(colorstart.g, colorend.g, percentage);
	blue = ft_getlight(colorstart.b, colorend.b, percentage);
	return ((red << 16) | (green << 8) | blue);
}
