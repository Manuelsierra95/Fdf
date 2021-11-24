/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:44:22 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/24 19:40:00 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	leer el archivo que me dan con get_next_line , contar el numero de columnas filtrando por 'espacios'
	contar el numero de lineas.
	Crear una matriz de numeros y unir el las coordenadas con el siguiente de su linea y con la posicion
	correspondiente de la fila de abajo.
	
	**Matriz creada**
	**TODO: Errores, probar logaritmo de Bresenham
	
	Errores:
		Proteger que el archivo no sea null con el gnl.
		
*/

#include "../includes/fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

void	ft_countlines()
{
	
}

void	ft_countcolums()
{
	
}

void	ft_getpixels(t_p ***p, char *line, t_fdf *fdf)
{
	int	x;
	int	y;
	int	sizey;

	fdf->spacex = (fdf->sizex - (fdf->sizex * 0.2)) / (fdf->lines - 1);
	fdf->spacey = (fdf->sizey - (fdf->sizey * 0.2)) / (fdf->nums - 1);
	fdf->sizex = fdf->sizex - (fdf->sizex * 0.1);
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
			// printf("Matrix[%d][%d]\t", x, y);
			// printf("Xpixel: %d\tYpixel: %d\n", (*p)[x][y].px, (*p)[x][y].py);
			sizey = sizey - fdf->spacey;
			y++;
		}
		fdf->sizex = fdf->sizex - fdf->spacex;
		x++;
	}
}

void	ft_getmatrixsize(t_fdf *fdf)
{
	char	*aux;
	char	*line;
	int		fd;
	int		i;
	
	fd = open("42.fdf", O_RDONLY);
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
}

void	ft_bresenham_x(t_aux *aux, t_fdf *fdf)
{
	double	i;

	mlx_pixel_put(fdf->mlx, fdf->win, aux->x, aux->y, 0xFFFFFF);
	i = fmin(aux->x1, aux->x2);
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
		mlx_pixel_put(fdf->mlx, fdf->win, aux->x, aux->y, 0xFFFFFF);
		i++;
	}
}

void	ft_bresenham_y(t_aux *aux, t_fdf *fdf)
{
	double	i;

	mlx_pixel_put(fdf->mlx, fdf->win, aux->x, aux->y, 0xFFFFFF);
	i = fmin(aux->y1, aux->y2);
	while(i < fmax(aux->y1, aux->y2))
	{
		aux->y = aux->y + 1;
		if(aux->p >= 0)
		{
			if((aux->dx * aux->dy) >= 0)
				aux->x = aux->x + 1;
			else
				aux->x = aux->x - 1;
		}
		else
		{
			aux->x = aux->x;
			aux->p = aux->p + 2 * abs(aux->dy);
		}
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

void	ft_putlines(t_p ***p, t_fdf *fdf, int x, int y) //meterle flags
{
	t_aux	aux;

	printf("Matrix[%d][%d]\t", x, y);
	printf("Xpixel: %d\tYpixel: %d\n", (*p)[x][y].x, (*p)[x][y].y);
	printf("Xpixel: %d\tYpixel: %d\n", (*p)[x + 1][y + 1].x, (*p)[x + 1][y + 1].y);
	if(fdf->flag == 1)
	{
		aux.x1 = (*p)[x][y].x;
		aux.x2 = (*p)[x + 1][y + 1].x;
		aux.y1 = (*p)[x][y].y;
		aux.y2 = (*p)[x + 1][y + 1].y;
		ft_bresenham(&aux, fdf);
	}
}

void	ft_getmatrix(t_p ***p, t_fdf *fdf)
{
	char	*line;
	int		x;
	int		y;

	ft_getpixels(p, line, fdf);
	x = 0;
	while(x < fdf->lines)
	{
		y = 0;
		while(y < fdf->nums)
		{
			// printf("Matrix[%d][%d]\t", x, y);
			// printf("Xpixel: %d\tYpixel: %d\n", (*p)[x][y].x, (*p)[x][y].y);
			// mlx_pixel_put(fdf->mlx, fdf->win, (*p)[x][y].px, (*p)[x][y].py, 0xFFFFFF);
			if(y + 1 < fdf->nums && x + 1 < fdf->lines) //si existe su siguiente en columna y fila
			{
				fdf->flag = 1;
				ft_putlines(p, fdf, x, y);
			}	
			// else if(y + 1 == fdf->nums && x + 1 < fdf->lines) //si existe solo su siguiente en fila
			// {
			// 	fdf->flag = 2;
			// 	ft_putlines(p, fdf, x, y);
			// }
			// else if(y + 1 < fdf->nums && x + 1 == fdf->lines) //si exite solo su siguiente en columna
			// {
			// 	fdf->flag = 3;
			// 	ft_putlines(p, fdf, x, y);
			// }
			y++;
		}
		x++;
	}
}

void	ft_fdfthings(t_fdf *fdf, char *argv)
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
	// printf("X: %d\tY: %d\n", fdf->sizex, fdf->sizey);
}
int main(int argc, char **argv)
{
	t_fdf		fdf;
	t_p	**p;

	fdf.lines = 0;
	fdf.nums = 0;

    // mlx_pixel_put(fdf.mlx, fdf.win, 640, 360, 0xFFFFFF);
	
	ft_fdfthings(&fdf, argv[2]);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.sizex, fdf.sizey, "fdf");
	ft_getmatrixsize(&fdf);
	ft_getmatrix(&p, &fdf);

    mlx_loop(fdf.mlx);
}