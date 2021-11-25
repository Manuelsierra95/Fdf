/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:22:32 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/25 18:26:21 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define PIPEX_H

# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*image;
	int		sizex;
	int		sizey;
	int		spacex;
	int		spacey;
	int		nums;
	int		lines;
	int		flag;
}	t_fdf;
typedef struct s_pixels
{
	int			x;
	int			y;
	int			z;
	char		*color;
}	t_p;
typedef struct s_aux
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	p;
}	t_aux;
char		*ft_substr(const char *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);
void		*ft_bzero(void *s, size_t n);

void	ft_putlines(t_p ***p, t_fdf *fdf, int x, int y);
void	ft_bresenham(t_aux *aux, t_fdf *fdf);
void	ft_mapsize(t_fdf *fdf, char *argv);
void	ft_getmatrixsize(t_fdf *fdf, char *argv);
void	ft_getmatrix(t_p ***p, t_fdf *fdf, char *argv);

void	ft_is_iso();
void	ft_isometric();

#endif