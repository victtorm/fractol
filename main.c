/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:13:10 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/27 16:51:44 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	koch(t_fractal *koch, char *set)
{
	koch->set = set;
	init_koch(koch);
	koch_events(koch);
	koch_img(koch);
	mlx_loop(koch->mlx_connection);
}

void	julia(t_fractal *fractal, char *f, char *r, char *i)
{
	fractal->set = f;
	fractal->c.r = ato_db(r);
	fractal->c.i = ato_db(i);
	fractal_init(fractal);
	fractal_events(fractal);
	fractal_img(fractal);
	mlx_loop(fractal->mlx_connection);
}

void	mandelbrot(t_fractal *fractal, char *f)
{
	fractal->set = f;
	fractal_init(fractal);
	fractal_events(fractal);
	fractal_img(fractal);
	mlx_loop(fractal->mlx_connection);
}

void	mandelbrot_and_julia(t_fractal *fractal, char *f1, char *f2)
{
	t_fractal	julia;

	fractal->set = f1;
	julia.set = f2;
	fractal->to_fractol = &julia;
	julia.to_fractol = fractal;
	fractal_init(fractal);
	fractal->maj = true;
	julia.mlx_connection = fractal->mlx_connection;
	julia.mlx_window = mlx_new_window(julia.mlx_connection,
			WIDTH, HEIGHT, julia.set);
	julia.img = mlx_new_image(julia.mlx_connection,
			WIDTH, HEIGHT);
	julia.pixels_adr = mlx_get_data_addr(julia.img,
			&julia.bits_per_pixel, &julia.line_len, &julia.endian);
	start_fractal(&julia);
	fractal_events(fractal);
	fractal_events(&julia);
	fractal_img(&julia);
	fractal_img(fractal);
	mlx_loop(fractal->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && (!check_mandelbrot(argv[1], "mandelbrot")))
		mandelbrot(&fractal, argv[1]);
	else if (argc == 4 && (!check_julia(argv[1], "julia", argv[2], argv[3])))
		julia(&fractal, argv[1], argv[2], argv[3]);
	else if (argc == 2 && (!check_koch(argv[1], "koch")))
		koch(&fractal, argv[1]);
	else if (argc == 3 && (!check_mandelbrot(argv[1], "mandelbrot"))
		&& !check_julia(argv[2], "julia", "0", "0"))
		mandelbrot_and_julia(&fractal, argv[1], argv[2]);
	else
		fractal_error();
	return (0);
}
