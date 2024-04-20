/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:13:10 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/20 16:49:18 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		maj(t_fractal *fractal, t_fractal *julia, int argc)
{
	if (argc == 3)
	{
		fractal->maj = 2;
		fractal->to_fractol = julia;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_fractal	julia;

	if (argc == 3)
	{
		fractal.set = argv[1];
		julia.set = argv[2];
		maj(&fractal, &julia, argc);
		fractal_init(&fractal);
		julia.mlx_connection = fractal.mlx_connection;
		fractal_init(&julia);
		fractal_events(&fractal, &julia);
		fractal_img(&julia);
		fractal_img(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	/*else if ((argc == 2 && (!check_mandelbrot(argv[1], "mandelbrot")))
		|| (argc == 4 && (!check_julia(argv[1], "julia", argv[2], argv[3]))))
	{
		fractal.set = argv[1];
		if (argc == 4)
		{
			//fractal.c.r = atobd(argv[2]);
			fractal.c.i = atobd(argv[3]);
		}
		fractal_init(&fractal);
		fractal_events(&fractal);
		fractal_img(&fractal);
		mlx_loop(fractal.mlx_connection);
	}*/
	return (0);
}

