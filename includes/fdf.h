/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:22:32 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:50:07 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_data;
typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_data		img;
	double		sizex;
	double		sizey;
	double		spacex;
	double		spacey;
	int			nums;
	int			lines;
	int			flag;
}	t_fdf;
typedef struct s_pixels
{
	double		x;
	double		y;
	double		z;
	char		*color;
}	t_p;
typedef struct s_aux
{
	char	*c1;
	char	*c2;
	double	x;
	double	y;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	dx;
	double	dy;
	double	p;
}	t_aux;
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_color;
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *s, size_t n);
int		ft_toupper(int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *temp, char *s2);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putlines(t_p ***p, t_fdf *fdf, int x, int y);
void	ft_bresenham(t_aux *aux, t_fdf *fdf);
void	ft_mapsize(t_fdf *fdf, char *argv);
void	ft_getmatrixsize(t_fdf *fdf, char *argv);
void	ft_getmatrix(t_p ***p, t_fdf *fdf, char *argv);
void	ft_getz(char *argv, t_fdf *fdf, t_p ***p);
void	ft_getcolor(char **str, int x, t_p ***p, t_fdf *fdf);
void	ft_getz2(char **str, int x, t_p ***p, t_fdf *fdf);
void	ft_changematrix(t_p ***p, t_fdf *fdf);
int		ft_parsecolor(char *str, t_color *color);
int		ft_drawcolor(t_aux *aux, int red, int green);
void	ft_imagedraw(t_fdf *fdf);
void	img_pixel_put(t_aux *aux, t_fdf *fdf);
void	ft_mapsize2(t_fdf *fdf);
void	free_fdf(t_p ***p, t_fdf *fdf);
void	ft_errormsg(int flag);
void	ft_getmatrixlines(t_fdf *fdf, int fd);
#endif