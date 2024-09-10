/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:54:27 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/01 18:02:57 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
		ft_putchar_fd(*s++, fd);
}

void	help_message(int flag)
{
	ft_putstr_fd("===================================================\n", 1);
	ft_putstr_fd("|                   HELP MESSAGE                  |\n", 1);
	ft_putstr_fd("===================================================\n", 1);
	if (flag == ARG_ERROR)
	{
		ft_putstr_fd("=======================MAKE========================\n", 2);
		ft_putstr_fd("| Make Mandelbrot   => ./fractal Mandelbrot       |\n", 2);
		ft_putstr_fd("| Make Julia        => ./fractal Julia -0.4 0.6   |\n", 2);
		ft_putstr_fd("| Make Burningship  => ./fractal Burningship      |\n", 2);
		ft_putstr_fd("===================================================\n", 2);
		exit(1);
	}
	else if (flag == WIN_ERROR)
	{
		ft_putstr_fd("                  Make window error                \n", 2);
		exit(1);
	}
	else if (flag == HOW_TO_CONTROL)
	{
		ft_putstr_fd("======================CONTROL======================\n", 1);
		ft_putstr_fd("| Move Screen       => press the arrow keys       |\n", 1);
		ft_putstr_fd("| Zoom in Zoom out  => scroll up & scroll down    |\n", 1);
		ft_putstr_fd("| Color Change      => press the number keys(1~5) |\n", 1);
		ft_putstr_fd("===================================================\n", 1);
	}
}
