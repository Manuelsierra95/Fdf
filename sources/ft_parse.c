/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:35:03 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:09:39 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mapsize(t_fdf *fdf, char *argv)
{
	int	y;

	y = 0;
	while(argv[y])
	{
		if(argv[y] == ' ')
		{
			fdf->sizex = ft_atoi(ft_substr(argv, 0, y));
			fdf->sizey = ft_atoi(ft_substr(argv, y + 1, ft_strlen(argv)));
			break ;
		}
		y++;
	}
}

void	ft_getpixels(t_p ***p, t_fdf *fdf)
{
	int	x;
	int	y;
	int	sizey;

	fdf->spacex = (fdf->sizex - (fdf->sizex * 0.2)) / (fdf->lines - 1);
	fdf->spacey = (fdf->sizey - (fdf->sizey * 0.2)) / (fdf->nums - 1);
	fdf->sizex = fdf->sizex - (fdf->sizex * 0.1);
	// printf("spaceX: %d\tspaceY: %d\n", fdf->spacex, fdf->spacey);
	*p = (t_p **) malloc(fdf->lines * sizeof(t_p*));
	x = 0;
	while(x < fdf->lines)
	{
		y = 0;
		sizey = fdf->sizey - (fdf->sizey * 0.1);
		(*p)[x] = (t_p *) malloc(fdf->nums * sizeof(t_p));
		while(y < fdf->nums)
		{
			(*p)[x][y].x = fdf->sizex;
			(*p)[x][y].y = sizey;
			sizey = sizey - fdf->spacey;
			y++;
		}
		fdf->sizex = fdf->sizex - fdf->spacex;
		x++;
	}
}

void	ft_getmatrixsize(t_fdf *fdf, char *argv)
{
	char	*aux;
	char	*line;
	int		fd;
	int		i;
	
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	aux = line;
	i = 0;
	while(line)
	{
		line = get_next_line(fd);
		fdf->lines++;
	}
	i = 0;
	while(aux[i])
	{
		if(aux[i] != ' ')
		{
			fdf->nums++;
			i++;
		}
		i++;
	}
	printf("Nums: %d\n", fdf->nums);
}

void	ft_getmatrix_flag(t_fdf *fdf, int x, int y)
{
	if(y + 1 < fdf->nums && x + 1 < fdf->lines)
		fdf->flag = 1;	
	else if(y + 1 == fdf->nums && x + 1 < fdf->lines)
		fdf->flag = 2;
	else if(y + 1 < fdf->nums && x + 1 == fdf->lines)
		fdf->flag = 3;		
}

void	ft_getmatrix(t_p ***p, t_fdf *fdf, char *argv)
{
	int		x;
	int		y;

	ft_getpixels(p, fdf);
	// ft_getz(p, fdf, argv);
	x = 0;
	while(x < fdf->lines)
	{
		y = 0;
		while(y < fdf->nums)
		{
			ft_getmatrix_flag(fdf, x, y);
			if(y + 1 < fdf->nums && x + 1 < fdf->lines) //si existe su siguiente en columna y fila
				ft_putlines(p, fdf, x, y);
			else if(y + 1 == fdf->nums && x + 1 < fdf->lines) //si existe solo su siguiente en fila
				ft_putlines(p, fdf, x, y);
			else if(y + 1 < fdf->nums && x + 1 == fdf->lines) //si exite solo su siguiente en columna
				ft_putlines(p, fdf, x, y);
			y++;
		}
		x++;
	}
}