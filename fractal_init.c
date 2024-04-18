/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:23:50 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/18 18:31:30 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void    start_fractal(t_fractal *fractal)
{
    fractal->r_move = 0;
    fractal->i_move = 0;
    fractal->zoom = 1;
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    //if (fractal->mlx_connection == NULL)
        //error
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
                                            WIDTH, HEIGHT, fractal->set);
    /*if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        //erro
    }*/
    fractal->img = mlx_new_image(fractal->mlx_connection,
                                            WIDTH, HEIGHT);
    /*if (fractal->img == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        //erro
    }*/
    fractal->pixels_adr = mlx_get_data_addr(fractal->img,
                            &fractal->bits_per_pixel, &fractal->line_len, &fractal->endian);
    start_fractal(fractal);
}
