/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:24 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/27 17:30:53 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_position(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_destroy_image(fractal->to_fractol->mlx_connection,
		fractal->to_fractol->img);
	fractal->to_fractol->img
		= mlx_new_image(fractal->to_fractol->mlx_connection, WIDTH, HEIGHT);
	mlx_mouse_get_pos(fractal->mlx_connection, fractal->mlx_window, &x, &y);
	fractal->to_fractol->c.r = scale(x, -2.2, 1.2, WIDTH)
		* fractal->zoom + fractal->r_move;
	fractal->to_fractol->c.i = scale(y, 1.5, -1.5, HEIGHT)
		* fractal->zoom + fractal->i_move;
	fractal_img(fractal->to_fractol);
	return (0);
}

int	close_window(t_fractal *fractal)
{
	if (fractal->maj == true)
	{
		mlx_destroy_image(fractal->to_fractol->mlx_connection,
			fractal->to_fractol->img);
		mlx_destroy_window(fractal->to_fractol->mlx_connection,
			fractal->to_fractol->mlx_window);
	}
	mlx_destroy_image(fractal->mlx_connection, fractal->img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free (fractal->mlx_connection);
	exit(1);
}

int	mouse_imput(int button, int x, int y, t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	mlx_mouse_get_pos(fractal->mlx_connection, fractal->mlx_window, &x, &y);
	if (button == 4)
		zoom_in(fractal, x, y);
	if (button == 5)
		zoom_out(fractal, x, y);
	fractal_img(fractal);
	return (0);
}

int	key_imput(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_window(fractal);
	mlx_destroy_image(fractal->mlx_connection, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (keysym == XK_Up)
		fractal->i_move += (0.8 * fractal->zoom);
	if (keysym == XK_Down)
		fractal->i_move -= (0.8 * fractal->zoom);
	if (keysym == XK_Left)
		fractal->r_move -= (0.8 * fractal->zoom);
	if (keysym == XK_Right)
		fractal->r_move += (0.8 * fractal->zoom);
	if (keysym == XK_KP_Add)
		fractal->inter += 10;
	if (keysym == XK_KP_Subtract)
		fractal->inter -= 10;
	if (fractal->inter < 10 || fractal->inter > 150)
		fractal->inter = 50;
	if (keysym == XK_Shift_L)
		change_color(fractal);
	fractal_img(fractal);
	return (0);
}

void	fractal_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_imput, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask,
		mouse_imput, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_window, fractal);
	if (fractal->maj)
		mlx_loop_hook(fractal->mlx_connection, mouse_position, fractal);
}
