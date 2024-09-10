/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:05:58 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/01 17:17:20 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	redraw(t_frac *f)
{
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f);
}

int	get_color(t_frac *f, int iter)
{
	int		color;

	color = 0x00F8F8FF;
	if (f->color_flag == COLOR_ONE)
		color = 0x00fff5ee;
	else if (f->color_flag == COLOR_TWO)
		color = 0x00F0FFF0;
	else if (f->color_flag == COLOR_THREE)
		color = 0xf0f8ff;
	else if (f->color_flag == COLOR_FOUR)
		color = 0xdcdcdc;
	else if (f->color_flag == COLOR_FIVE)
		color = 0x00FFF0F5;
	return (color * iter);
}

void	my_mlx_pixel_put(t_frac *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img_addr + (y * f->size_line + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_iter(t_frac *f, int x, int y)
{
	if (f->set_type == 'M')
		return (mandelbrot(f, x, y));
	else if (f->set_type == 'J')
		return (julia(f, x, y));
	else if (f->set_type == 'B')
		return (burningship(f, x, y));
	exit(1);
}

void	draw_fractal(t_frac *f)
{
	int	w_x;
	int	w_y;
	int	iter;
	int	color;

	w_y = -1;
	while (++w_y <= HEIGHT)
	{
		w_x = -1;
		while (++w_x <= WIDTH)
		{
			iter = get_iter(f, w_x, w_y);
			if (iter < ITER_MAX)
			{
				color = get_color(f, iter);
				my_mlx_pixel_put(f, w_x, w_y, color);
			}
			else if (iter == ITER_MAX)
				my_mlx_pixel_put(f, w_x, w_y, 0X00000000);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img_ptr, 0, 0);
}
