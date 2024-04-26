/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:12:53 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/26 20:25:51 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void    draw_igual(t_fractal *koch, t_koch c, t_koch d)
{
    if (c.x > d.x)
    {
        while (c.x > d.x)
        {
            koch->c.r = c.x / koch->zoom + koch->r_move;
            koch->c.i = c.y / koch->zoom + koch->i_move;
            if (koch->c.i < HEIGHT && koch->c.i > 0 && koch->c.r < WIDTH && koch->c.r > 0)
                ft_put_pixels(koch, koch->c.r, koch->c.i, koch->color_1);
            c.x--;
        }
    }
    else 
    {
        while (c.x < d.x)
        {
            koch->c.r = c.x / koch->zoom + koch->r_move;
            koch->c.i = c.y / koch->zoom + koch->i_move;
            if (koch->c.i < HEIGHT && koch->c.i > 0 && koch->c.r < WIDTH && koch->c.r > 0)
                ft_put_pixels(koch, koch->c.r, koch->c.i, koch->color_1);
            c.x++;
        }
    }
}

void    draw_up(t_fractal *koch, t_koch c, t_koch d)
{   
    if (c.x > d.x)
    {
        while (c.x > d.x)
        {
            koch->c.r = c.x / koch->zoom + koch->r_move;
            koch->c.i = c.y / koch->zoom + koch->i_move;
            if (koch->c.i < HEIGHT && koch->c.i > 0 && koch->c.r < WIDTH && koch->c.r > 0)
                ft_put_pixels(koch, koch->c.r, koch->c.i, koch->color_1);
            c.x -= 1 /1.732;
            c.y++;
        }
    }
    else 
    {
        while (c.x < d.x)
        {
            koch->c.r = c.x / koch->zoom + koch->r_move;
            koch->c.i = c.y / koch->zoom + koch->i_move;
            if (koch->c.i < HEIGHT && koch->c.i > 0 && koch->c.r < WIDTH && koch->c.r > 0)
                ft_put_pixels(koch, koch->c.r, koch->c.i, koch->color_1);
            c.x += 1 /1.732;
            c.y++;
        }
    }
}

void    draw_down(t_fractal *koch, t_koch c, t_koch d)
{
    if (c.x > d.x)
    {
        while (c.x > d.x)
        {
            koch->c.r = c.x / koch->zoom + koch->r_move;
            koch->c.i = c.y / koch->zoom + koch->i_move;
            if (koch->c.i < HEIGHT && koch->c.i > 0 && koch->c.r < WIDTH && koch->c.r > 0)
                ft_put_pixels(koch, koch->c.r, koch->c.i, koch->color_1);
            c.x -= 1 /1.732;
            c.y--;
        }
    }
    else 
    {
        while (c.x < d.x)
        {
            koch->c.r = c.x / koch->zoom + koch->r_move;
            koch->c.i = c.y / koch->zoom + koch->i_move;
            if (koch->c.i < HEIGHT && koch->c.i > 0 && koch->c.r < WIDTH && koch->c.r > 0)
                ft_put_pixels(koch, koch->c.r, koch->c.i, koch->color_1);
            c.x += 1 /1.732;
            c.y--;
        }
    }
}