/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:52:50 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/25 19:06:00 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_koch(char *str1, char *str2)
{
	ft_strtolower(str1);
	if (str1 == NULL || ft_strlen(str1) != 4)
		return (1);
	while ((*str1 == *str2) && (*str1 != '\0'))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void    start_koch(t_fractal *fractal)
{
       /* fractal->coord[2] = NULL;
        fractal->coord[3] = NULL;
        fractal->coord[4] = NULL;*/
        fractal->r_move = 0;
        fractal->i_move = 0;
        fractal->zoom = 1;
        fractal->inter = 3;
        fractal->coord[0].x = WIDTH * 0.2 * fractal->zoom + fractal->r_move;
        fractal->coord[0].y = HEIGHT * 0.4 * fractal->zoom + fractal->i_move;
        fractal->coord[1].x = WIDTH * 0.8 * fractal->zoom + fractal->r_move;
        fractal->coord[1].y = HEIGHT * 0.4 * fractal->zoom + fractal->i_move;
        fractal->color_1 = WHITE;
        fractal->color_2 = RED;
        fractal->color_2 = GREEN;
        
}

void    init_koch(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        free(fractal->mlx_connection);
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
                                            WIDTH, HEIGHT, fractal->set);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
    }
    fractal->img = mlx_new_image(fractal->mlx_connection,
                                            WIDTH, HEIGHT);
    if (fractal->img == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
    }
    fractal->pixels_adr = mlx_get_data_addr(fractal->img,
                            &fractal->bits_per_pixel, &fractal->line_len, &fractal->endian);
    start_koch(fractal);
}