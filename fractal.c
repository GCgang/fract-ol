/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:06:20 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/01 18:02:58 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot(t_frac *f, int w_x, int w_y)
{
	int		iter;
	double	x;
	double	y;
	double	temp;

	iter = 0;
	x = 0;
	y = 0;
	f->cmplx_re = \
	w_x * (f->right - f->left) / (double)WIDTH + f->left + f->move_x;
	f->cmplx_im = \
	w_y * (f->bottom - f->top) / (double)HEIGHT + f->top + f->move_y;
	while (((x * x) + (y * y) < 4) && (iter < ITER_MAX))
	{
		temp = (x * x) - (y * y) + f->cmplx_re;
		y = (2 * x * y) + f->cmplx_im;
		x = temp;
		iter++;
	}
	return (iter);
}

int	julia(t_frac *f, int w_x, int w_y)
{
	int		iter;
	double	x;
	double	y;
	double	temp;

	iter = 0;
	x = w_x * (f->right - f->left) / (double)WIDTH + f->left + f->move_x;
	y = w_y * (f->bottom - f->top) / (double)HEIGHT + f->top + f->move_y;
	while (((x * x) + (y * y) < 4) && (iter < ITER_MAX))
	{
		temp = (x * x) - (y * y) + f->cmplx_re;
		y = (2 * x * y) + f->cmplx_im;
		x = temp;
		iter++;
	}
	return (iter);
}

int	burningship(t_frac *f, int w_x, int w_y)
{
	int		iter;
	double	x;
	double	y;
	double	temp;

	iter = 0;
	x = 0;
	y = 0;
	f->cmplx_re = \
	w_x * (f->right - f->left) / (double)WIDTH + f->left + f->move_x;
	f->cmplx_im = \
	w_y * (f->bottom - f->top) / (double)HEIGHT + f->top + f->move_y;
	while (((x * x) + (y * y) < 4) && (iter < ITER_MAX))
	{
		temp = (x * x) - (y * y) + f->cmplx_re;
		y = -1 * fabs(2 * x * y) + f->cmplx_im;
		x = temp;
		iter++;
	}
	return (iter);
}
