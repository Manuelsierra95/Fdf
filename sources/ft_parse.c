/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:35:03 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:53:11 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_getpixels(t_p ***p, t_fdf *fdf)
{
	int		x;
	int		y;
	double	sizey;
	double	sizex;

	sizex = fdf->sizex - (fdf->sizex * 0.9);
	*p = (t_p **) malloc((fdf->lines + 1) * sizeof(void *));
	x = 0;
	while (x < fdf->lines)
	{
		y = 0;
		sizey = fdf->sizey - (fdf->sizey * 0.9);
		(*p)[x] = (t_p *) malloc((fdf->nums) * sizeof(t_p));
		while (y < fdf->nums)
		{
			(*p)[x][y].x = sizex;
			(*p)[x][y].y = sizey;
			sizey = sizey + fdf->spacey;
			y++;
		}
		sizex = sizex + fdf->spacex;
		x++;
	}
}

void	ft_getmatrix_flag(t_fdf *fdf, int x, int y)
{
	if (y + 1 < fdf->nums && x + 1 < fdf->lines)
		fdf->flag = 1;
	else if (y + 1 == fdf->nums && x + 1 < fdf->lines)
		fdf->flag = 2;
	else if (y + 1 < fdf->nums && x + 1 == fdf->lines)
		fdf->flag = 3;
}

void	freep(t_p ***p, t_fdf *fdf)
{
	int	x;
	int	y;

	x = fdf->lines - 1;
	while (x >= 0)
	{
		y = fdf->nums - 1;
		while (y >= 0)
		{
			free((*p)[x][y].color);
			y--;
		}
		free((*p)[x]);
		x--;
	}
	free(*p);
}

void	ft_getmatrixsize(t_fdf *fdf, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_errormsg(2);
	ft_getmatrixlines(fdf, fd);
	close(fd);
}

void	ft_getmatrix(t_p ***p, t_fdf *fdf, char *argv)
{
	int		x;
	int		y;

	ft_getpixels(p, fdf);
	ft_getz(argv, fdf, p);
	ft_changematrix(p, fdf);
	x = 0;
	while (x < fdf->lines)
	{
		y = 0;
		while (y < fdf->nums)
		{
			ft_getmatrix_flag(fdf, x, y);
			if (y + 1 < fdf->nums && x + 1 < fdf->lines)
				ft_putlines(p, fdf, x, y);
			else if (y + 1 == fdf->nums && x + 1 < fdf->lines)
				ft_putlines(p, fdf, x, y);
			else if (y + 1 < fdf->nums && x + 1 == fdf->lines)
				ft_putlines(p, fdf, x, y);
			y++;
		}
		x++;
	}
}
