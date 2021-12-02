/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:36:13 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 16:05:16 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_line1_x(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].x;
	aux->y1 = (*p)[x][y].y;
	aux->c1 = (*p)[x][y].color;
	aux->x2 = (*p)[x][y + 1].x;
	aux->y2 = (*p)[x][y + 1].y;
	aux->c2 = (*p)[x][y + 1].color;
}

void	ft_line1_y(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].x;
	aux->y1 = (*p)[x][y].y;
	aux->c1 = (*p)[x][y].color;
	aux->x2 = (*p)[x + 1][y].x;
	aux->y2 = (*p)[x + 1][y].y;
	aux->c2 = (*p)[x + 1][y].color;
}

void	ft_line2(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].x;
	aux->y1 = (*p)[x][y].y;
	aux->c1 = (*p)[x][y].color;
	aux->x2 = (*p)[x + 1][y].x;
	aux->y2 = (*p)[x + 1][y].y;
	aux->c2 = (*p)[x + 1][y].color;
}

void	ft_line3(t_p ***p, t_aux *aux, int x, int y)
{
	aux->x1 = (*p)[x][y].x;
	aux->y1 = (*p)[x][y].y;
	aux->c1 = (*p)[x][y].color;
	aux->x2 = (*p)[x][y + 1].x;
	aux->y2 = (*p)[x][y + 1].y;
	aux->c2 = (*p)[x][y + 1].color;
}

void	ft_putlines(t_p ***p, t_fdf *fdf, int x, int y)
{
	t_aux	aux;

	if (fdf->flag == 1)
	{
		ft_line1_x(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
		ft_line1_y(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
	}
	else if (fdf->flag == 2)
	{
		ft_line2(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
	}
	else if (fdf->flag == 3)
	{
		ft_line3(p, &aux, x, y);
		ft_bresenham(&aux, fdf);
	}
}
