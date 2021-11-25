/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:36:13 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:16:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_line1_x(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].y;//Cambio los valores para pintarlo bien
	aux->y1 = (*p)[x][y].x;
	aux->x2 = (*p)[x][y + 1].y;
	aux->y2 = (*p)[x][y + 1].x;
}

void	ft_line1_y(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].y;
	aux->y1 = (*p)[x][y].x;
	aux->x2 = (*p)[x + 1][y].y;
	aux->y2 = (*p)[x + 1][y].x;
}

void	ft_line2(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].y;
	aux->y1 = (*p)[x][y].x;
	aux->x2 = (*p)[x + 1][y].y;
	aux->y2 = (*p)[x + 1][y].x;
}

void	ft_line3(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].y;
	aux->y1 = (*p)[x][y].x;
	aux->x2 = (*p)[x][y + 1].y;
	aux->y2 = (*p)[x][y + 1].x;
}

void	ft_putlines(t_p ***p, t_fdf *fdf, int x, int y)
{
	t_aux	aux;

	if(fdf->flag == 1)
	{
		ft_line1_x(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
		ft_line1_y(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
	}
	else if(fdf->flag == 2)
	{
		ft_line2(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
	}
	else if(fdf->flag == 3)
	{
		ft_line3(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
	}
}
