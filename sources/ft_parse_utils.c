/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:28:46 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:48:47 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**ft_readmap(char *argv)
{
	char	**matrix;
	char	*line;
	int		fd;
	int		x;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	matrix[x++] = line;
	while(line)
	{
		line = get_next_line(fd);
		matrix[x++] = line;
	}
	return(matrix);
}

char	*getnum_z(char *str, int x, int y, t_p ***p)
{
	int	i;

//20,0xFF0000
	i = 0;
	while(str[i])
	{
		if(str[i] == ',')
		{
			p[x][y]->color = ft_substr(str[i], i, ft_strlen(str));
			break ;
		}
	}
	p[x][y]->z = ft_atoi(str);
}

char	**ft_getmatrix_z(char *argv, t_fdf *fdf, t_p ***p)
{
	char	**matrix;
	int		x;
	int		y;
	int		j;

	matrix = ft_readmap(argv);
	x = 0;
	while(x < fdf->lines)
	{
		y = 0;
		j = 0;
		while(y < fdf->nums)
		{
			if(matrix[x][y] == ' ')
			{
				matrix[x][y] = ft_getnum_z(ft_substr(matrix[x], j, y), x, y, p);
				j = y;
			}
			y++;
		}
		x++;
	}
}

void	ft_getz(t_p ***p, t_fdf *fdf, char *argv)
{
	int		x;
	int		y;
	char	**matrix;

	matrix = ft_getmatrix_z(argv, fdf, p);
	x = 0;
	while(x < fdf->lines)
	{
		y = 0;
		while(y < fdf->nums)
		{
			
			y++;
		}
		x++;
	}	
}
