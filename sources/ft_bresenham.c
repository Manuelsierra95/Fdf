/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:33:34 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:15:51 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham_x(t_aux *aux, t_fdf *fdf)
{
	double	i;

	// printf("X1: %d\tX2: %d\n", aux->x1, aux->x2);
	mlx_pixel_put(fdf->mlx, fdf->win, aux->x, aux->y, 0xFFFFFF);
	i = fmin(aux->x1, aux->x2);
	// printf("i/x: %f\n", i);
	while(i < fmax(aux->x1, aux->x2))
	{
		aux->x = aux->x + 1;
		if(aux->p >= 0)
		{
			if((aux->dx * aux->dy) >= 0)
				aux->y = aux->y + 1;
			else
				aux->y = aux->y - 1;
			aux->p = aux->p + 2 * (abs(aux->dy) - abs(aux->dx));
		}
		else
		{
			aux->y = aux->y;
			aux->p = aux->p + 2 * abs(aux->dy);
		}
		// printf("X: %d\tY: %d\n", aux->x, aux->y);
		mlx_pixel_put(fdf->mlx, fdf->win, aux->x, aux->y, 0xFFFFFF);
		i++;
	}
}

void	ft_bresenham_y(t_aux *aux, t_fdf *fdf)
{
	double	i;

	// printf("X: %d\tY: %d\n", aux->y1, aux->y2);
	mlx_pixel_put(fdf->mlx, fdf->win, aux->x, aux->y, 0xFFFFFF);
	i = fmin(aux->y1, aux->y2);
	// printf("i/y: %f\n", i);
	while(i < fmax(aux->y1, aux->y2))
	{
		aux->y = aux->y + 1;
		if(aux->p >= 0)
		{
			if((aux->dx * aux->dy) >= 0)
				aux->x = aux->x + 1;
			else
				aux->x = aux->x - 1;
			aux->p = aux->p + 2 * (abs(aux->dx) - abs(aux->dy));
		}
		else
		{
			aux->x = aux->x;
			aux->p = aux->p + 2 * abs(aux->dx);
		}
		// printf("X: %d\tY: %d\n", aux->x, aux->y);
		mlx_pixel_put(fdf->mlx, fdf->win, aux->x, aux->y, 0xFFFFFF);
		i++;
	}
}

void	ft_bresenhamaux(t_aux *aux, t_fdf *fdf)
{
	if(aux->y1 < aux->y2)
	{
		aux->x = aux->x1;
		aux->y = aux->y1;
	}
	else
	{
		aux->x = aux->x2;
		aux->y = aux->y2;
	}
	aux->p = 2 * abs(aux->dx) - abs(aux->dy);	
	ft_bresenham_y(aux, fdf);
}

void	ft_bresenham(t_aux *aux, t_fdf *fdf)
{
	aux->dx = aux->x2 - aux->x1;
	aux->dy = aux->y2 - aux->y1;
	if(abs(aux->dx) > abs(aux->dy))
	{
		if(aux->x1 < aux->x2)
		{
			aux->x = aux->x1;
			aux->y = aux->y1;
		}
		else
		{
			aux->x = aux->x2;
			aux->y = aux->y2;
		}
		aux->p = 2 * abs(aux->dy) - abs(aux->dx);
		ft_bresenham_x(aux, fdf);
	}
	else
		ft_bresenhamaux(aux, fdf);
}
