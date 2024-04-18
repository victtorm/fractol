/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:13:10 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/18 18:42:49 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (!check_mandelbrot(argv[1], "mandelbrot")))
		|| (argc == 4 && (!check_julia(argv[1], "julia", argv[2], argv[3]))))
	{
		fractal.set = argv[1];
		if (argc == 4)
		{
			fractal.c.r = atodb(argv[2]);
			fractal.c.i = atodb(argv[3]);
		}
		fractal_init(&fractal);
		fractal_img(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	return (0);
}
