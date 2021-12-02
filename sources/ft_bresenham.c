/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:33:34 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 16:04:55 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham_x(t_aux *aux, t_fdf *fdf)
{
	double	i;

	img_pixel_put(aux, fdf);
	i = fmin(aux->x1, aux->x2);
	while (i < fmax(aux->x1, aux->x2))
	{
		aux->x = aux->x + 1;
		if (aux->p >= 0)
		{
			if ((aux->dx * aux->dy) >= 0)
				aux->y = aux->y + 1;
			else
				aux->y = aux->y - 1;
			aux->p = aux->p + 2 * (fabs(aux->dy) - fabs(aux->dx));
		}
		else
		{
			aux->y = aux->y;
			aux->p = aux->p + 2 * fabs(aux->dy);
		}
		img_pixel_put(aux, fdf);
		i++;
	}
}

void	ft_bresenham_y(t_aux *aux, t_fdf *fdf)
{
	double	i;

	img_pixel_put(aux, fdf);
	i = fmin(aux->y1, aux->y2);
	while (i < fmax(aux->y1, aux->y2))
	{
		aux->y = aux->y + 1;
		if (aux->p >= 0)
		{
			if ((aux->dx * aux->dy) >= 0)
				aux->x = aux->x + 1;
			else
				aux->x = aux->x - 1;
			aux->p = aux->p + 2 * (fabs(aux->dx) - fabs(aux->dy));
		}
		else
		{
			aux->x = aux->x;
			aux->p = aux->p + 2 * fabs(aux->dx);
		}
		img_pixel_put(aux, fdf);
		i++;
	}
}

void	ft_bresenhamaux(t_aux *aux, t_fdf *fdf)
{
	if (aux->y1 < aux->y2)
	{
		aux->x = aux->x1;
		aux->y = aux->y1;
	}
	else
	{
		aux->x = aux->x2;
		aux->y = aux->y2;
	}
	aux->p = 2 * fabs(aux->dx) - fabs(aux->dy);
	ft_bresenham_y(aux, fdf);
}

void	ft_bresenham(t_aux *aux, t_fdf *fdf)
{
	aux->dx = aux->x2 - aux->x1;
	aux->dy = aux->y2 - aux->y1;
	if (fabs(aux->dx) > fabs(aux->dy))
	{
		if (aux->x1 < aux->x2)
		{
			aux->x = aux->x1;
			aux->y = aux->y1;
		}
		else
		{
			aux->x = aux->x2;
			aux->y = aux->y2;
		}
		aux->p = 2 * fabs(aux->dy) - fabs(aux->dx);
		ft_bresenham_x(aux, fdf);
	}
	else
		ft_bresenhamaux(aux, fdf);
}
