/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:23:50 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/27 16:51:23 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_error(void)
{
	write(2, "Invalid Argumets.\n", 18);
	write(2, "Try use:\n", 10);
	write(2, "./fractol mandelbrot\n", 21);
	write(2, "./fractol julia double(real) souble(imaginary)\n", 47);
	write(2, "./fractol mandelbrot julia\n", 27);
	write(2, "./fractol koch\n", 15);
	exit(1);
}

void	start_fractal(t_fractal *fractal)
{
	fractal->r_move = 0;
	fractal->i_move = 0;
	fractal->zoom = 1;
	fractal->inter = 50;
	fractal->color_1 = WHITE;
	fractal->color_2 = BLACK;
	fractal->maj = false;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		free(fractal->mlx_connection);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->set);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	fractal->img = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	fractal->pixels_adr = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel, &fractal->line_len, &fractal->endian);
	start_fractal(fractal);
}
