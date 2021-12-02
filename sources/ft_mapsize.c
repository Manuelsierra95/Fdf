/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:04:05 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:55:49 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_getmatrixnums(char *aux, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (aux[i])
	{
		if (aux[i] >= '0' && aux[i] <= '9')
		{
			while (aux[i] != ' ' && aux[i])
				i++;
			fdf->nums++;
		}
		if (aux[i])
			i++;
	}
	free(aux);
}

void	ft_getmatrixlines(t_fdf *fdf, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		ft_errormsg(4);
	ft_getmatrixnums(line, fdf);
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		fdf->lines++;
		free(line);
	}
}

void	ft_calculatespace(t_fdf *fdf)
{
	fdf->spacex = (fdf->sizex - (fdf->sizex * 0.5)) / (fdf->lines - 1);
	fdf->spacey = (fdf->sizey - (fdf->sizey * 0.5)) / (fdf->nums - 1);
	fdf->spacex = fdf->spacex * -1;
	fdf->spacey = fdf->spacey * -1;
}

void	ft_mapsize(t_fdf *fdf, char *argv)
{
	int		y;
	char	*size1;
	char	*size2;

	y = 0;
	while (argv[y])
	{
		if (argv[y] == ' ')
		{
			size1 = ft_substr(argv, 0, y);
			fdf->sizex = ft_atoi(size1);
			size2 = ft_substr(argv, y + 1, ft_strlen(argv));
			fdf->sizey = ft_atoi(size2);
			free(size1);
			free(size2);
			break ;
		}
		y++;
	}
	if (fdf->sizex < 500 || fdf->sizey < 500)
		ft_errormsg(1);
	ft_calculatespace(fdf);
}

void	ft_mapsize2(t_fdf *fdf)
{
	fdf->sizex = 1000;
	fdf->sizey = 1000;
	ft_calculatespace(fdf);
}
