/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:00:42 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/18 18:59:22 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_start_c(t_fractal *fractal, t_complex z)
{
	if (fractal->set[0] == 'm')
	{
		fractal->c.r = z.r;
		fractal->c.i = z.i;
	}
	return ;
}

void	ft_put_pixels(t_fractal *fractal, int x, int y, int color)
{
	int	move;

	move = 0;
	move = (y * fractal->line_len) + (x * (fractal->bits_per_pixel / 8));
	*(unsigned int*)(fractal->pixels_adr + move) = color;

}	

double	scale(double u_num, double n_min, double n_max, double o_max)
{
	double	result;

	result = (n_max - n_min) * u_num / o_max + n_min;
	return (result);
}

static void	scale_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			interactions;
	int			color;

	interactions = 0;
	z.r = (scale(x, -2.2, 1.2, WIDTH)) * fractal->zoom + fractal->r_move;
	z.i = (scale(y, 1.5, -1.5, HEIGHT)) * fractal->zoom + fractal->i_move;
	set_start_c(fractal, z);
	while (1000 > interactions)
	{
		z = ft_square(z);
		z = ft_sum(z, fractal->c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			color = scale(interactions, BLACK, WHITE, 1000);
			ft_put_pixels(fractal, x, y, color);
			return ;
		}
		interactions ++;
	}
	ft_put_pixels(fractal, x, y, WHITE);
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
		fractal->mlx_window, fractal->img, 0, 0);
}
