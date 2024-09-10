/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:14:13 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/01 18:02:57 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	exit_hook(void)
{
	exit(0);
}

int	key_press(int keycode, t_frac *f)
{
	if (keycode == KEY_ESC || keycode == KEY_X)
		exit(0);
	else if (keycode == KEY_UP)
		f->move_y = f->move_y + 0.1;
	else if (keycode == KEY_DOWN)
		f->move_y = f->move_y - 0.1;
	else if (keycode == KEY_LEFT)
		f->move_x = f->move_x - 0.1;
	else if (keycode == KEY_RIGHT)
		f->move_x = f->move_x + 0.1;
	else if (keycode == COLOR_ONE || \
			keycode == COLOR_TWO || \
			keycode == COLOR_THREE || \
			keycode == COLOR_FOUR || \
			keycode == COLOR_FIVE)
		f->color_flag = keycode;
	redraw(f);
	return (0);
}

void	zoom(t_frac *f, int x, int y)
{
	double	new_width;
	double	new_height;
	double	x_length;
	double	y_length;

	new_width = f->zoom * COMPLEX_WIDTH;
	new_height = -1 * f->zoom * COMPLEX_HEIGHT;
	x_length = f->right - f->left;
	y_length = f->bottom - f->top;
	f->left = \
	f->left + x * x_length / (double)WIDTH - x * (new_width / (double)WIDTH);
	f->top = \
	f->top + y * y_length / (double)HEIGHT - y * (new_height / (double)HEIGHT);
	f->right = f->left + new_width;
	f->bottom = f->top + new_height;
	redraw(f);
}

int	mouse_press(int mousecode, int x, int y, t_frac *f)
{
	if (mousecode == MOUSE_SCROLL_UP)
	{
		f->zoom /= 1.1;
		zoom(f, x, y);
	}
	else if (mousecode == MOUSE_SCROLL_DOWN)
	{
		f->zoom *= 1.1;
		zoom(f, x, y);
	}
	return (0);
}
