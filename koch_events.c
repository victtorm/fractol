/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:43:10 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/26 19:44:36 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void    koch_color(t_fractal *fractal)
{
    if (fractal->color_1 == BLUE)
        fractal->color_1 = GREEN;
    else if (fractal->color_1 == GREEN)
        fractal->color_1 = PURPLE;
    else if (fractal->color_1 == PURPLE)
        fractal->color_1 = BLUE;
}

int koch_close_window(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free (fractal->mlx_connection);
    exit(1);
}

int koch_mouse_imput(int button, int x, int y, t_fractal *fractal)
{
    mlx_mouse_get_pos(fractal->mlx_connection, fractal->mlx_window, &x, &y);
    mlx_destroy_image(fractal->mlx_connection, fractal->img);
    fractal->img = mlx_new_image(fractal->mlx_connection,
                                            WIDTH, HEIGHT);
    if (button ==  4)
    {
        fractal->r_move = (x / fractal->zoom + fractal->r_move) - (x / (fractal->zoom * 1.1));
        fractal->i_move = (y / fractal->zoom + fractal->i_move) - (y / (fractal->zoom * 1.1));
        fractal->zoom *= 1.1;
    }
    if (button ==  5)
    {   
        fractal->r_move = (x / fractal->zoom + fractal->r_move) - (x / (fractal->zoom * 0.9));
        fractal->i_move = (y / fractal->zoom + fractal->i_move) - (y / (fractal->zoom * 0.9));
        fractal->zoom *= 0.9;
    }
    koch_img(fractal);
    return (0);
}

int koch_key_imput(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        exit(1);
    }
    mlx_destroy_image(fractal->mlx_connection, fractal->img);
    fractal->img = mlx_new_image(fractal->mlx_connection,
                                            WIDTH, HEIGHT);
    if (keysym == XK_Up)
        fractal->i_move += 10 * fractal->zoom;
    if (keysym == XK_Down)
        fractal->i_move -= 10 * fractal->zoom;
    if (keysym == XK_Left)
        fractal->r_move -= 10 * fractal->zoom;
    if (keysym == XK_Right)
        fractal->r_move += 10 * fractal->zoom;
    if (keysym == XK_KP_Add)
        fractal->inter += 1;
    if (keysym == XK_KP_Subtract)
        fractal->inter -= 1;
    if (fractal->inter < 1 || fractal->inter > 20)
        fractal->inter = 1;
    if (keysym == XK_Shift_L)
        koch_color(fractal);
    koch_img(fractal);
    return (0);
}

void    koch_events(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, koch_key_imput, fractal);
    mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, koch_mouse_imput, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, koch_close_window, fractal);
}