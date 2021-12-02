/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:44:22 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:54:42 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	destroy_win(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		exit(0);
	}
	return (0);
}

int	close_win(void)
{
	exit(0);
	return (0);
}

void	create_key_hook(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, destroy_win, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, close_win, fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_p		**p;

	if (argc == 1)
		ft_errormsg(3);
	fdf.mlx = mlx_init();
	ft_getmatrixsize(&fdf, argv[1]);
	if (argv[2])
		ft_mapsize(&fdf, argv[2]);
	else
		ft_mapsize2(&fdf);
	fdf.win = mlx_new_window(fdf.mlx, fdf.sizex, fdf.sizey, "fdf");
	ft_imagedraw(&fdf);
	ft_getmatrix(&p, &fdf, argv[1]);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	create_key_hook(&fdf);
	mlx_loop(fdf.mlx);
}
