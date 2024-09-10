/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:22 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/01 18:02:56 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	make_window(t_frac *f, char *set)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		help_message(WIN_ERROR);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, set);
	if (f->win == NULL)
		help_message(WIN_ERROR);
	f->img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->img_ptr == NULL)
		help_message(WIN_ERROR);
	f->img_addr = \
	mlx_get_data_addr(f->img_ptr, &f->bpp, &f->size_line, &f->endian);
	if (f->img_addr == NULL)
		help_message(WIN_ERROR);
}

int	set_value(t_frac *f, char **argv, char set_type)
{
	if (set_type == 'J')
	{
		f->cmplx_re = ft_atod(argv[2]);
		f->cmplx_im = ft_atod(argv[3]);
	}
	f->top = 2;
	f->bottom = -2;
	f->left = -2;
	f->right = 2;
	f->move_x = 0;
	f->move_y = 0;
	f->zoom = 1;
	f->set_type = set_type;
	return (1);
}

int	check_set_type(t_frac *f, int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			return (set_value(f, argv, 'M'));
		else if (ft_strcmp(argv[1], "Burningship") == 0)
			return (set_value(f, argv, 'B'));
	}
	else if (argc == 4)
	{
		if (ft_strcmp(argv[1], "Julia") == 0)
			return (set_value(f, argv, 'J'));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_frac	f;

	if (check_set_type(&f, argc, argv))
	{
		help_message(HOW_TO_CONTROL);
		make_window(&f, argv[1]);
		draw_fractal(&f);
		mlx_key_hook(f.win, &key_press, &f);
		mlx_mouse_hook(f.win, &mouse_press, &f);
		mlx_hook(f.win, 17, 0, exit_hook, 0);
		mlx_loop(f.mlx);
	}
	else
		help_message(ARG_ERROR);
	return (0);
}
