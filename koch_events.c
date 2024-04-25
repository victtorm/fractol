/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:43:10 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/25 14:26:49 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"


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
    if (button ==  4)
        zoom_in(fractal,x, y);
    if (button ==  5)
        zoom_out(fractal,x, y);
    fractal_img(fractal);
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
    if (keysym == XK_Up)
        fractal->i_move += (1 * fractal->zoom);
    if (keysym == XK_Down)
        fractal->i_move -= (1 * fractal->zoom);
    if (keysym == XK_Left)
        fractal->r_move -= (1 * fractal->zoom);
    if (keysym == XK_Right)
        fractal->r_move += (1 * fractal->zoom);
    if (keysym == XK_KP_Add)
        fractal->inter += 1;
    if (keysym == XK_KP_Subtract)
        fractal->inter -= 1;
    if (fractal->inter < 1 || fractal->inter > 10)
        fractal->inter = 1;
    if (keysym == XK_Shift_L)
        change_color(fractal);
    fractal_img(fractal);
    return (0);
}

void    koch_events(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, koch_key_imput, fractal);
    mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, koch_mouse_imput, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, koch_close_window, fractal);
}