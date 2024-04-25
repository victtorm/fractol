/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:04:47 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/25 19:13:17 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	koch_put_pixels(t_fractal *fractal, int x, int y, int color)
{
	int	move;

	move = 0;
	move = (y * fractal->line_len) + (x * (fractal->bits_per_pixel / 8));
	*(unsigned int*)(fractal->pixels_adr + move) = color;

}
mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, rand () % 0x1000000);

void    draw_igual(t_fractal *koch, t_koch c, t_koch d)
{
    while (c.x <= d.x)
    {
        koch_put_pixels(koch, c.x, d.y, koch->color_1);
        c.x++;
    }
}
void    draw_up(t_fractal *koch, t_koch c, t_koch d)
{
    while (c.x <= d.x)
    {
        koch_put_pixels(koch, c.x, c.y, koch->color_2);
        c.x++;
        c.y++;
    }
}

void    draw_down(t_fractal *koch, t_koch c, t_koch d)
{
    while (c.x <= d.x)
    {
        koch_put_pixels(koch, c.x, c.y, koch->color_3);
        c.x++;
        c.y--;
    }
}

void    draw_line(t_fractal *koch, t_koch a, t_koch b)
{
    t_koch c;
    t_koch d;
    t_fractal temp;

    c = a;
    d = b;
    temp = *koch;
    if (koch->inter == 0)
    {
        if (a.y == b.y)
            draw_igual(&temp, c, d);
        if (a.y < b.y)
            draw_up(&temp, c, d);
        if (a.y > b.y)
            draw_down(&temp, c, d);
    }
    else
    {
        temp.coord[0] = a;
        temp.coord[1] = b;
        temp.inter--;
        update_coord(temp.coord);
        draw_line(&temp, temp.coord[0], temp.coord[2]);
        draw_line(&temp, temp.coord[2], temp.coord[4]);
        draw_line(&temp, temp.coord[4], temp.coord[3]);
        draw_line(&temp, temp.coord[3], temp.coord[1]);
    }
    return;
}

void update_coord(t_koch *m)
{
    if (m[0].y == m[1].y)
	{
        m[2].x = ((m[1].x - m[0].x) / 3) + m[0].x;
        m[2].y = ((m[1].y - m[0].y) / 3) + m[0].y;
	    m[3].x = (((m[1].x - m[0].x) / 3) * 2) + m[0].x;
        m[3].y = ((m[1].y - m[0].y) / 3) * 2 + m[0].y;
		m[4].x = m[2].x + (m[3].x - m[2].x) * 0.5 - (m[3].y - m[2].y) * 0.866;
    	m[4].y = m[2].y + (m[3].y - m[2].y) * 0.5 + (m[3].x - m[2].x) * 0.866;
    }
}

void    koch_img(t_fractal *koch)
{
    draw_line (koch, koch->coord[0], koch->coord[1]);
    mlx_put_image_to_window(koch->mlx_connection,
		koch->mlx_window, koch->img, 0, 0);
}