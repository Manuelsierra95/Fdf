/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:28:46 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:33:55 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**ft_readmap(char *argv, t_fdf *fdf)
{
	char	**matrix;
	int		fd;
	int		x;

	fd = open(argv, O_RDONLY);
	x = 0;
	matrix = (char **) malloc(fdf->lines * sizeof(char *));
	while (x < fdf->lines)
	{
		matrix[x] = get_next_line(fd);
		x++;
	}
	close(fd);
	return (matrix);
}

void	ft_getargs(char **str, int x, t_p ***p, t_fdf *fdf)
{
	int	i;

	ft_getz2(str, x, p, fdf);
	ft_getcolor(str, x, p, fdf);
	i = fdf->nums;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	ft_getz(char *argv, t_fdf *fdf, t_p ***p)
{
	char	**matrix;
	char	**auxmat;
	int		x;

	matrix = ft_readmap(argv, fdf);
	x = 0;
	while (x < fdf->lines)
	{
		auxmat = ft_split(matrix[x], ' ');
		ft_getargs(auxmat, x, p, fdf);
		x++;
	}
	x = fdf->lines - 1;
	while (x >= 0)
	{
		free(matrix[x]);
		x--;
	}
	free(matrix);
}
