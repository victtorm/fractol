/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:00:42 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/16 19:17:18 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double u_num, double n_min, double n_max, double o_max)
{
	double	result;

	result = (n_max - n_min) * u_num / o_max + n_min;
	return (result);
}

static void	scale_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			interactions;
	int			color;

	interactions = 0;
	z.r = (scale(x, -2, 2, 0, WIDTH)) * fractal->zoom + fractal->r_move;
	z.i = (scale(y, 2, -2, 0, HEIGHT)) * fractal->zoom + fractal->i_move;
	c.r = fractal->c_real;
	c.i = fractal->c_imaginary;
	while (150 > interactions)
	{
		z = ft_square(z);
		z = ft_sum(z, c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			color = scale(interactions, BLACK, WHITE, 0, 150);
			mlx_pixel_put(fractal->mlx_connection, fractal->mlx_window,
				z.real, z.imaginary, color);
			return ;
		}
		interactions ++;
	}
	mlx_pixel_put(fractal->mlx_connection, fractal->mlx_window,
		z.r, z.i, WHITE);
}

void	fractal_img(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			scale_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
