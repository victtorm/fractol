/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:00:42 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/13 18:39:36 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

double  scale(double d, double size)
{
    double  result;
    
    result = 0;
    if (size = WIDTH)
        result = -4 * d / WIDTH - 2;
    if (size = HEIGHT)
        result = 4 * d / HEIGHT + 2;
    return (result);
}
static void scale_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;

    z.real = (scale(x, WIDTH)) + fractal->real_move;
    c.imaginary = (scale(y, HEIGHT)) + fractal->imaginary_move;

    
}


void    fractal_img(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
            scale_pixel(x, y, fractal);

    }
    mlx_put_image_to_window(fractal->mlx_connection,
                            fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}