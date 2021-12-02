/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:54:56 by msierra-          #+#    #+#             */
/*   Updated: 2021/12/02 17:55:14 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_putstringerror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 2);
		i++;
	}
	exit(0);
}

void	ft_errormsg(int flag)
{
	if (flag == 1)
		ft_putstringerror("Window to small, change the args\n");
	else if (flag == 2)
		ft_putstringerror("Bad infile\n");
	else if (flag == 3)
		ft_putstringerror("Error: Insufficient number of arguments\n");
	else if (flag == 4)
		ft_putstringerror("Incorrect map\n");
}
