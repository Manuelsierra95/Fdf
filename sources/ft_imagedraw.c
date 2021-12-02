/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imagedraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:59:34 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:10:56 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pixel_put(t_aux *aux, t_fdf *fdf)
{
	int	pixel;
	int	color;
	int	red;
	int	green;

	red = 0;
	green = 0;
	color = (int) ft_drawcolor(aux, red, green);
	pixel = ((int)aux->y * fdf->img.len) + ((int)aux->x * (fdf->img.bpp / 8));
	if (fdf->img.endian == 1)
	{
		fdf->img.addr[pixel + 0] = (color >> 24);
		fdf->img.addr[pixel + 1] = (color >> 16) & 0xFF;
		fdf->img.addr[pixel + 2] = (color >> 8) & 0xFF;
		fdf->img.addr[pixel + 3] = (color) & 0xFF;
	}
	else if (fdf->img.endian == 0)
	{
		fdf->img.addr[pixel + 0] = (color) & 0xFF;
		fdf->img.addr[pixel + 1] = (color >> 8) & 0xFF;
		fdf->img.addr[pixel + 2] = (color >> 16) & 0xFF;
		fdf->img.addr[pixel + 3] = (color >> 24);
	}
}

void	ft_imagedraw(t_fdf *fdf)
{
	fdf->img.img = mlx_new_image(fdf->mlx, fdf->sizex, fdf->sizey);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.len, &fdf->img.endian);
}
