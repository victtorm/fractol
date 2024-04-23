/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:04:50 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/23 17:57:51 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    change_color(t_fractal *fractal)
{
    if (fractal->maj == true)
        change_color(fractal->to_fractol);
    if (fractal->color_1 == WHITE)
    {
        fractal->color_1 = GREEN;
        fractal->color_2 = RED;
    }
    else if (fractal->color_1 == GREEN)
    {
        fractal->color_1 = PURPLE;
        fractal->color_2 = YELLOW;
    }
    else if (fractal->color_1 == PURPLE)
    {
        fractal->color_1 = WHITE;
        fractal->color_2 = BLACK;
    }
}
void    zoom_in(t_fractal *fractal, int x, int y)
{
    if (ft_strlen(fractal->set) == 10)
    {
        fractal->r_move += (scale(x, -2.2, 1.2, WIDTH)) * 0.13 * fractal->zoom;
        fractal->i_move += (scale(y, 1.5, -1.5, HEIGHT)) * 0.13 * fractal->zoom;
        fractal->zoom *= 0.9; 
    }
    else 
    {
        fractal->r_move += (scale(x, -2, 2, WIDTH)) * 0.13 * fractal->zoom;
        fractal->i_move += (scale(y, 2, -2, HEIGHT)) * 0.13 * fractal->zoom;
        fractal->zoom *= 0.9;
    }
}

void    zoom_out(t_fractal *fractal, int x, int y)
{
    if (ft_strlen(fractal->set) == 10)
    {
        fractal->r_move += (scale(x, -2.2, 1.2, WIDTH)) * 0.13 * fractal->zoom;
        fractal->i_move += (scale(y, 1.5, -1.5, HEIGHT)) * 0.13 * fractal->zoom;
        fractal->zoom *= 1.1; 
    }
    else 
    {
        fractal->r_move += (scale(x, -2, 2, WIDTH)) * 0.13 * fractal->zoom;
        fractal->i_move += (scale(y, 2, -2, HEIGHT)) * 0.13 * fractal->zoom;
        fractal->zoom *= 1.1;
    }
}
