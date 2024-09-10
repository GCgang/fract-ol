/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:06:04 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/02 11:49:09 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define KEY_ESC			53
# define KEY_X				7
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWN			125
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define WIDTH				800
# define HEIGHT				800
# define COMPLEX_WIDTH		4
# define COMPLEX_HEIGHT		4
# define ITER_MAX			100
# define ARG_ERROR			1
# define WIN_ERROR			2
# define HOW_TO_CONTROL		3
# define COLOR_ONE			18
# define COLOR_TWO			19
# define COLOR_THREE		20
# define COLOR_FOUR			21
# define COLOR_FIVE			23

typedef struct s_frac
{
	void	*mlx;
	void	*win;
	void	*key_param;
	void	*mouse_param;
	double	top;
	double	bottom;
	double	left;
	double	right;
	double	move_x;
	double	move_y;
	double	zoom;
	double	cmplx_re;
	double	cmplx_im;
	char	set_type;
	int		color_flag;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_frac;

void	redraw(t_frac *f);
int		get_color(t_frac *f, int iter);
void	my_mlx_pixel_put(t_frac *f, int x, int y, int color);
int		get_iter(t_frac *f, int x, int y);
void	draw_fractal(t_frac *f);
int		mandelbrot(t_frac *f, int w_x, int w_y);
int		julia(t_frac *f, int w_x, int w_y);
int		burningship(t_frac *f, int w_x, int w_y);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	help_message(int flag);
int		exit_hook(void);
int		key_press(int keycode, t_frac *f);
void	zoom(t_frac *f, int x, int y);
int		mouse_press(int mousecode, int x, int y, t_frac *f);
void	make_window(t_frac *f, char *set);
int		set_value(t_frac *f, char **argv, char set_type);
int		check_set_type(t_frac *f, int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
double	after_dot(char *str);
double	ft_atod(char *str);

#endif