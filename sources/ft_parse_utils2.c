/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:41:35 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:47:52 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_getcolor(char **str, int x, t_p ***p, t_fdf *fdf)
{
	int		y;
	int		i;
	char	*aux;

	y = 0;
	while (y < fdf->nums)
	{
		i = 0;
		while (str[y][i])
		{
			if (str[y][i] == 'x')
			{
				aux = ft_substr(str[y], i + 1, ft_strlen(str[y]));
				(*p)[x][y].color = aux;
			}
			i++;
		}
		if (!(*p)[x][y].color)
			(*p)[x][y].color = "FFFFFF";
		y++;
	}
}

void	ft_getz2(char **str, int x, t_p ***p, t_fdf *fdf)
{
	int		y;
	int		i;
	char	*aux;

	y = 0;
	while (y < fdf->nums)
	{
		i = 0;
		while (str[y][i])
		{
			if (str[y][i] == ',')
			{
				aux = ft_substr(str[y], 0, y);
				(*p)[x][y].z = ft_atoi(aux);
				free(aux);
				break ;
			}
			else
				(*p)[x][y].z = ft_atoi(str[y]);
			(*p)[x][y].color = NULL;
			i++;
		}
		y++;
	}
}

void	ft_change_pix(t_p ***p, int x, int y)
{
	int	pre_x;
	int	pre_y;

	pre_x = (*p)[x][y].x;
	pre_y = (*p)[x][y].y;
	(*p)[x][y].x = (pre_x - pre_y) * cos(-0.523599);
	(*p)[x][y].y = -((*p)[x][y].z) + (pre_x + pre_y) * sin(-0.523599);
}

void	ft_recalculatespace(t_p ***p, t_fdf *fdf, int x, int y)
{
	double	diagonal;
	double	center;

	diagonal = sqrt(pow(fdf->sizex, 2) + pow(fdf->sizey, 2));
	center = diagonal / 2;
	(*p)[x][y].x = (*p)[x][y].x - center / 4;
	(*p)[x][y].y = (*p)[x][y].y - center;
}

void	ft_changematrix(t_p ***p, t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < fdf->lines)
	{
		y = 0;
		while (y < fdf->nums)
		{
			ft_recalculatespace(p, fdf, x, y);
			ft_change_pix(p, x, y);
			y++;
		}
		x++;
	}
}
