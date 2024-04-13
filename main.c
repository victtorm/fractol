/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:13:10 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/13 16:52:03 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal   fractal;

    if ((argc == 2 && !check_mandelbrot(argv[1], "mandelbrot")) ||
            argc == 4 && !check_julia(argv[1], "julia", argv[2], argv[3]))
    {   
        fractal.set = argv[1];
        if (argc == 4)
            //JULIA things
        fractal_init(&fractal);
        fractal
        mlx_loop(fractal.mlx_connection);
        
        
        write (1, "ok\n", 3);
    }
    else 
        write (1, "ERROR\n", 6);
    //ERROR
    return (0);
}