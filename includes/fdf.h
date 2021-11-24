/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:22:32 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/24 18:02:45 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define PIPEX_H

# include <stdlib.h>

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
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		*get_next_line(int fd);



#endif