/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:04:47 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/26 20:20:49 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_line(t_fractal *koch, t_koch a, t_koch b)
{
	t_fractal	temp;

	temp = *koch;
	if (koch->inter == 0)
	{
		if (a.y == b.y)
			draw_igual(&temp, a, b);
		if (a.y < b.y)
			draw_up(&temp, a, b);
		if (a.y > b.y)
			draw_down(&temp, a, b);
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
	return ;
}

void	update_coord(t_koch *m)
{
	m[2].x = ((m[1].x - m[0].x) / 3) + m[0].x;
	m[2].y = ((m[1].y - m[0].y) / 3) + m[0].y;
	m[3].x = (((m[1].x - m[0].x) / 3) * 2) + m[0].x;
	m[3].y = (((m[1].y - m[0].y) / 3) * 2) + m[0].y;
	if (m[0].y == m[1].y)
	{
		m[4].x = m[2].x + (m[3].x - m[2].x) * 0.5 - (m[3].y - m[2].y) * 0.866;
		m[4].y = m[2].y + (m[3].y - m[2].y) * 0.5 + (m[3].x - m[2].x) * 0.866;
	}
	else if (m[0].y < m[1].y)
	{
		m[4].x = m[0].x;
		m[4].y = m[3].y;
	}
	else if (m[0].y > m[1].y)
	{
		m[4].x = m[1].x;
		m[4].y = m[2].y;
	}
}

void	koch_img(t_fractal *koch)
{
	update_coord(koch->coord);
	draw_line (koch, koch->coord[0], koch->coord[1]);
	mlx_put_image_to_window(koch->mlx_connection,
		koch->mlx_window, koch->img, 0, 0);
}
