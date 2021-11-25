/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:44:22 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:47:59 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	leer el archivo que me dan con get_next_line , contar el numero de columnas filtrando por 'espacios'
	contar el numero de lineas.
	Crear una matriz de numeros y unir el las coordenadas con el siguiente de su linea y con la posicion
	correspondiente de la fila de abajo.
	
	**Matriz creada**
	**Dibujo en 2d hecho**
	**TODO: Errores, hacer que abra el archivo del mapa por parametro
			Meter en la matriz **p tanto color como "z" en el ft_parse_utils
	
	Errores:
		Proteger que el archivo no sea null con el gnl.
		
*/

#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	t_fdf		fdf;
	t_p	**p;

	fdf.lines = 0;
	fdf.nums = 0;

    // mlx_pixel_put(fdf.mlx, fdf.win, 640, 360, 0xFFFFFF);
	
	ft_mapsize(&fdf, argv[2]);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.sizex, fdf.sizey, "fdf");
	ft_getmatrixsize(&fdf, argv[1]);
	ft_getmatrix(&p, &fdf, argv[1]);

    mlx_loop(fdf.mlx);
}