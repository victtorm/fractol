/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:23:50 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/13 16:48:20 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include # include "fractol.h"

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        //error
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
                                            WIDTH, HEIGHT, fractal->set);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        //erro
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
                                            WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        //erro
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                            &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    



}